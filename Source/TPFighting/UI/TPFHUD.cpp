// Fill out your copyright notice in the Description page of Project Settings.


#include "TPFHUD.h"
#include "AttributesWidget.h"

class ATPFPlayerState;

void ATPFHUD::Init(const ATPFPlayerState* TPFPlayerState)
{
	AttributesWidget = CreateWidget<UAttributesWidget>(GetOwningPlayerController(), AttributeWidgetClass);
	AttributesWidget->BindToAttributes(TPFPlayerState->GetAbilitySystemComponent(), TPFPlayerState->GetAttributeSet());
	AttributesWidget->AddToViewport();
}
