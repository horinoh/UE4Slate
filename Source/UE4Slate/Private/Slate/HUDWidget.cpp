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
	Get style by property name and set

	.TextStyle(YYYStyle::Get(), "XXX")
	.BorderImage(YYYStyle::Get().GetBrush("XXX"))
	.ButtonStyle(&YYYStyle::Get().GetWidgetStyle<FButtonStyle>("XXX"))

	Example of getting FCoreStyle's style or brush (Defined in FCoreStyle::Create())
	.Style(FCoreStyle::Get(), "Checkbox")
	.Style(FCoreStyle::Get(), "ToggleButtonCheckbox")
	.BorderImage(FCoreStyle::Get().GetBrush("NoBorder"))
	.Image(FCoreStyle::Get().GetDefaultBrush())
	*/

	//!< Image
	const auto Image = SNew(SImage)
		.Image(FHUDStyle::Get().GetBrush("UE4Icon"))
		.ToolTipText(LOCTEXT("SImage_Key", "SImage_Text"));
	//!< Border
	const auto Border = SNew(SBorder)
		.BorderImage(FCoreStyle::Get().GetBrush("ScrollBorder"));
	//!< TextBlock
	const auto TextBlock = SNew(STextBlock)
		.Text(LOCTEXT("STextBlock_Key", "STextBlock_Text"))
		//.Font(FEditorStyle::GetFontStyle(FName("ToolBarButton.LabelFont")))
		.ToolTipText(LOCTEXT("STextBlock_Key", "STextBlock_Text"));
	//!< Button
	const auto Button = SNew(SButton)
		.Text(LOCTEXT("SButton_Key", "SButton_Text"))
		.ToolTipText(LOCTEXT("SButton_Key", "SButton_Text"))
		.OnClicked(this, &SHUDWidget::OnButtonClicked);
	//!< CheckBox
	const auto CheckBox = SNew(SCheckBox)
		.IsChecked(this, &SHUDWidget::IsCheckBoxChecked)
		.OnCheckStateChanged(this, &SHUDWidget::OnCheckBoxStateChanged)
		.ToolTipText(LOCTEXT("SCheckBox_Key", "SCheckBox_Text"))
		[
			SNew(STextBlock)
			.Text(LOCTEXT("SCheckBox_Key", "SCheckBox_Text"))
		];

	//!< HorizontalBox
	const auto HorizontalBox = SNew(SHorizontalBox) + SHorizontalBox::Slot();
	HorizontalBox->AddSlot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		[
			TextBlock
		];
	HorizontalBox->AddSlot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		[
			Button
		];
	HorizontalBox->AddSlot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		[
			CheckBox
		];
	for (auto i = 0; i < 5; ++i) 
	{
		HorizontalBox->AddSlot()
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			[
				Image
			];
	}

	//!< VerticalBox
	const auto VerticalBox = SNew(SVerticalBox) + SVerticalBox::Slot();
	VerticalBox->AddSlot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		[
			TextBlock
		];
	VerticalBox->AddSlot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		[
			Button
		];
	VerticalBox->AddSlot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		[
			CheckBox
		];
	for (auto i = 0; i < 5; ++i) 
	{
		VerticalBox->AddSlot()
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			[
				Image
			];
	}

	//!< GridPanel
	const auto GridPanel = SNew(SUniformGridPanel).SlotPadding(FMargin(5.0f));
	for (auto i = 0; i < 5; ++i) 
	{
		for (auto j = 0; j < 5; ++j) 
		{
			GridPanel->AddSlot(i, j)
				.HAlign(HAlign_Center)
				.VAlign(VAlign_Center)
				[
					Image
				];
		}
	}

	//!< WrapBox
	const auto WrapBox = SNew(SWrapBox).PreferredWidth(1000.0f) + SWrapBox::Slot();
	for (auto i = 0; i < 20; ++i)
	{
		WrapBox->AddSlot()
			.Padding(20)
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				Image
			];
	}

	ChildSlot
	[
		//!< ScrollBox
		SNew(SScrollBox)		
		+SScrollBox::Slot()
		.Padding(10, 5)
		[
			HorizontalBox
		]

		+ SScrollBox::Slot()
		.Padding(10, 5)
		[
			Border
		]

		+ SScrollBox::Slot()
		.Padding(10, 5)
		[
			VerticalBox
		]

		+ SScrollBox::Slot()
		.Padding(10, 5)
		[
			Border
		]

		+ SScrollBox::Slot()
		.Padding(10, 5)
		[
			GridPanel
		]

		+ SScrollBox::Slot()
		.Padding(10, 5)
		[
			Border
		]

		+ SScrollBox::Slot()
		.Padding(10, 5)
		[
			WrapBox
		]

		+ SScrollBox::Slot()
		.Padding(10, 5)
		[
			Border
		]

		+ SScrollBox::Slot()
		.Padding(10, 5)
		[
			Border
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