// Fill out your copyright notice in the Description page of Project Settings.

#include "UE4Slate.h"
#include "HUDSlateWidgetStyleContainer.h"

const FName FHUDWidgetStyle::TypeName(TEXT("FHUDWidgetStyle"));

void FHUDWidgetStyle::GetResources(TArray<const FSlateBrush*> & OutBrushes) const
{
	//!< ƒƒ“ƒo‚Éƒuƒ‰ƒV‚ðŽ‚½‚¹‚½ê‡‚ÍŽÀ‘•‚·‚é
	OutBrushes.Add(&XXXBrush);
}

const FHUDWidgetStyle& FHUDWidgetStyle::GetDefault()
{
	static FHUDWidgetStyle Default;
	return Default;
}

