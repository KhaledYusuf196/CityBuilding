// Fill out your copyright notice in the Description page of Project Settings.


#include "PlacementMenuItemWidget.h"

#include "PlacementMenuWidget.h"
#include "PlacementUIHandlerInterface.h"
#include "Components/Button.h"
#include "Components/Image.h"

void UPlacementMenuItemWidget::SetupItem(UPlacementMenuWidget* PlacementMenuWidget, FBuildingPrototype BuildingPrototype)
{
	PlacementUIHandler = PlacementMenuWidget->PlacementUIHandler;

	BuildingActorClass = BuildingPrototype.BuildingActor;
	
	BuildingImage->SetBrushFromTexture(BuildingPrototype.BuildingImage);

	ActivateButton->OnClicked.AddDynamic(this, &UPlacementMenuItemWidget::OnActivateButtonClick);

	PlacementMenuWidget->AddPlacementMenuItem(this);
}

void UPlacementMenuItemWidget::OnActivateButtonClick()
{
	if(PlacementUIHandler == nullptr) return;
	PlacementUIHandler->ReceiveActiveBuilding(BuildingActorClass);
}

