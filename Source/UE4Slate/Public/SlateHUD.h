// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SWeakWidget.h"

#include "GameFramework/HUD.h"
#include "SlateHUD.generated.h"

/**
 * 
 */
UCLASS()
class UE4SLATE_API ASlateHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	virtual void PostInitializeComponents() override;

protected:
	TSharedPtr<class SHUDWidget> HUDWidget;
	//TSharedPtr<class SWeakWidget> HUDWidgetContainer;
};
