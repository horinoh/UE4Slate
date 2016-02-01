// Fill out your copyright notice in the Description page of Project Settings.

#include "UE4Slate.h"
#include "SlateHUD.h"

#include "Slate/HUDWidget.h"

void ASlateHUD::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	if (nullptr != GEngine && GEngine->IsValidLowLevel())
	{
		const auto GVC = GEngine->GameViewport;
		if (nullptr != GVC)
		{
			//!< ���̏�� SHUDWidget ���쐬���āA�����o�ϐ� HUDWidget �փA�T�C��
			SAssignNew(HUDWidget, SHUDWidget);
			//!< �r���[�|�[�g�֒ǉ�
			GEngine->GameViewport->AddViewportWidgetContent(SNew(SWeakWidget).PossiblyNullContent(HUDWidget.ToSharedRef()));
		}
	}
}
