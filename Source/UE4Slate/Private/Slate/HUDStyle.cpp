// Fill out your copyright notice in the Description page of Project Settings.

#include "UE4Slate.h"
#include "HUDStyle.h"

#include "SlateGameResources.h"

#include "HUDSlateWidgetStyleContainer.h"

/**
FHUDStyle は ゲームモジュールの StartupModule() でインスタンスを作成しているスタティッククラス
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

TSharedRef<class FSlateStyleSet> FHUDStyle::Create()
{
	TSharedRef<FSlateStyleSet> StyleRef = FSlateGameResources::New(FHUDStyle::GetStyleSetName(), "/Game/UI/Styles", "/Game/UI/Styles");

	auto& Style = StyleRef.Get();
	/**
	FSlateStyleSet::Set("XXX", スタイル) は第二引数に様々なスタイル(ブラシも可)を取るオーバーロードを持つ
	ここでスタイルを登録しておく

	Style.Set("XXX", FSlateImageBrush(FPaths::GameContentDir() / TEXT("YYY.png"), FVector2D(32, 32)));
	Style.Set("XXX", FSlateBoxBrush(FPaths::GameContentDir() / TEXT("YYY.png"), FMargin(3.0f / 8.0f)));
	Style.Set("XXX", FSlateBoxBrush(FPaths::GameContentDir() / TEXT("YYY.png"), FMargin(3.0f / 8.0f)));

	Style.Set("XXX", FTextBlockStyle()
	.SetFont(FSlateFontInfo(FPaths::GameContentDir() / TEXT("YYY.ttf"), 14))
	.SetColorAndOpacity(FLinearColor::White)
	.SetShadowOffset(FIntPoint(-1, 1))
	);
	Style.Set("XXX", FTextBlockStyle()
	.SetFont(FSlateFontInfo(FPaths::GameContentDir() / TEXT("YYY.otf"), 14))
	.SetColorAndOpacity(FLinearColor::White)
	.SetShadowOffset(FIntPoint(-1, 1))
	);
	*/

	//!< ここでは "HUDWidgetSytle" という名前で自前のスタイルを登録しておく
	Style.Set("HUDWidgetStyle", FHUDWidgetStyle());

	return StyleRef;
}

