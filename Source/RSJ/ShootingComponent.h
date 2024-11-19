
#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Bullet.h"
#include "ShootingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RSJ_API UShootingComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	UShootingComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Shooting")
	void Shoot();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shooting")
	TSubclassOf<ABullet> BulletClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Shooting")
	float FireRate;

private:

	float TimeSinceLastShot;
};
