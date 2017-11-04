// Fill out your copyright notice in the Description page of Project Settings.

#include "UE4Slate.h"
#include "HUDStyle.h"

#include "SlateGameResources.h"

/**
FHUDStyle is static class instanced in StartupModle()
*/

TSharedPtr<class FSlateStyleSet> FHUDStyle::HUDStyleInstance = nullptr;

void FHUDStyle::Initialize()
{
	if (!HUDStyleInstance.IsValid())
	{
		HUDStyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*HUDStyleInstance);
	}
}

void FHUDStyle::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*HUDStyleInstance);
	ensure(HUDStyleInstance.IsUnique());
	HUDStyleInstance.Reset();
}

const class ISlateStyle& FHUDStyle::Get()
{
	return *HUDStyleInstance;
}

FName FHUDStyle::GetStyleSetName()
{
	static FName StyleSetName(TEXT("HUDStyle"));
	return StyleSetName;
}

/**
cf. FCoreStyle::Create()
*/
TSharedRef<class FSlateStyleSet> FHUDStyle::Create()
{
	TSharedRef<FSlateStyleSet> StyleRef = FSlateGameResources::New(FHUDStyle::GetStyleSetName(), "/Game/Slate", "/Game/Slate");

	auto& Style = StyleRef.Get();
	/**
	Style.Set("XXX", FSlateImageBrush(FPaths::ProjectContentDir() / TEXT("YYY.png"), FVector2D(32, 32)));
	Style.Set("XXX", FSlateBoxBrush(FPaths::ProjectContentDir() / TEXT("YYY.png"), FMargin(3.0f / 8.0f)));
	Style.Set("XXX", FSlateBoxBrush(FPaths::ProjectContentDir() / TEXT("YYY.png"), FMargin(3.0f / 8.0f)));

	Style.Set("XXX", FTextBlockStyle()
	.SetFont(FSlateFontInfo(FPaths::ProjectContentDir() / TEXT("YYY.ttf"), 14))
	.SetColorAndOpacity(FLinearColor::White)
	.SetShadowOffset(FIntPoint(-1, 1))
	);
	Style.Set("XXX", FTextBlockStyle()
	.SetFont(FSlateFontInfo(FPaths::ProjectContentDir() / TEXT("YYY.otf"), 14))
	.SetColorAndOpacity(FLinearColor::White)
	.SetShadowOffset(FIntPoint(-1, 1))
	);
	*/

	//!< Crosshair image is from https://wiki.unrealengine.com/First_Person_Shooter_C%2B%2B_Tutorial
	Style.Set("Crosshair", new FSlateImageBrush(FPaths::ProjectContentDir() / TEXT("Crosshair_fps_tutorial") / TEXT("crosshair") + TEXT(".TGA"), FVector2D(16, 16)));
	//!< Copy from UnrealEngine\Engine\Content\Slate\Testing\UE4Icon.png
	Style.Set("UE4Icon", new FSlateImageBrush(FPaths::ProjectContentDir() / TEXT("Slate") / TEXT("UE4Icon") + TEXT(".png"), FVector2D(50, 50)));

	return StyleRef;
}

