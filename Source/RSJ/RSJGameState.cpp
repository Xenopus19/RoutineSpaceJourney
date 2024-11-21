

#include "RSJGameState.h"

ARSJGameState::ARSJGameState()
{
	CurrentScore = 0;
}

void ARSJGameState::AddScore(int DeltaScore)
{
	CurrentScore += DeltaScore;
	OnScoreChangedEvent.Broadcast(CurrentScore);
}
