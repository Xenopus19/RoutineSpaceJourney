// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "ContactDamageComponent.h"
#include "Bullet.generated.h"

class USphereComponent;
class UProjectileMovementComponent;
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

    UPROPERTY(EditAnywhere)
    class UStaticMeshComponent* BulletMesh;

	UPROPERTY(EditAnywhere)
	UProjectileMovementComponent* ProjectileComponent;

	UPROPERTY(EditAnywhere)
	class UContactDamageComponent* ContactDamage;
};
