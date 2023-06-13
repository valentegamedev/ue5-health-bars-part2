// Fill out your copyright notice in the Description page of Project Settings.


#include "VHealthComponent.h"

// Sets default values for this component's properties
UVHealthComponent::UVHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}


// Called when the game starts
void UVHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	// Initializing the health
	Health = MaxHealth;
}

int32 UVHealthComponent::GetHealth() const
{
	return Health;
}

int32 UVHealthComponent::GetMaxHealth() const
{
	return MaxHealth;
}

void UVHealthComponent::UpdateHealth(int32 DeltaHealth)
{
	Health+=DeltaHealth;
	//Clamp the health to avoid values less than 0 and bigger than MaxHealth
	Health = FMath::Clamp(Health, 0.0f, MaxHealth);

	if(Health == 0.0f)
	{
		OnHealthChanged.Broadcast(Health, MaxHealth);
		OnHealthDepleted.Broadcast();
	} else
	{
		OnHealthChanged.Broadcast(Health, MaxHealth);
	}
}