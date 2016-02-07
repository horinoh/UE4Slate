// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#pragma once

#include "SlateBasics.h"

class FHUDStyle
{
public:
	static void Initialize();
	static void Shutdown();
	static const class ISlateStyle& Get();
	static FName GetStyleSetName();

private:
	static TSharedRef<class FSlateStyleSet> Create();
	static TSharedPtr<class FSlateStyleSet> HUDStyleInstance;
};
