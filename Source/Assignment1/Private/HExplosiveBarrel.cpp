// Fill out your copyright notice in the Description page of Project Settings.


#include "HExplosiveBarrel.h"
#include "Components/StaticMeshComponent.h"
#include "PhysicsEngine/RadialForceComponent.h"


// Sets default values
AHExplosiveBarrel::AHExplosiveBarrel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BarrelMesh = CreateDefaultSubobject<UStaticMeshComponent>("BarrelMesh");
	RootComponent = BarrelMesh;

	RadForce = CreateDefaultSubobject<URadialForceComponent>("RadForce");
	RadForce->SetupAttachment(BarrelMesh);

	BarrelMesh->SetSimulatePhysics(true);
	RadForce->bImpulseVelChange = true;

}

// Called when the game starts or when spawned
void AHExplosiveBarrel::BeginPlay()
{
	Super::BeginPlay();
	
	BarrelMesh->OnComponentHit.AddDynamic(this, &AHExplosiveBarrel::Explode);

}



// Called every frame
void AHExplosiveBarrel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHExplosiveBarrel::Explode(UPrimitiveComponent* Projectile, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	RadForce->FireImpulse();

}

