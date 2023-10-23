// Copyright 2022 Mickael Daniel. All Rights Reserved.


#include "AnimNotifies/ComboGraphANS_CollisionWindow.h"

#include "Components/ComboGraphCollisionComponent.h"
#include "Utils/ComboGraphUtils.h"

void UComboGraphANS_CollisionWindow::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const float TotalDuration)
{
	ActivateCollision(MeshComp, true);
	Super::NotifyBegin(MeshComp, Animation, TotalDuration);
}

void UComboGraphANS_CollisionWindow::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	ActivateCollision(MeshComp, false);
	Super::NotifyEnd(MeshComp, Animation);
}

// ReSharper disable once CppMemberFunctionMayBeConst
void UComboGraphANS_CollisionWindow::ActivateCollision(USkeletalMeshComponent* MeshComp, const bool bShouldStart)
{
	if (MeshComp)
	{
		AActor* Owner = MeshComp->GetOwner();
		if (!IsValid(Owner))
		{
			return;
		}

		// Only relevant for authority (Fix #8)
		if (!Owner->HasAuthority())
		{
			return;
		}

		// Avoid doing anything for animation preview actor (notifiers are triggered in persona preview viewport)
		if (!FComboGraphUtils::IsAnimationPreviewActor(Owner))
		{

			if (UComboGraphCollisionComponent* CollisionComponent = GetCollisionComponent(Owner))
			{
				if (bShouldStart)
				{
					CollisionComponent->StartTrace();

				}
				else
				{
					CollisionComponent->EndTrace();
				}
			}
		}
	}
}


UComboGraphCollisionComponent* UComboGraphANS_CollisionWindow::GetCollisionComponent(AActor* OwnerActor) const
{
	if (!OwnerActor)
	{
		return nullptr;
	}

	return OwnerActor->FindComponentByClass<UComboGraphCollisionComponent>();
}

