// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "UObject/Object.h"
#include "PlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class TPFIGHTING_API APlayerCharacter : public ABaseCharacter
{
	GENERATED_BODY()

public:
	
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

private:
	void InitAbilitySystem();
};
