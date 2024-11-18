// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bullet.generated.h"

class USphereComponent;

UCLASS()
class RSJ_API ABullet : public AActor
{
	GENERATED_BODY()
	
public:	

	ABullet();

protected:

	virtual void BeginPlay() override;

public:	

	virtual void Tick(float DeltaTime) override;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collision")
    class USphereComponent* CollisionSphere;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
    class UStaticMeshComponent* BulletMesh;
};
