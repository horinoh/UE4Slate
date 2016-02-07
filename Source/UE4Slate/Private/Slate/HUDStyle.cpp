// Fill out your copyright notice in the Description page of Project Settings.

#include "UE4Slate.h"
#include "HUDStyle.h"

#include "SlateGameResources.h"

#include "HUDSlateWidgetStyleContainer.h"

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

TSharedRef<class FSlateStyleSet> FHUDStyle::Create()
{
	TSharedRef<FSlateStyleSet> StyleRef = FSlateGameResources::New(FHUDStyle::GetStyleSetName(), "/Game/UI/Styles", "/Game/UI/Styles");

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

	//!< �����ł� "HUDWidgetSytle" �Ƃ������O�Ŏ��O�̃X�^�C����o�^���Ă���
	Style.Set("HUDWidgetStyle", FHUDWidgetStyle());

	return StyleRef;
}

