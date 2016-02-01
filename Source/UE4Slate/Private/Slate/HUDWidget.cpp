// Fill out your copyright notice in the Description page of Project Settings.

#include "UE4Slate.h"
#include "HUDWidget.h"

#define LOCTEXT_NAMESPACE "Namespace"

//BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SHUDWidget::Construct(const FArguments& InArgs)
{
	//HUDBrush = MakeShareable(new FHUDBrush("TextureName", FVector2D(1920, 1080)));
	//SlateHUD = InArgs._SlateHUD;

	ChildSlot
	[
		SNew(SOverlay)
		+ SOverlay::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		[
			//SNew(SImage)
			//.Image(HUDBrush.Get())

			SNew(STextBlock)
			.ColorAndOpacity(FLinearColor::White)
			.ShadowColorAndOpacity(FLinearColor::Black)
			.ShadowOffset(FIntPoint(-1, 1))
			.Text(FText::FromString("Hello World")/*LOCTEXT("KEY", "TEXT")*/)
		]
	];
}
//END_SLATE_FUNCTION_BUILD_OPTIMIZATION

#undef LOCTEXT_NAMESPACE