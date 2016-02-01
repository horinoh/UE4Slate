// Fill out your copyright notice in the Description page of Project Settings.

#include "UE4Slate.h"
#include "SlateGameMode.h"

#include "SlateHUD.h"

ASlateGameMode::ASlateGameMode()
{
	HUDClass = ASlateHUD::StaticClass();
}
