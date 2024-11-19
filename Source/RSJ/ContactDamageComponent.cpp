#include "ContactDamageComponent.h"


UContactDamageComponent::UContactDamageComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	if (GetOwner())
	{
		if(GetOwner()->FindComponentByClass<UStaticMeshComponent>())
		{
			Mesh = GetOwner()->FindComponentByClass<UStaticMeshComponent>();
		}
	}
}


void UContactDamageComponent::BeginPlay()
{
	Super::BeginPlay();

	Mesh->OnComponentHit.AddDynamic(this, &UContactDamageComponent::OnHit);
	
}


void UContactDamageComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UContactDamageComponent::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	URSJHealthComponent* health = OtherActor->FindComponentByClass<URSJHealthComponent>();
	if (health)
	{
		health->DecreaseHealth(Damage);
	}
	OnHitEvent.Broadcast();
}

