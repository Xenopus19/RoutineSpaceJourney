

#pragma once

#include "CoreMinimal.h"
#include "RSJHealthComponent.h"
#include "Blueprint/UserWidget.h"
#include "RSJUserWidget.generated.h"

UCLASS()
class RSJ_API URSJUserWidget : public UUserWidget
{
	GENERATED_BODY()
	

protected:
	virtual void NativeConstruct() override;

	UFUNCTION(BlueprintImplementableEvent)
	void OnScoreChanged(int NewScore);

	UFUNCTION(BlueprintImplementableEvent)
	void OnHealthChanged(float OldHealth, float NewHealth);

	UFUNCTION(BlueprintImplementableEvent)
	void OnDeath(AActor* OwningActor);

	UPROPERTY(BlueprintReadOnly)
	URSJHealthComponent* PlayerHealth;
};
