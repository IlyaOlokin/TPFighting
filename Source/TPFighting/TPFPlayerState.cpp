// Fill out your copyright notice in the Description page of Project Settings.


#include "TPFPlayerState.h"

#include "BaseAttributeSet.h"
#include "TPFAbilitySystemComponent.h"


ATPFPlayerState::ATPFPlayerState()
{
	NetUpdateFrequency = 60.0f;
	
	AbilitySystemComponent = CreateDefaultSubobject<UTPFAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	
	AttributeSet = CreateDefaultSubobject<UBaseAttributeSet>("AttributeSet");
}

UBaseAttributeSet* ATPFPlayerState::GetAttributeSet() const
{
	return AttributeSet;
}
