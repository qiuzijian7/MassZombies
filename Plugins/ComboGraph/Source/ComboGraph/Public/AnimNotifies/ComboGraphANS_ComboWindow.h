// Copyright 2022 Mickael Daniel. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "ComboGraphANS_ComboWindow.generated.h"

/** Anim notifies that sends relevant Gameplay Events on begin / end */
UCLASS(NotBlueprintable, meta = (DisplayName = "Combo Graph: Combo Window"))
class COMBOGRAPH_API UComboGraphANS_ComboWindow : public UAnimNotifyState
{
	GENERATED_BODY()

public:
	virtual void NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration) override;
	virtual void NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;
};
