

#include "RSJGameState.h"

ARSJGameState::ARSJGameState()
{
	CurrentScore = 0;
}

void ARSJGameState::AddScore(int DeltaScore)
{
	CurrentScore += DeltaScore;
	OnScoreChangedEvent.Broadcast(CurrentScore);
	GEngine->AddOnScreenDebugMessage(
		-1,
		5.f,
		FColor::Red,
		*FString::Printf(TEXT("This is an on-screen message! Value: %d"), CurrentScore)
	);
}
