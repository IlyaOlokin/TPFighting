// Fill out your copyright notice in the Description page of Project Settings.


#include "TPFPlayerState.h"
#include "TPFAbilitySystemComponent.h"


// Sets default values
ATPFPlayerState::ATPFPlayerState()
{
	NetUpdateFrequency = 100.0f;
	
	AbilitySystemComponent = CreateDefaultSubobject<UTPFAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
}
