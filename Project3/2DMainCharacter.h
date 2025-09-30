// 2DMainCharacter.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "2DMainCharacter.generated.h"

UCLASS()
class PROJECT3_API A2DMainCharacter : public ACharacter
{
    GENERATED_BODY()

public:
    A2DMainCharacter();

protected:
    virtual void BeginPlay() override;
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
    // Input handlers
    void HandleWheelieInput(float AxisValue);
    void HandleRunInput(float AxisValue);

    // Wheelie logic
    UFUNCTION(BlueprintCallable, Category = "Movement")
    void PerformWheelie(float WheelieValue, float RunValue);

    // Store the current run input value
    float CurrentRunValue;

    // Store the current wheelie input value
    float CurrentWheelieValue;

    // Optional: Expose wheelie state to Blueprints
    UPROPERTY(BlueprintReadOnly, Category = "Movement", meta = (AllowPrivateAccess = "true"))
    bool bIsWheelying;

    // Optional: Wheelie intensity for animations/effects
    UPROPERTY(BlueprintReadOnly, Category = "Movement", meta = (AllowPrivateAccess = "true"))
    float WheelieIntensity;
}; #pragma once
