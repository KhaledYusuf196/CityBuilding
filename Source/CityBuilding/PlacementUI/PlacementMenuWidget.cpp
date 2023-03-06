// Fill out your copyright notice in the Description page of Project Settings.


#include "PlacementMenuWidget.h"

#include "Components/Button.h"
#include "Components/CanvasPanelSlot.h"


bool UPlacementMenuWidget::Initialize()
{
	if(!Super::Initialize()) return false;
	
	if(!ensure(PlacementMenuList != nullptr)) return false;
	PlacementMenuList->Visibility = ESlateVisibility::Hidden;

	if(!ensure(PlacementMenuButton != nullptr)) return false;
	PlacementMenuButton->OnClicked.AddDynamic(this, &UPlacementMenuWidget::ShowPlacementMenuList);
	
	return true;
}

void UPlacementMenuWidget::AddPlacementMenuItem(UUserWidget* Item)
{
	PlacementMenuList->AddChild(Item);
}

FReply UPlacementMenuWidget::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	if(InMouseEvent.IsMouseButtonDown(FKey("RightMouseButton")))
	{
		HidePlacementMenuList();
	}
	return Super::NativeOnMouseButtonDown(InGeometry, InMouseEvent);
}


void UPlacementMenuWidget::ShowPlacementMenuList()
{
	PlacementMenuList->SetVisibility(ESlateVisibility::Visible);
}

void UPlacementMenuWidget::HidePlacementMenuList()
{
	PlacementMenuList->SetVisibility(ESlateVisibility::Hidden);
}
