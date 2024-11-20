
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemySpawner.generated.h"

UCLASS()
class RSJ_API AEnemySpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AEnemySpawner();

protected:
	
	virtual void BeginPlay() override;

	void SpawnEnemy();

public:	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	float SpawnRate;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	TSubclassOf<AActor> EnemyClass;

private:
	float TimeSinceLastSpawn;

};
