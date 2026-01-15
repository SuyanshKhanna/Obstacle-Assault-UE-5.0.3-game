// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	//UE_LOG(LogTemp, Display, TEXT("Memberfloat current val: %f"), MemberFloat);
	//UE_LOG(LogTemp, Display, TEXT("only Visible %d"), iCanSeeYou);

	//FVector Test = FVector(-720.0f, -460.0f, 710.0f);
	//(X = -720.000000, Y = -460.000000, Z = 710.000000)
	//SetActorLocation(Test);
	StartLocation = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);

	
}
void AMovingPlatform::MovePlatform(float DeltaTime)
{
	FVector Current = GetActorLocation();
	Current = Current + (PlatformVelocity * DeltaTime);
	SetActorLocation(Current);
	Distance = FVector::Dist(StartLocation, Current);
	if (Distance >= MAXDistance) {
		FVector Direction = PlatformVelocity.GetSafeNormal();
		FVector NewStart = StartLocation + MAXDistance * Direction;
		SetActorLocation(NewStart);
		StartLocation = NewStart;
		PlatformVelocity = -PlatformVelocity;
	}
	//SetActorRotation()
}

void AMovingPlatform::RotatePlatform(float DeltaTime){
	{
		FRotator RotationToAdd = RotationVelocity * DeltaTime;
		AddActorLocalRotation(RotationToAdd);
		//SetActorRotation(RotationVelocity * DeltaTime);
	}
}

