// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BuildingActor.generated.h"

UCLASS()
class CITYBUILDING_API ABuildingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABuildingActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	void SelectBuilding() const;

	void DeselectBuilding() const;

private:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* BuildingMesh;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY()
	class UBuildingActionComponent* BuildingActionComponent;

};
