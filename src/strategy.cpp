#include <iostream>
#include "strategy.h"
using namespace std;

bool StrategyEngine::isTireNearCliff(const Tire& tire){
    if (tire.age >= tire.cliffLap()-1){
        return true;
    }
    else{
        return false;
    }
}

bool StrategyEngine::isMandatoryStopUrgent(const Car& car, const RaceState& state){
    if(car.hasMandatoryHardStop() == true and state.totalLaps - state.currentLap < 12){
        return true;
    }
    else{
        return false;
    }
}

bool StrategyEngine::shouldPitUnderSC(const Car& car , const RaceState& state){
    if (state.totalLaps-state.currentLap > 8 && (car.completedStops.empty() || StrategyEngine::isTireNearCliff(car.tire) ||  car.tire.age > 15 && state.totalLaps-state.currentLap >15)){
        return true;
    }
    else{
        return false;
    }
}

bool StrategyEngine::shouldUndercutCarAhead(const Car& car, const Car& carAhead, const Track& track, const RaceState& state){
    double advantage = carAhead.tire.degPenalty() - Tire(car.tire.compound).degPenalty();
    if(state.totalLaps-state.currentLap > 10 && car.gapToCarAhead < 2.0 && (carAhead.tire.age - car.tire.age) <= 5 && ((carAhead.tire.cliffLap() - carAhead.tire.age) <= 3) && advantage > 0.2 ){
        return true;
    }
    else{
        return false;
    }
}

float StrategyEngine::estimatePitBenefit(const Car& car, const Track& track, const RaceState& state, Compound newCompound){
    float current_tire_pen = 0.0;
    float total_fresh_t_pen = 0.0;

    for(int i = 0 ; i < 5 ; i++){
        Tire currentTemp = Tire(car.tire.compound);
        currentTemp.age = car.tire.age + i;
        current_tire_pen += currentTemp.degPenalty();

        Tire freshTemp = Tire(newCompound);
        freshTemp.age =  i;
        total_fresh_t_pen += freshTemp.degPenalty();
    }
    return (current_tire_pen-total_fresh_t_pen)/5;
}

Compound StrategyEngine::chooseTireCompound(const Car& car, const Track& track, const RaceState& state){
    if (car.hasMandatoryHardStop() && state.totalLaps - state.currentLap < 15){
        return Compound::SOFT;
    }
    if(track.wearMultiplier >1.2 && state.totalLaps - state.currentLap >20){
        return Compound::HARD;
    }
    if(state.totalLaps - state.currentLap >25){
        return Compound::HARD;
    }
    else if(state.totalLaps - state.currentLap >12){
        return Compound::MEDIUM;
    }
    else{
       return Compound::SOFT;
    }
}

bool StrategyEngine::shouldPit(Car& car , const vector<Car>& allCars, const Track& track, const RaceState& state){
    if(state.totalLaps - state.currentLap <=1){
        return false;
    }
    if(car.inPit){
        return false;
    }
    if(state.scState != None){
        return shouldPitUnderSC(car , state);
    }
    if(isMandatoryStopUrgent(car , state)){
        return true;
    }
    if(isTireNearCliff(car.tire) && state.totalLaps - state.currentLap > 5){
        return true;
    }
    
    for (int i = 0  ; i < allCars.size() ; i++){
        if(allCars.at(i).position == car.position-1){
            if(shouldUndercutCarAhead(car, allCars.at(i), track, state)){
            return true;
            }
        }
    }

        
    return  estimatePitBenefit(car, track, state, chooseTireCompound(car, track, state)) > 0.3;
}