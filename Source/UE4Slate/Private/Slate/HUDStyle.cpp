// Fill out your copyright notice in the Description page of Project Settings.

#include "UE4Slate.h"
#include "HUDStyle.h"

#include "SlateGameResources.h"

/**
FHUDStyle �� �Q�[�����W���[���� StartupModule() �ŃC���X�^���X���쐬���Ă���X�^�e�B�b�N�N���X
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
�Q�l FCoreStyle::Create()
*/
TSharedRef<class FSlateStyleSet> FHUDStyle::Create()
{
	TSharedRef<FSlateStyleSet> StyleRef = FSlateGameResources::New(FHUDStyle::GetStyleSetName(), "/Game/Slate", "/Game/Slate");

	auto& Style = StyleRef.Get();
	/**
	FSlateStyleSet::Set("XXX", �X�^�C��) �͑������ɗl�X�ȃX�^�C��(�u���V����)�����I�[�o�[���[�h������
	�����ŃX�^�C����o�^���Ă���

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

	//!< https://wiki.unrealengine.com/First_Person_Shooter_C%2B%2B_Tutorial ����N���X�w�A�摜�������Ă���
	Style.Set("Crosshair", new FSlateImageBrush(FPaths::GameContentDir() / TEXT("Crosshair_fps_tutorial") / TEXT("crosshair") + TEXT(".TGA"), FVector2D(16, 16)));
	//!< UnrealEngine\Engine\Content\Slate\Testing\UE4Icon.png ���R�s�[���Ă���
	Style.Set("UE4Icon", new FSlateImageBrush(FPaths::GameContentDir() / TEXT("Slate") / TEXT("UE4Icon") + TEXT(".png"), FVector2D(50, 50)));

	return StyleRef;
}

