// Fill out your copyright notice in the Description page of Project Settings.

#include "UE4Slate.h"
#include "SlateHUD.h"

#include "Slate/HUDWidget.h"

void ASlateHUD::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	if (nullptr != GEngine && GEngine->IsValidLowLevel())
	{
		const auto GVC = GEngine->GameViewport;
		if (nullptr != GVC)
		{
			//!< Create SHUDWidget and assign to HUDWidget
			SAssignNew(HUDWidget, SHUDWidget);
			//!< Add to viewport
			GEngine->GameViewport->AddViewportWidgetContent(SNew(SWeakWidget).PossiblyNullContent(HUDWidget.ToSharedRef()));
		}
	}
}
