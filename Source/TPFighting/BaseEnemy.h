// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "UI/AttributesWidget.h"
#include "BaseEnemy.generated.h"

UCLASS()
class TPFIGHTING_API ABaseEnemy : public ABaseCharacter
{
	GENERATED_BODY()

public:
	ABaseEnemy();

protected:
	virtual void BeginPlay() override;
	virtual void InitHUD() override;
	
	
};
