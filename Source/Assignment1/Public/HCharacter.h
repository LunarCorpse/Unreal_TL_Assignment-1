// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "HCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class ASSIGNMENT1_API AHCharacter : public ACharacter
{
	GENERATED_BODY()

protected:
	
	UPROPERTY(EditAnywhere, Category = "Attacks")
	TSubclassOf<AActor> ProjectileClass;


public:
	// Sets default values for this character's properties
	AHCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComp;

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArmComp;



	void MoveForward(float value);
	void MoveRight(float value);

	void PrimaryAttack();
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
