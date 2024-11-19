// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"

AEnemyAIController::AEnemyAIController()
{
    PrimaryActorTick.bCanEverTick = true;
    BehaviorTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComponent"));
    BlackboardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackboardComponent"));
}

void AEnemyAIController::BeginPlay()
{
    Super::BeginPlay();

    EnemyShooting = GetPawn()->FindComponentByClass<UShootingComponent>();

    if (IsValid(BehaviorTree.Get()))
    {
        RunBehaviorTree(BehaviorTree.Get());
        BehaviorTreeComponent->StartTree(*BehaviorTree.Get());
            
    }
}

void AEnemyAIController::OnPossess(APawn* InPawn)
{
    Super::OnPossess(InPawn);

    if (IsValid(Blackboard.Get()) && IsValid(BehaviorTree.Get()))
    {
        Blackboard->InitializeBlackboard(*BehaviorTree.Get()->BlackboardAsset.Get());
    }
}

void AEnemyAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    EnemyShooting->Shoot();
}

