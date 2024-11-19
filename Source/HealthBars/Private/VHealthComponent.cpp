// Fill out your copyright notice in the Description page of Project Settings.


#include "VHealthComponent.h"

// Sets default values for this component's properties
UVHealthComponent::UVHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UVHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	Health = MaxHealth;
	// ...
	
}

float UVHealthComponent::GetHealth() const
{
	return Health;
}
	 
float UVHealthComponent::GetMaxHealth() const
{
	return MaxHealth;
}

void UVHealthComponent::UpdateHealth(float DeltaHealth)
{
	Health+=DeltaHealth;
	//Clamp the health to avoid values less than 0 and bigger than MaxHealth
	Health = FMath::Clamp(Health, 0.0f, MaxHealth);

	OnHealthChanged.Broadcast(Health, MaxHealth);
	
	if(Health == 0.0f)
	{
		OnHealthDepleted.Broadcast();
	}
}