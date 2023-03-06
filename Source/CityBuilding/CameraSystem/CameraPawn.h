// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "CameraPawn.generated.h"

UCLASS()
class CITYBUILDING_API ACameraPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACameraPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//TODO: Move to a PlayerController if needed
	void SetupInputMode();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void AddBuilding();
	
	void AddZoomInput(const float Input) { ZoomValue += -Input; }

	void SetForwardValue(float Forward) { ForwardValue = Forward; }

	void SetRightValue(float Right) { RightValue = Right; }

	void SetPitchValue(float Pitch) { PitchValue = Pitch; }

	void SetYawValue(float Yaw) { YawValue = Yaw; }

	void ActivateRotation() { bIsRotationActive = true; }
	
	void DeactivateRotation() { bIsRotationActive = false; }

protected:
	UPROPERTY(BlueprintReadWrite)
	float ForwardValue;

	UPROPERTY(BlueprintReadWrite)
	float RightValue;

	UPROPERTY(BlueprintReadWrite)
	float PitchValue;

	UPROPERTY(BlueprintReadWrite)
	float YawValue;

	float ZoomValue;

	UPROPERTY(BlueprintReadWrite)
	bool bIsRotationActive;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* DefaultSceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class USpringArmComponent* CameraRootComponent;

	UPROPERTY(VisibleAnywhere)
	class UCameraComponent* CameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UCameraControlComponent* CameraControlComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UBuildingSpawnerComponent* BuildingSpawnerComponent;
};
