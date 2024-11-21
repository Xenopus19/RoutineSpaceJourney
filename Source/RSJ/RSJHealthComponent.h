

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RSJHealthComponent.generated.h"
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHealthChanged, float, OldHealth, float, NewHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDeath, AActor*, OwningActor);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )

class RSJ_API URSJHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	URSJHealthComponent();

	UFUNCTION(BlueprintCallable)
	void DecreaseHealth(float DeltaHealth);

	UFUNCTION(BlueprintCallable)
	void AddHealth(float DeltaHealth);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetHealthNormalised();

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnHealthChanged OnHealthChangedEvent;

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnDeath OnDeathEvent;

protected:

	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly)
	float Health;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxHealth; 

	void HandleHealthChange(float OldHealth, float NewHealth);

public:	

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
