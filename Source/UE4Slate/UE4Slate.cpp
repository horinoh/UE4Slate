// Fill out your copyright notice in the Description page of Project Settings.

#include "UE4Slate.h"

#include "Private/Slate/HUDStyle.h"

class FSlateGameModuleImpl : public FDefaultGameModuleImpl
{
	virtual void StartupModule() override
	{
		//FSlateStyleRegistry::UnRegisterSlateStyle(FHUDStyle::GetStyleSetName());
		FHUDStyle::Initialize();
	}

	virtual void ShutdownModule() override
	{
		FHUDStyle::Shutdown();
	}
};

IMPLEMENT_PRIMARY_GAME_MODULE( FSlateGameModuleImpl, UE4Slate, "UE4Slate" );
