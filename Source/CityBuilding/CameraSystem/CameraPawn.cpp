// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraPawn.h"

#include "CameraControlComponent.h"
#include "Camera/CameraComponent.h"
#include "CityBuilding/FunctionalPlacement/BuildingSpawnerComponent.h"
#include "GameFramework/SpringArmComponent.h"


// Sets default values
ACameraPawn::ACameraPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DefaultSceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	CameraRootComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraRoot"));
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	

	CameraControlComponent = CreateDefaultSubobject<UCameraControlComponent>(TEXT("CameraControl"));
	BuildingSpawnerComponent = CreateDefaultSubobject<UBuildingSpawnerComponent>(TEXT("BuildingSpawner"));
	
	RootComponent = DefaultSceneRoot;
	CameraRootComponent->SetupAttachment(RootComponent);
	CameraComponent->SetupAttachment(CameraRootComponent);
	CameraControlComponent->CameraRootComponent = CameraRootComponent;
}

// Called when the game starts or when spawned
void ACameraPawn::BeginPlay()
{
	Super::BeginPlay();
	SetupInputMode();
}

void ACameraPawn::SetupInputMode()
{
	APlayerController* PlayerController = Cast<APlayerController>(GetController());
	if (PlayerController == nullptr) return;

	FInputModeGameAndUI InputMode;
	InputMode.SetHideCursorDuringCapture(false);
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::LockOnCapture);
	PlayerController->SetInputMode(InputMode);
	PlayerController->SetShowMouseCursor(true);
	PlayerController->bEnableClickEvents = true;
}

// Called every frame
void ACameraPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector2D MovementInput(ForwardValue, RightValue);
	FVector2D RotationInput(PitchValue, YawValue);


	CameraControlComponent->SetMovementInput(MovementInput);
	CameraControlComponent->SetZoomInput(ZoomValue);
	ZoomValue = 0;
	if (bIsRotationActive)
	{
		CameraControlComponent->SetRotationInput(RotationInput);
	}
}

// Called to bind functionality to input
void ACameraPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}
