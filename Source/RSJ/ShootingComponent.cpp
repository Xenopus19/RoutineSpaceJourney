

#include "ShootingComponent.h"

UShootingComponent::UShootingComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
    FireRate = 1.0f;
    TimeSinceLastShot = 0.0f;
}


void UShootingComponent::BeginPlay()
{
	Super::BeginPlay();
	
}


void UShootingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
    TimeSinceLastShot += DeltaTime;

}

void UShootingComponent::Shoot()
{
    if (TimeSinceLastShot < FireRate)
    {
        return;
    }
    if (BulletClass)
    {
        UWorld* World = GetWorld();
        if (World)
        {
            FVector SpawnLocation = GetComponentLocation();
            FRotator SpawnRotation = GetComponentRotation();

            AActor* SpawnedBullet = World->SpawnActor<AActor>(BulletClass, SpawnLocation, SpawnRotation);
            if (SpawnedBullet)
            {
                GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Bullet spawned!"));
            }
        }
    }
    TimeSinceLastShot = 0.0f;
}

