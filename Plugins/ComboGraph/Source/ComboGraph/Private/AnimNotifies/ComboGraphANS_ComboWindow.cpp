// Copyright 2022 Mickael Daniel. All Rights Reserved.


#include "AnimNotifies/ComboGraphANS_ComboWindow.h"

#include "Abilities/ComboGraphNativeTags.h"
#include "Abilities/GameplayAbilityTypes.h"
#include "Utils/ComboGraphBlueprintLibrary.h"
#include "Utils/ComboGraphUtils.h"

void UComboGraphANS_ComboWindow::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const float TotalDuration)
{
	if (MeshComp)
	{
		AActor* Owner = MeshComp->GetOwner();

		// Avoid sending event for animation preview actor (notifiers are triggered in persona preview viewport)
		if (Owner && !FComboGraphUtils::IsAnimationPreviewActor(Owner))
		{
			UComboGraphBlueprintLibrary::SendGameplayEventToActor(Owner, FComboGraphNativeTags::Get().ComboBegin, FGameplayEventData());
		}
	}

	Super::NotifyBegin(MeshComp, Animation, TotalDuration);
}

void UComboGraphANS_ComboWindow::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	if (MeshComp)
	{
		AActor* Owner = MeshComp->GetOwner();
		// Avoid sending event for animation preview actor (notifiers are triggered in persona preview viewport)
		if (Owner && !FComboGraphUtils::IsAnimationPreviewActor(Owner))
		{
			UComboGraphBlueprintLibrary::SendGameplayEventToActor(Owner, FComboGraphNativeTags::Get().ComboEnd, FGameplayEventData());
		}
	}

	Super::NotifyEnd(MeshComp, Animation);
}
