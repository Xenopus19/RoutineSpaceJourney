


#include "Bullet.h"

ABullet::ABullet()
{
	PrimaryActorTick.bCanEverTick = true;

    BulletMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BulletMesh"));
    RootComponent = BulletMesh;

	ProjectileComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	ProjectileComponent->InitialSpeed = 800;
	ProjectileComponent->MaxSpeed = 8500;

	ContactDamage = CreateDefaultSubobject<UContactDamageComponent>(TEXT("ContactDamage"));
	ContactDamage->OnHitEvent.AddDynamic(this, &ABullet::OnBulletHit);
}

void ABullet::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABullet::OnBulletHit()
{
	Destroy();
}

void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

