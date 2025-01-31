// Fill out your copyright notice in the Description page of Project Settings.


#include "AttributesWidget.h"
#include "TPFighting/BaseAttributeSet.h"

void UAttributesWidget::BindToAttributes(UAbilitySystemComponent* ASC, const UBaseAttributeSet* AttributeSet)
{
	try
	{
		HealthPercent = NUMERIC_VALUE(AttributeSet, Health) / NUMERIC_VALUE(AttributeSet, MaxHealth);
		StancePercent = NUMERIC_VALUE(AttributeSet, Stance) / NUMERIC_VALUE(AttributeSet, MaxStance);
	}
	catch (...)
	{
	}
	

	ASC->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetHealthAttribute()).AddLambda(
		[this, AttributeSet](const FOnAttributeChangeData& Data)->void
		{
			HealthPercent = Data.NewValue / NUMERIC_VALUE(AttributeSet, MaxHealth);
		});

	ASC->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetStanceAttribute()).AddLambda(
		[this, AttributeSet](const FOnAttributeChangeData& Data)->void
		{
			StancePercent = Data.NewValue / NUMERIC_VALUE(AttributeSet, MaxStance);
		});
	
}
