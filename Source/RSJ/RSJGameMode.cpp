

#include "RSJGameMode.h"
#include "RSJCharacter.h"
#include "RSJGameState.h"
#include "UObject/ConstructorHelpers.h"

ARSJGameMode::ARSJGameMode()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	GameStateClass = ARSJGameState::StaticClass();
}
