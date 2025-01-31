// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "Abilities/GameplayAbility.h"
#include "UI/AttributesWidget.h"
#include "BaseCharacter.generated.h"

class UBaseAttributeSet;
class UTPFAbilitySystemComponent;

UENUM(BlueprintType)
enum ECharacterType
{
	NPC,
	Player
};

UCLASS()
class TPFIGHTING_API ABaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()
	
private:
	void InitAbilitySystem();
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character", meta = (AllowPrivateAccess = " true"))
	TEnumAsByte<ECharacterType> CharacterType;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GAS", meta = (AllowPrivateAccess = " true"))
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	UBaseAttributeSet* AttributeSet;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category= "GAS")
	TArray<TSubclassOf<UGameplayAbility>> DefaultAbilities;

	UPROPERTY(EditDefaultsOnly, Category= "GAS")
	TSubclassOf<UGameplayEffect> DefaultAttributeEffect;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Team")
	int Team;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UAttributesWidget> AttributeWidgetClass;
	
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UAttributesWidget> AttributesWidget;

	virtual void BeginPlay() override;
	
	void GiveDefaultAbilities();
	void InitDefaultAttributes() const;
	
	UFUNCTION(BlueprintCallable)
	virtual void InitHUD();
	
public:
	
	ABaseCharacter();

	UFUNCTION(BlueprintCallable)
	virtual UBaseAttributeSet* GetAttributeSet() const;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override
	{
		return AbilitySystemComponent;
	}

	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;
	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
