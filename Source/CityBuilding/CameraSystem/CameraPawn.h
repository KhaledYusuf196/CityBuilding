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

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	void AddZoomInput(const float Input) { ZoomValue += -Input; }

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
	class UCameraControlComponent* CameraControlComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class USpringArmComponent* CameraRootComponent;
};
