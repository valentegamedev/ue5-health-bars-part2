// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "VHealthBarWidget.generated.h"

class UProgressBar;
class UTextBlock;
class UVHealthComponent;

UCLASS()
class HEALTHBARS_API UVHealthBarWidget : public UUserWidget
{
	GENERATED_BODY()
	TWeakObjectPtr<UVHealthComponent> TargetHealthComponent;
	 
	UFUNCTION()
	void OnHealthChanged(float NewHealth, float MaxHealth);
	
protected:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UProgressBar> HealthProgressBar;
	 
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UTextBlock> HealthTextBlock;
public:
	UFUNCTION(BlueprintCallable)
	void SetTargetHealthComponent(UVHealthComponent* NewHealthComponent);
};
