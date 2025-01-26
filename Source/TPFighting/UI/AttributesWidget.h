// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TPFighting/TPFPlayerState.h"
#include "Blueprint/UserWidget.h"
#include "AttributesWidget.generated.h"

/**
 * 
 */
UCLASS()
class TPFIGHTING_API UAttributesWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void BindToAttributes(UAbilitySystemComponent* ASC, const UBaseAttributeSet* AttributeSet);

protected:
	UPROPERTY(BlueprintReadOnly)
	float HealthPercent;
	
	UPROPERTY(BlueprintReadOnly)
	float StancePercent;
};
