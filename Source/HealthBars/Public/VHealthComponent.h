// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "VHealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHealthDepletedSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHealthChangedSignature, int32, NewHealth, int32, MaxHealth);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class HEALTHBARS_API UVHealthComponent : public UActorComponent
{
	GENERATED_BODY()

	// Current health
	UPROPERTY(BlueprintGetter=GetHealth, Category="Default")
	int32 Health;

	// Max health
	UPROPERTY(BlueprintGetter=GetMaxHealth, EditAnywhere, Category="Default")
	int32 MaxHealth;
	
public:	
	// Sets default values for this component's properties
	UVHealthComponent();

	UPROPERTY(BlueprintAssignable, Category = "Default")
	FOnHealthChangedSignature OnHealthChanged;
	
	UPROPERTY(BlueprintAssignable, Category = "Default")
	FOnHealthDepletedSignature OnHealthDepleted;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	UFUNCTION(BlueprintGetter)
	int32 GetHealth() const;

	UFUNCTION(BlueprintGetter)
	int32 GetMaxHealth() const;
	
	UFUNCTION(BlueprintCallable)
	void UpdateHealth(int32 DeltaHealth);
};
