#include "RSJUserWidget.h"
#include "RSJCharacter.h"
#include "RSJGameState.h"
#include "Kismet/GameplayStatics.h"


void URSJUserWidget::NativeConstruct()
{
    Super::NativeConstruct();
    APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0); 
    if (PlayerController)
    {
        PlayerController->bShowMouseCursor = true;
        APawn* PlayerPawn = PlayerController->GetPawn();
        if (PlayerPawn)
        {
            ARSJCharacter* Player = Cast<ARSJCharacter>(PlayerPawn);
            PlayerHealth = Player->FindComponentByClass<URSJHealthComponent>();
            PlayerHealth->OnHealthChangedEvent.AddDynamic(this, &URSJUserWidget::OnHealthChanged);
            PlayerHealth->OnDeathEvent.AddDynamic(this, &URSJUserWidget::OnDeath);
        }
    }

    AGameStateBase* GameState = GetWorld()->GetGameState();
    if (GameState)
    {
        ARSJGameState* RSJGameState = Cast<ARSJGameState>(GameState);
        if (RSJGameState)
        {
            RSJGameState->OnScoreChangedEvent.AddDynamic(this, &URSJUserWidget::OnScoreChanged);
        }
    }
}

void URSJUserWidget::SetPause(bool IsPaused)
{
    APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
    if (PlayerController != NULL)
    {
        PlayerController->SetPause(IsPaused);
    }
}

