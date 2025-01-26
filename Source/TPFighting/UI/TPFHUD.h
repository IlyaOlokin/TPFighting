// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributesWidget.h"
#include "GameFramework/HUD.h"
#include "TPFighting/TPFPlayerState.h"
#include "TPFHUD.generated.h"

/**
 * 
 */
UCLASS()
class TPFIGHTING_API ATPFHUD : public AHUD
{
	GENERATED_BODY()

public:
	void Init(const ATPFPlayerState* TPFPlayerState);

protected:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UAttributesWidget> AttributeWidgetClass;

private:
	UPROPERTY()
	TObjectPtr<UAttributesWidget> AttributesWidget;
};
