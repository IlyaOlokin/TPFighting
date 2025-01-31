// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"
#include "BaseAttributeSet.h"
#include "TPFAbilitySystemComponent.h"
#include "UI/AttributesWidget.h"
#include "TPFPlayerState.h"
#include "UI/TPFHUD.h"

ABaseCharacter::ABaseCharacter()
{
 	PrimaryActorTick.bCanEverTick = true;
	
	if (CharacterType == NPC)
	{
		InitAbilitySystem();
	}
}

UBaseAttributeSet* ABaseCharacter::GetAttributeSet() const
{
	return AttributeSet;
}

void ABaseCharacter::InitAbilitySystem()
{
	switch (CharacterType)
	{
		case Player:
			{
				ATPFPlayerState* TPFPlayerState = GetPlayerState<ATPFPlayerState>();
				check(TPFPlayerState);
				AbilitySystemComponent = CastChecked<UTPFAbilitySystemComponent>(TPFPlayerState->GetAbilitySystemComponent());
				AbilitySystemComponent->InitAbilityActorInfo(TPFPlayerState, this);
				AttributeSet = TPFPlayerState->GetAttributeSet();
				break;
			}
		case NPC:
			{
				AbilitySystemComponent = CreateDefaultSubobject<UTPFAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
				AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
				AttributeSet = CreateDefaultSubobject<UBaseAttributeSet>("AttributeSet");
				break;
			}
		default:
			break;
	}
}



void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (CharacterType == NPC)
	{
		AbilitySystemComponent->InitAbilityActorInfo(this, this);
		GiveDefaultAbilities();
		InitDefaultAttributes();
		InitHUD();
	}
}

void ABaseCharacter::GiveDefaultAbilities()
{
	check(AbilitySystemComponent);
	if (!HasAuthority()) return;
	for (int i = 0; i < DefaultAbilities.Num(); i++)
	{
		const FGameplayAbilitySpec AbilitySpec(DefaultAbilities[i], 1, i);
		AbilitySystemComponent->GiveAbility(AbilitySpec);
	}
}

void ABaseCharacter::InitDefaultAttributes() const
{
	if (!AbilitySystemComponent || !DefaultAttributeEffect) return;
	
	FGameplayEffectContextHandle EffectContextHandle = AbilitySystemComponent->MakeEffectContext();
	EffectContextHandle.AddSourceObject(this);
	const FGameplayEffectSpecHandle SpecHandle = AbilitySystemComponent->MakeOutgoingSpec(DefaultAttributeEffect, 1, EffectContextHandle);

	if (SpecHandle.IsValid())
	{
		AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());
	}
}

void ABaseCharacter::InitHUD()
{
	switch (CharacterType)
	{
		case Player:
			if (const APlayerController* PlayerController = Cast<APlayerController>(GetController()))
			{
				if (ATPFHUD* TPFHUD =  Cast<ATPFHUD>(PlayerController->GetHUD()))
				{
					ATPFPlayerState* TPFPlayerState = Cast<ATPFPlayerState>(GetPlayerState());
					TPFHUD->Init(TPFPlayerState);
				}
			}
			break;
		case NPC:
			AttributesWidget = CreateWidget<UAttributesWidget>(GetWorld()->GetFirstPlayerController(),AttributeWidgetClass);
			AttributesWidget->BindToAttributes(GetAbilitySystemComponent(), GetAttributeSet());
			break;
		default: ;
	}
}

void ABaseCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	if (CharacterType == Player)
	{
		InitAbilitySystem();
		GiveDefaultAbilities();
		InitDefaultAttributes();
		InitHUD();
	}
}

void ABaseCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	if (CharacterType == Player)
	{
		InitAbilitySystem();
		InitDefaultAttributes();
		InitHUD();
	}
}

void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

