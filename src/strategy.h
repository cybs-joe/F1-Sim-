#pragma once
#include <string>
#include <cmath>
#include <vector>
#include <random>
#include "car.h"
#include "tire.h"
#include "track.h"
using namespace std;

enum SafetyCarState{
    None,
    VIRTUAL,
    FULL,
};

struct RaceState{
    int currentLap;
    int totalLaps;
    SafetyCarState scState;
    int scEndLap;
};
class StrategyEngine{
    public:
    static bool shouldPit(Car& car , const vector<Car>& allCars, const Track& track, const RaceState& state);
    static Compound chooseTireCompound(const Car& car, const Track& track, const RaceState& state);

    private:
    static bool isMandatoryStopUrgent(const Car& car, const RaceState& state);
    static bool isTireNearCliff(const Tire& tire);
    static bool shouldPitUnderSC(const Car& car , const RaceState& state);
    static bool shouldUndercutCarAhead(const Car& car, const Car& carAhead, const Track& track, const RaceState& state);
    static float estimatePitBenefit(const Car& car, const Track& track, const RaceState& state, Compound newCompound);

    
};