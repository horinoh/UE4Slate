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
			//!< この場で SHUDWidget を作成して、メンバ変数 HUDWidget へアサイン
			SAssignNew(HUDWidget, SHUDWidget);
			//!< ビューポートへ追加
			GEngine->GameViewport->AddViewportWidgetContent(SNew(SWeakWidget).PossiblyNullContent(HUDWidget.ToSharedRef()));
		}
	}
}
