// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraPawn.h"

#include "CameraControlComponent.h"
#include "GameFramework/SpringArmComponent.h"


// Sets default values
ACameraPawn::ACameraPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	CameraRootComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraRoot"));

	CameraControlComponent = CreateDefaultSubobject<UCameraControlComponent>(TEXT("CameraControl"));

	RootComponent = DefaultSceneRoot;
	CameraRootComponent->SetupAttachment(RootComponent);
	CameraControlComponent->CameraRootComponent = CameraRootComponent;
}

// Called when the game starts or when spawned
void ACameraPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACameraPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector2D MovementInput(ForwardValue, RightValue);
	FVector2D RotationInput(PitchValue,YawValue);


	CameraControlComponent->SetMovementInput(MovementInput);
	if(bIsRotationActive)
	{
		CameraControlComponent->SetRotationInput(RotationInput);
	}
}

// Called to bind functionality to input
void ACameraPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
}

