


#include "RSJBackgroundMusic.h"

ARSJBackgroundMusic::ARSJBackgroundMusic()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ARSJBackgroundMusic::BeginPlay()
{
	Super::BeginPlay();
	UWorld* World = GetWorld();
	if (World && SoundToPlay)
	{
		UGameplayStatics::PlaySound2D(World, SoundToPlay);
	}
}

void ARSJBackgroundMusic::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

