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
	プロパティ名でスタイルを取得してセットする

	.TextStyle(YYYStyle::Get(), "XXX")
	.BorderImage(YYYStyle::Get().GetBrush("XXX"))
	.ButtonStyle(&YYYStyle::Get().GetWidgetStyle<FButtonStyle>("XXX"))

	FCoreStyle のスタイルやブラシ取得例 (FCoreStyle::Create() で定義されている)
	.Style(FCoreStyle::Get(), "Checkbox")
	.Style(FCoreStyle::Get(), "ToggleButtonCheckbox")
	.BorderImage(FCoreStyle::Get().GetBrush("NoBorder"))
	.Image(FCoreStyle::Get().GetDefaultBrush())
	*/

	ChildSlot
	[
#if 0
		SNew(SOverlay)
		+ SOverlay::Slot()
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		[
		]
#endif
		//!< スクロールボックス
		SNew(SScrollBox)		
		+SScrollBox::Slot()
		.Padding(10, 5)
		[
			//!< 水平ボックス
			SNew(SHorizontalBox)
			+SHorizontalBox::Slot()
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			[
				SNew(SImage)
				.Image(FHUDStyle::Get().GetBrush("UE4Icon"))
				.ToolTipText(LOCTEXT("SImage_Key", "SImage_Text"))
			]
			+ SHorizontalBox::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SNew(STextBlock)
				.Text(LOCTEXT("STextBlock_Key", "STextBlock_Text"))
				//.Font(FEditorStyle::GetFontStyle(FName("ToolBarButton.LabelFont")))
				.ToolTipText(LOCTEXT("STextBlock_Key", "STextBlock_Text"))
			]
			+ SHorizontalBox::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SNew(SButton)
				.Text(LOCTEXT("SButton_Key", "SButton_Text"))
				.ToolTipText(LOCTEXT("SButton_Key", "SButton_Text"))
				.OnClicked(this, &SHUDWidget::OnButtonClicked)
			]
			+ SHorizontalBox::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SNew(SCheckBox)
				.IsChecked(this, &SHUDWidget::IsCheckBoxChecked)
				.OnCheckStateChanged(this, &SHUDWidget::OnCheckBoxStateChanged)
				.ToolTipText(LOCTEXT("SCheckBox_Key", "SCheckBox_Text"))
				[
					SNew(STextBlock)
					.Text(LOCTEXT("SCheckBox_Key", "SCheckBox_Text"))
				]
			]
		]

		+ SScrollBox::Slot()
		.Padding(10, 5)
		[
			//!< ボーダー
			SNew(SBorder)
			.BorderImage(FCoreStyle::Get().GetBrush("ScrollBorder"))
		]

		+ SScrollBox::Slot()
		.Padding(10, 5)
		[
			//!< 垂直ボックス
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			[
				SNew(SImage)
				.Image(FHUDStyle::Get().GetBrush("UE4Icon"))
				.ToolTipText(LOCTEXT("SImage_Key", "SImage_Text"))
			]
			+ SVerticalBox::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SNew(STextBlock)
				.Text(LOCTEXT("STextBlock_Key", "STextBlock_Text"))
				.ToolTipText(LOCTEXT("STextBlock_Key", "STextBlock_Text"))
			]
			+ SVerticalBox::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SNew(SButton)
				.Text(LOCTEXT("SButton_Key", "SButton_Text"))
				.ToolTipText(LOCTEXT("SButton_Key", "SButton_Text"))
				.OnClicked(this, &SHUDWidget::OnButtonClicked)
			]
			+ SVerticalBox::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SNew(SCheckBox)
				.IsChecked(this, &SHUDWidget::IsCheckBoxChecked)
				.OnCheckStateChanged(this, &SHUDWidget::OnCheckBoxStateChanged)
				.ToolTipText(LOCTEXT("SCheckBox_Key", "SCheckBox_Text"))
				[
					SNew(STextBlock)
					.Text(LOCTEXT("SCheckBox_Key", "SCheckBox_Text"))
				]
			]
		]

		+ SScrollBox::Slot()
		.Padding(10, 5)
		[
			//!< ボーダー
			SNew(SBorder)
			.BorderImage(FCoreStyle::Get().GetBrush("ScrollBorder"))
		]

		+ SScrollBox::Slot()
		.Padding(10, 5)
		[
			//!< グリッドパネル
			SNew(SUniformGridPanel)
			.SlotPadding(FMargin(5.0f))
			+ SUniformGridPanel::Slot(0, 0)
			.HAlign(HAlign_Right)
			.VAlign(VAlign_Top)
			[
				SNew(SImage)
				.Image(FHUDStyle::Get().GetBrush("UE4Icon"))
				.ToolTipText(LOCTEXT("SImage_Key", "SImage_Text"))
			]
			+ SUniformGridPanel::Slot(0, 1)
			.HAlign(HAlign_Right)
			.VAlign(VAlign_Center)
			[
				SNew(SImage)
				.Image(FHUDStyle::Get().GetBrush("UE4Icon"))
				.ToolTipText(LOCTEXT("SImage_Key", "SImage_Text"))
			]
			+ SUniformGridPanel::Slot(0, 2)
			.HAlign(HAlign_Right)
			.VAlign(VAlign_Bottom)
			[
				SNew(SImage)
				.Image(FHUDStyle::Get().GetBrush("UE4Icon"))
				.ToolTipText(LOCTEXT("SImage_Key", "SImage_Text"))
			]
			+ SUniformGridPanel::Slot(1, 0)
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Top)
			[
				SNew(SImage)
				.Image(FHUDStyle::Get().GetBrush("UE4Icon"))
				.ToolTipText(LOCTEXT("SImage_Key", "SImage_Text"))
			]
			+ SUniformGridPanel::Slot(1, 1)
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			[
				SNew(SImage)
				.Image(FHUDStyle::Get().GetBrush("UE4Icon"))
				.ToolTipText(LOCTEXT("SImage_Key", "SImage_Text"))
			]
			+ SUniformGridPanel::Slot(1, 2)
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Bottom)
			[
				SNew(SImage)
				.Image(FHUDStyle::Get().GetBrush("UE4Icon"))
				.ToolTipText(LOCTEXT("SImage_Key", "SImage_Text"))
			]
			+ SUniformGridPanel::Slot(2, 0)
			.HAlign(HAlign_Left)
			.VAlign(VAlign_Top)
			[
				SNew(SImage)
				.Image(FHUDStyle::Get().GetBrush("UE4Icon"))
				.ToolTipText(LOCTEXT("SImage_Key", "SImage_Text"))
			]
			+ SUniformGridPanel::Slot(2, 1)
			.HAlign(HAlign_Left)
			.VAlign(VAlign_Center)
			[
				SNew(SImage)
				.Image(FHUDStyle::Get().GetBrush("UE4Icon"))
				.ToolTipText(LOCTEXT("SImage_Key", "SImage_Text"))
			]
			+ SUniformGridPanel::Slot(2, 2)
			.HAlign(HAlign_Left)
			.VAlign(VAlign_Bottom)
			[
				SNew(SImage)
				.Image(FHUDStyle::Get().GetBrush("UE4Icon"))
				.ToolTipText(LOCTEXT("SImage_Key", "SImage_Text"))
			]
		]

		+ SScrollBox::Slot()
		.Padding(10, 5)
		[
			//!< ボーダー
			SNew(SBorder)
			.BorderImage(FCoreStyle::Get().GetBrush("ScrollBorder"))
		]

		+ SScrollBox::Slot()
		.Padding(10, 5)
		[
			//!< ラップボックス
			SNew(SWrapBox)
			.PreferredWidth(300.0f)
			+ SWrapBox::Slot()
			.Padding(20)
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SNew(SImage)
				.Image(FHUDStyle::Get().GetBrush("UE4Icon"))
				.ToolTipText(LOCTEXT("SImage_Key", "SImage_Text"))
			]
			+ SWrapBox::Slot()
			.Padding(20)
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SNew(SImage)
				.Image(FHUDStyle::Get().GetBrush("UE4Icon"))
				.ToolTipText(LOCTEXT("SImage_Key", "SImage_Text"))
			]
			+ SWrapBox::Slot()
			.Padding(20)
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SNew(SImage)
				.Image(FHUDStyle::Get().GetBrush("UE4Icon"))
				.ToolTipText(LOCTEXT("SImage_Key", "SImage_Text"))
			]
			+ SWrapBox::Slot()
			.Padding(20)
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SNew(SImage)
				.Image(FHUDStyle::Get().GetBrush("UE4Icon"))
				.ToolTipText(LOCTEXT("SImage_Key", "SImage_Text"))
			]
		]

		+ SScrollBox::Slot()
		.Padding(10, 5)
		[
			//!< ボーダー
			SNew(SBorder)
			.BorderImage(FCoreStyle::Get().GetBrush("ScrollBorder"))
		]

		+ SScrollBox::Slot()
		.Padding(10, 5)
		[
			//!< ボーダー
			SNew(SBorder)
			.BorderImage(FCoreStyle::Get().GetBrush("ScrollBorder"))
		]
	];
}

FReply SHUDWidget::OnButtonClicked()
{
	UE_LOG(LogSlate, Log, TEXT("OnButtonClicked"));
	if (nullptr != GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Green, TEXT("OnButtonClicked"));
	}
	return FReply::Handled();
}

ECheckBoxState SHUDWidget::IsCheckBoxChecked() const
{
	return bCheckBoxState ? ECheckBoxState::Checked : ECheckBoxState::Unchecked;
}
void SHUDWidget::OnCheckBoxStateChanged(ECheckBoxState CheckBoxState)
{
	UE_LOG(LogSlate, Log, TEXT("CheckBoxStateChanged"));
	if (nullptr != GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, TEXT("OnCheckBoxStatChanged"));
	}
	bCheckBoxState = CheckBoxState == ECheckBoxState::Checked ? true : false;
}

//END_SLATE_FUNCTION_BUILD_OPTIMIZATION

#undef LOCTEXT_NAMESPACE