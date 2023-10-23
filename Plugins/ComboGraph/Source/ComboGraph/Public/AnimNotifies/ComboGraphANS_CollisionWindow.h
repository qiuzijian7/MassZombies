// Copyright 2022 Mickael Daniel. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "ComboGraphANS_CollisionWindow.generated.h"

class UComboGraphCollisionComponent;

/** Anim notifies that start and end traces on Owner's ComboGraph CollisionComponent. */
UCLASS(NotBlueprintable, meta = (DisplayName = "Combo Graph: Collision Window"))
class COMBOGRAPH_API UComboGraphANS_CollisionWindow : public UAnimNotifyState
{
	GENERATED_BODY()

public:
	virtual void NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration) override;
	virtual void NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;

protected:

	/** Returns owner collision component through component search, if it has any */
	UComboGraphCollisionComponent* GetCollisionComponent(AActor* OwnerActor) const;

	void ActivateCollision(USkeletalMeshComponent* MeshComp, bool bShouldStart);
};
