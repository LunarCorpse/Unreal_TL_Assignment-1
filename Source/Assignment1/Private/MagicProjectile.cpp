// Fill out your copyright notice in the Description page of Project Settings.


#include "MagicProjectile.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"


// Sets default values
AMagicProjectile::AMagicProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereComp = CreateDefaultSubobject<USphereComponent>("SphereComp");
	SphereComp->SetCollisionProfileName("Projectile");
	RootComponent = SphereComp;

	
	EffectComp = CreateDefaultSubobject<UParticleSystemComponent>("EffectComp");
	EffectComp->SetupAttachment(SphereComp);

	ProjectileComp = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileComp");
	ProjectileComp->InitialSpeed = 1000.f;
	ProjectileComp->bRotationFollowsVelocity = true;
	ProjectileComp->bInitialVelocityInLocalSpace = true;
	ProjectileComp->ProjectileGravityScale = 0.0f;

}

// Called when the game starts or when spawned
void AMagicProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMagicProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

