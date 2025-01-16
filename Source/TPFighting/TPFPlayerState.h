// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemInterface.h"
#include "TPFPlayerState.generated.h"

class UTPFAbilitySystemComponent;
class UBaseAttributeSet;

UCLASS()
class TPFIGHTING_API ATPFPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ATPFPlayerState();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override
	{
		return AbilitySystemComponent;
	}
	
	virtual auto GetAttributeSet() const -> UBaseAttributeSet*;

protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GAS", meta = (AllowPrivateAccess = " true"))
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	
	UPROPERTY(Transient)
	UBaseAttributeSet* AttributeSet;
};
