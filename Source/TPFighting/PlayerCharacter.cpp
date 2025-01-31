// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "TPFAbilitySystemComponent.h"
#include "TPFPlayerState.h"
#include "UI/TPFHUD.h"

void APlayerCharacter::InitAbilitySystem()
{
	/*ATPFPlayerState* TPFPlayerState = GetPlayerState<ATPFPlayerState>();
	check(TPFPlayerState);
	AbilitySystemComponent = CastChecked<UTPFAbilitySystemComponent>(TPFPlayerState->GetAbilitySystemComponent());
	AbilitySystemComponent->InitAbilityActorInfo(TPFPlayerState, this);
	AttributeSet = TPFPlayerState->GetAttributeSet();*/
}

void APlayerCharacter::InitHUD()
{
	Super::InitHUD();
	
	/*if (const APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if (ATPFHUD* TPFHUD =  Cast<ATPFHUD>(PlayerController->GetHUD()))
		{
			ATPFPlayerState* TPFPlayerState = Cast<ATPFPlayerState>(GetPlayerState());
			TPFHUD->Init(TPFPlayerState);
		}
	}*/
}
