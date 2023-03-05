// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlacementMenuItemWidget.h"
#include "PlacementUIHandlerInterface.h"
#include "Blueprint/UserWidget.h"
#include "PlacementMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class CITYBUILDING_API UPlacementMenuWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual bool Initialize() override;

	void AddPlacementMenuItem(UUserWidget* Item);

private:
	UPROPERTY(meta = (BindWidget))
	class UButton* PlacementMenuButton;

	UPROPERTY(meta = (BindWidget))
	UPanelWidget* PlacementMenuList;


	UFUNCTION()
	void ShowPlacementMenuList();

	UFUNCTION()
	void HidePlacementMenuList();

public:
	IPlacementUIHandlerInterface* PlacementUIHandler;
};
