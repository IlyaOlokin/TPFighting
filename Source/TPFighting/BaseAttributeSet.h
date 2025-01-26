// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "BaseAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName)\
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName)\
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName)\
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName)\
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

#define NUMERIC_VALUE(AttributeSetName, PropertyName) \
	AttributeSetName->Get##PropertyName##Attribute().GetNumericValue(AttributeSetName)


UCLASS()
class TPFIGHTING_API UBaseAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UBaseAttributeSet();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
	
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "Attribute")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Health);
	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = "Attribute")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, MaxHealth);
	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Stance, Category = "Attribute")
	FGameplayAttributeData Stance;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Stance);
	UFUNCTION()
	void OnRep_Stance(const FGameplayAttributeData& OldStance) const;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxStance, Category = "Attribute")
	FGameplayAttributeData MaxStance;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, MaxStance);
	UFUNCTION()
	void OnRep_MaxStance(const FGameplayAttributeData& OldMaxStance) const;

	
};
