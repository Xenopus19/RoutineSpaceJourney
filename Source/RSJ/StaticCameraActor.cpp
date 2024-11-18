// Fill out your copyright notice in the Description page of Project Settings.


#include "StaticCameraActor.h"

// Sets default values
AStaticCameraActor::AStaticCameraActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));

	SetActorLocation(FVector(0.f, 0.f, 500.f)); 
	SetActorRotation(FRotator(-90.f, 0.f, 0.f));

}

// Called when the game starts or when spawned
void AStaticCameraActor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AStaticCameraActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

