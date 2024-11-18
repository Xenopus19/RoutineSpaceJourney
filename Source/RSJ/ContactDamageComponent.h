
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RSJHealthComponent.h"
#include "ContactDamageComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RSJ_API UContactDamageComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UContactDamageComponent();

protected:
	virtual void BeginPlay() override;

	UStaticMeshComponent* Mesh;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);


	UPROPERTY(EditAnywhere)
	float Damage;
		
};
