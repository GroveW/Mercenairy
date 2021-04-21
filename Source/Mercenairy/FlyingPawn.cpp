// Fill out your copyright notice in the Description page of Project Settings.


#include "FlyingPawn.h"

#include "GameFramework/FloatingPawnMovement.h"

// Sets default values
AFlyingPawn::AFlyingPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	FloatingPawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>("Floating Pawn Movement");
}

// Called when the game starts or when spawned
void AFlyingPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFlyingPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFlyingPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MouseX", this, &AFlyingPawn::Mouse_X);
	PlayerInputComponent->BindAxis("MouseY", this, &AFlyingPawn::Mouse_Y);
	PlayerInputComponent->BindAxis("Accelerate", this, &AFlyingPawn::Accelerate);
	PlayerInputComponent->BindAxis("Sideways", this, &AFlyingPawn::Sideways);
}

void AFlyingPawn::Mouse_X(float Value)
{

}

void AFlyingPawn::Mouse_Y(float Value)
{
	float Velocity = FloatingPawnMovement->Velocity.Size();

	if (Velocity > 1000.0f)
	{
		FRotator NewRot = GetActorRotation() + (FVector::UpVector.Rotation() * Value * -0.01f);

		SetActorRotation(NewRot);
	}
}

void AFlyingPawn::Accelerate(float Value)
{
	FloatingPawnMovement->AddInputVector(GetActorForwardVector() * Value);
}

void AFlyingPawn::Sideways(float Value)
{
	float Velocity = FloatingPawnMovement->Velocity.Size();

	if (Velocity > 0.01f)
	{
		FRotator NewRot = GetActorRotation() + (FVector::RightVector.Rotation() * (Value * 0.01f * Velocity / FloatingPawnMovement->GetMaxSpeed()));

		SetActorRotation(NewRot);
	}
}