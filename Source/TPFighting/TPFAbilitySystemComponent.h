// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "TPFAbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class TPFIGHTING_API UTPFAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	UTPFAbilitySystemComponent();

protected:
	virtual void BeginPlay() override;
};
