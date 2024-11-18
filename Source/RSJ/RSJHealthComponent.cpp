
#include "RSJHealthComponent.h"


URSJHealthComponent::URSJHealthComponent()
{

	PrimaryComponentTick.bCanEverTick = true;

	Health = MaxHealth;
}

void URSJHealthComponent::DecreaseHealth(float DeltaHealth)
{
	float old = Health;
	Health -= DeltaHealth;
	HandleHealthChange(old, Health);
}

void URSJHealthComponent::AddHealth(float DeltaHealth)
{
	float old = Health;
	Health += DeltaHealth;
	if (Health > MaxHealth)
	{
		Health = MaxHealth;
	}
	HandleHealthChange(old, Health);
}



void URSJHealthComponent::BeginPlay()
{
	Super::BeginPlay();
}



void URSJHealthComponent::HandleHealthChange(float OldHealth, float NewHealth)
{
	OnHealthChangedEvent.Broadcast(OldHealth, NewHealth);
	OnDeathEvent.Broadcast(GetOwner());
}

void URSJHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}


