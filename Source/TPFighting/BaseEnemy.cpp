// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseEnemy.h"

#include "BaseAttributeSet.h"
#include "TPFAbilitySystemComponent.h"
#include "GameFramework/GameSession.h"
#include "UI/AttributesWidget.h"


ABaseEnemy::ABaseEnemy()
{
	/*AbilitySystemComponent = CreateDefaultSubobject<UTPFAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
	AttributeSet = CreateDefaultSubobject<UBaseAttributeSet>("AttributeSet");*/
}

void ABaseEnemy::BeginPlay()
{
	Super::BeginPlay();
	
	/*AbilitySystemComponent->InitAbilityActorInfo(this, this);
	GiveDefaultAbilities();
	InitDefaultAttributes();
	InitHUD();*/
}

void ABaseEnemy::InitHUD()
{
	Super::InitHUD();

	/*AttributesWidget = CreateWidget<UAttributesWidget>(GetWorld()->GetFirstPlayerController(),AttributeWidgetClass);
	AttributesWidget->BindToAttributes(GetAbilitySystemComponent(), GetAttributeSet());*/
}