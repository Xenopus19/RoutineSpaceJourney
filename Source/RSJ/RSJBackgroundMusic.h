

#pragma once

#include "CoreMinimal.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Actor.h"
#include "RSJBackgroundMusic.generated.h"

UCLASS()
class RSJ_API ARSJBackgroundMusic : public AActor
{
	GENERATED_BODY()
	
public:	
	ARSJBackgroundMusic();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio")
	USoundBase* SoundToPlay;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
