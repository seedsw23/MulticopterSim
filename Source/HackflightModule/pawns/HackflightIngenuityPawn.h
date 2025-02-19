/*
* Class declaration for pawn class using Hackflight flight manager
*
* Copyright (C) 2021 Simon D. Levy
*
* MIT License
*/

#pragma once

#include <actuators/mixers/quadxap.hpp>

#include "../../MainModule/vehicles/multirotors/Ingenuity.hpp"

#include "../HackflightFlightManager.hpp"

#include "SimMotor.hpp"

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "HackflightIngenuityPawn.generated.h"

UCLASS(Config=Game)
class HACKFLIGHTMODULE_API AHackflightIngenuityPawn : public APawn {

    private:

        GENERATED_BODY()

        // Helper class
        Ingenuity _ingenuity;

        FHackflightFlightManager * _flightManager = NULL;

        SimMotor _motors = SimMotor(4);

        hf::MixerQuadXAP  _mixer = hf::MixerQuadXAP(&_motors);

    protected:

        // AActor overrides

        virtual void BeginPlay() override;

        virtual void Tick(float DeltaSeconds) override;

        virtual void PostInitializeComponents() override;

        virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

        // virtual void NotifyHit(...) override

    public:	

        AHackflightIngenuityPawn();

}; // AHackflightIngenuityPawn
