// Fill out your copyright notice in the Description page of Project Settings.


#include "TPFAbilitySystemComponent.h"

UTPFAbilitySystemComponent::UTPFAbilitySystemComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	SetIsReplicated(true);
}

void UTPFAbilitySystemComponent::BeginPlay()
{
	Super::BeginPlay();
}
