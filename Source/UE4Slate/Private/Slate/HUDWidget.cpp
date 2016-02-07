// Fill out your copyright notice in the Description page of Project Settings.

#include "UE4Slate.h"
#include "HUDWidget.h"

#include "HUDStyle.h"
#include "HUDSlateWidgetStyleContainer.h"

#define LOCTEXT_NAMESPACE "Namespace"

//BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SHUDWidget::Construct(const FArguments& InArgs)
{
	//HUDBrush = MakeShareable(new FHUDBrush("TextureName", FVector2D(1920, 1080)));
	//SlateHUD = InArgs._SlateHUD;

	/**
	プロパティ名でスタイルを取得してセットする

	.TextStyle(YYYStyle::Get(), "XXX")
	.BorderImage(YYYStyle::Get().GetBrush("XXX"))
	.ButtonStyle(&YYYStyle::Get().GetWidgetStyle<FButtonStyle>("XXX"))
	
	.Image(&FHUDStyle::Get().GetWidgetStyle<FHUDWidgetStyle>("PROPNAME").XXXBrush);
	*/

	/**
	FCoreStyle のサンプル

	.Style(FCoreStyle::Get(), "Checkbox")
	.Style(FCoreStyle::Get(), "ToggleButtonCheckbox")
	.BorderImage(FCoreStyle::Get().GetBrush("NoBorder"))
	.Image(FCoreStyle::Get().GetDefaultBrush())
	*/

	//!< 自前のスタイルは "HUDWidgetStyle" という名前で登録したので、その名前で取得する
	auto HUDWidgetStyle = FHUDStyle::Get().GetWidgetStyle<FHUDWidgetStyle>("HUDWidgetStyle");
	HUDWidgetStyle.XXXBrush;

	ChildSlot
	[
		SNew(SOverlay)
		+ SOverlay::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		[
			SNew(SImage)
			.Image(FCoreStyle::Get().GetDefaultBrush())
			//.Image(HUDBrush.Get())
			
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