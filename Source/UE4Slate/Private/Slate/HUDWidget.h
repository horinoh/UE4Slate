// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SlateBasics.h"
//#include "SlateExtras.h"

class SHUDWidget : public SCompoundWidget
{
public:
	//!< FArgments �͂��̃}�N���Œ�`�����
	SLATE_BEGIN_ARGS(SHUDWidget) {}
	//SLATE_ARGUMENT(TYPE, NAME)
	//SLATE_ARGUMENT(TWeakObjectPtr<class ASlateHUD>, SlateHUD)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

protected:
	//TWeakObjectPtr<class ASlateHUD> SlateHUD;
	//TWeakObjectPtr<class TYPE> NAME;
	//TSharedPtr<FSlateDynamicImageBrush> HUDBrush;
};
