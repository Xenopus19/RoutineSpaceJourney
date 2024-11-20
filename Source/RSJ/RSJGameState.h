
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "RSJGameState.generated.h"
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnScoreChanged, int, NewScore);
UCLASS()
class RSJ_API ARSJGameState : public AGameStateBase
{
	GENERATED_BODY()
	
public:

	ARSJGameState();
	UFUNCTION(BlueprintCallable)
	void AddScore(int DeltaScore);

	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnScoreChanged OnScoreChangedEvent;

protected:
	int CurrentScore;


};
