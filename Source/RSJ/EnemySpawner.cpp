


#include "EnemySpawner.h"

AEnemySpawner::AEnemySpawner()
{
	PrimaryActorTick.bCanEverTick = true;
    
}

void AEnemySpawner::BeginPlay()
{
	Super::BeginPlay();
    TimeSinceLastSpawn = 0.0f;
}

void AEnemySpawner::SpawnEnemy()
{
    if (TimeSinceLastSpawn < SpawnRate)
    {
        return;
    }
    if (EnemyClass)
    {
        
        UWorld* World = GetWorld();
        if (World)
        {
            FVector SpawnLocation = GetActorLocation();
            FRotator SpawnRotation = GetActorRotation();

            AActor* Enemy = World->SpawnActor<AActor>(EnemyClass, SpawnLocation, SpawnRotation);
            if (Enemy)
            {
                TimeSinceLastSpawn = 0.0f;
            }
        }
    }
}

void AEnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TimeSinceLastSpawn += DeltaTime;
    SpawnEnemy();
}

