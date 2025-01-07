// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "TPFAbilitySystemComponent.h"
#include "TPFPlayerState.h"

void APlayerCharacter::InitAbilitySystem()
{
	ATPFPlayerState* TPFPlayerState = GetPlayerState<ATPFPlayerState>();
	check(TPFPlayerState);
	AbilitySystemComponent = CastChecked<UTPFAbilitySystemComponent>(TPFPlayerState->GetAbilitySystemComponent());
	AbilitySystemComponent->InitAbilityActorInfo(TPFPlayerState, this);
}

void APlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	InitAbilitySystem();
	GiveDefaultAbilities();
}

void APlayerCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	InitAbilitySystem();
}
