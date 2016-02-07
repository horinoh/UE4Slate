// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Styling/SlateWidgetStyleContainerBase.h"
#include "HUDSlateWidgetStyleContainer.generated.h"

USTRUCT()
struct FHUDWidgetStyle : public FSlateWidgetStyle
{
	GENERATED_BODY()

public:
	//!< FSlateWidgetStyle
	virtual void GetResources(TArray<const FSlateBrush*> & OutBrushes) const override;
	virtual const FName GetTypeName() const override
	{
		return TypeName;
	}

	static const FName TypeName;
	static const FHUDWidgetStyle& GetDefault();

	UPROPERTY(EditAnywhere, Category = Appearance)
	FSlateBrush XXXBrush;
};

/**
 * 
 */
UCLASS()
class UHUDSlateWidgetStyleContainer : public USlateWidgetStyleContainerBase
{
	GENERATED_BODY()
	
public:
	//!< USlateWidgetStyleContainerBase
	virtual const struct FSlateWidgetStyle* const GetStyle() const override
	{
		return static_cast< const struct FSlateWidgetStyle* >(&HUDWidgetStyle);
	}

	UPROPERTY(Category = Appearance, EditAnywhere, meta = (ShowOnlyInnerProperties))
	FHUDWidgetStyle HUDWidgetStyle;
};
