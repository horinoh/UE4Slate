// Fill out your copyright notice in the Description page of Project Settings.

#include "UE4Slate.h"
#include "HUDWidget.h"

#include "HUDStyle.h"

#define LOCTEXT_NAMESPACE "Namespace"

//BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SHUDWidget::Construct(const FArguments& InArgs)
{
	//SlateHUD = InArgs._SlateHUD;

	/**
	�v���p�e�B���ŃX�^�C�����擾���ăZ�b�g����

	.TextStyle(YYYStyle::Get(), "XXX")
	.BorderImage(YYYStyle::Get().GetBrush("XXX"))
	.ButtonStyle(&YYYStyle::Get().GetWidgetStyle<FButtonStyle>("XXX"))

	FCoreStyle �̃X�^�C����u���V�擾��
	.Style(FCoreStyle::Get(), "Checkbox")
	.Style(FCoreStyle::Get(), "ToggleButtonCheckbox")
	.BorderImage(FCoreStyle::Get().GetBrush("NoBorder"))
	.Image(FCoreStyle::Get().GetDefaultBrush())
	*/

	ChildSlot
	[
		SNew(SOverlay)
		+ SOverlay::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		[
			SNew(SImage)
			//.Image(FCoreStyle::Get().GetDefaultBrush())
			//.Image(FCoreStyle::Get().GetBrush("TrashCan"))
			//.Image(FHUDStyle::Get().GetBrush("Crosshair"))
			.Image(FHUDStyle::Get().GetBrush("UE4Icon"))

			//SNew(SBorder)
			//.BorderImage(FCoreStyle::Get().GetBrush("NoBorder"))

			//SNew(STextBlock)
			//.ColorAndOpacity(FLinearColor::White)
			//.ShadowColorAndOpacity(FLinearColor::Black)
			//.ShadowOffset(FIntPoint(-1, 1))
			//.Text(FText::FromString("Hello World")/*LOCTEXT("KEY", "TEXT")*/)

			//SNew(SButton)
			//.Text(FText::FromString("Button"))
			//.OnClicked(this, &SHUDWidget::OnClicked)
		]
	];
}

//FReply SHUDWidget::OnClicked()
//{
//	UE_LOG(LogSlate, Log, TEXT("OnClicked"));
//	return FReply::Handled();
//}

//END_SLATE_FUNCTION_BUILD_OPTIMIZATION

#undef LOCTEXT_NAMESPACE