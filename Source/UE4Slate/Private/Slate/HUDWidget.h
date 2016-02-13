// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SlateBasics.h"
//#include "SlateExtras.h"

class SHUDWidget : public SCompoundWidget
{
public:
	/**
	FArgments はこのマクロで定義される
	FArgments のメンバには先頭に "_" が自動的に付けられる
	*/
	SLATE_BEGIN_ARGS(SHUDWidget)
	//	: _XXXBrush(FCoreStyle::Get().GetDefaultBrush())
	//	, _SlateHUD(nullptr)
	{}
	//SLATE_ATTRIBUTE(const FSlateBrush*, XXXBrush)
	//SLATE_ARGUMENT(TWeakObjectPtr<class ASlateHUD>, SlateHUD)
	//SLATE_EVENT(FOnClicked, OnClicked)
	//SLATE_NAMED_SLOT(FArguments, FSimpleSlot, Content)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	FReply OnButtonClicked();

	ECheckBoxState IsCheckBoxChecked() const;
	void OnCheckBoxStateChanged(ECheckBoxState CheckBoxState);

protected:
	//TWeakObjectPtr<class ASlateHUD> SlateHUD;
	bool bCheckBoxState;
};
