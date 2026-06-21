#include <iostream>
#include <algorithm>
#include "strategy.h"
#include "race.h"
#include "car.h"
#include "driver.h"
#include "track.h"
#include <random>


using namespace std;

Race::Race(const Track& track, vector<Car> cars){
    this -> track = track;
    this -> cars = cars;
    state.currentLap = 0;
    state.totalLaps = track.totalLaps;
    state.scState = None;
    rng = mt19937(random_device{}());
}

void Race::simulate() {
    cout << "\n=== " << track.name << " | " << track.totalLaps << " laps ===\n\n";
    for (int i = 1; i <= state.totalLaps; i++) {
        state.currentLap = i;
        simulateLap();
        if (i == 1 || i % 5 == 0 || i == state.totalLaps)
            printStandings();
    }
    printFinalResults();
}

void Race::simulateLap(){
    for(int i = 0 ; i< cars.size() ; i++){
        cars[i].inPit = false;
    }
    checkSafetyCar();
    handleRetirements();
    applyPitStops();
    simulateLapTimes();
    updatePositions();
    updateGaps();
}

void Race::checkSafetyCar(){
    if(state.scState != None && state.currentLap >= state.scEndLap){
        state.scState = None;
        cout << "Safety Car in" << endl;
    }
    else if(state.scState == None ){
        if(rollDice(track.scProbPerLap)== true){
            if(rollDice(0.4)){
                state.scState = VIRTUAL;
                state.scEndLap = state.currentLap + uniform_int_distribution<int>(3, 6)(rng);
                cout<< "VIRTUAL SAFETY CAR" << endl;
            }
            else{
                state.scState = FULL;
                state.scEndLap = state.currentLap + uniform_int_distribution<int>(3, 6)(rng);
                cout << "SAFETY CAR DEPLOYED" <<endl;
            }
        }
    }
}

void Race::handleRetirements(){
    for(int i = 0 ; i<cars.size() ; i++){
        if(not cars[i].retired){
            if(!rollDice(cars[i].teamPerf.reliability)){
                cars[i].retired = true;
                cout << "DNF" << endl;
            }
        }
    }
}

void Race::applyPitStops(){
    for(int i = 0 ; i< cars.size() ; i++){
        if(!cars[i].retired){

            if(StrategyEngine::shouldPit(cars[i], cars, track, state)==true){
                Compound comp =StrategyEngine::chooseTireCompound(cars[i] , track , state);
                cars[i].pit(comp);
                cars[i].completedStops.back().lap = state.currentLap;
                cars[i].totalRaceTime += track.pitLossTIme + cars[i].teamPerf.pitStopTime;
                cout << state.currentLap <<" " <<  "PIT:"<< " " << cars[i].driver.shortName << " " << cars[i].tire.name() <<" " <<  cars[i].completedStops.back().lap << endl;      
            }        
        }
    }
}

void Race::simulateLapTimes(){
    for(int i = 0 ; i <cars.size() ; i++){
        if(!cars[i].retired){
            float noise = randNormal(0.15f);
            float lapTime = cars[i].calcLapTime(track.baseLapTime, track.wearMultiplier, (state.scState != None), noise);
            cars[i].lastLapTime = lapTime;
            cars[i].totalRaceTime += lapTime;
            cars[i].tire.wearlap();
            cars[i].fuelLoad -= 1.8;
        }
    }
}

void Race::updatePositions(){
    sort(cars.begin() , cars.end() , [](const Car& a , const Car& b){
        if (!a.retired && b.retired)
        return true;

    if (a.retired && !b.retired)
        return false;

    return a.totalRaceTime < b.totalRaceTime;
    });
    for(int i = 0 ; i<cars.size() ; i++){
        cars[i].position = i +1;
    }
}

void Race::updateGaps(){
    cars[0].gapToLeader = 0;

    for(int i = 1 ; i< cars.size() ; i++){
        cars[i].gapToLeader = cars[i].totalRaceTime - cars[0].totalRaceTime;
        cars[i].gapToCarAhead = cars[i].totalRaceTime - cars[i-1].totalRaceTime;
    }
}

float Race::randNormal(float stddev){
normal_distribution<float> dist(0.0f, stddev);
return dist(rng);
}

bool Race::rollDice(float probability){
    uniform_real_distribution<float> dist(0.0f , 1.0f);
    if(dist(rng) < probability){
        return true;
    }
    else{
        return false;
    }
}

void Race::printStandings() {
    cout << "\nLAP " << state.currentLap << "/" << state.totalLaps << "\n";
    cout << "--------------------------------------------------\n";
    int shown = 0;
    for (int i = 0; i < (int)cars.size(); i++) {
        if (cars[i].retired) continue;
        if (++shown > 10) break;
        string gap;
        if (shown == 1) gap = "      LEADER";
        else {
            char buf[32];
            snprintf(buf, sizeof(buf), "+%9.3fs", cars[i].gapToLeader);
            gap = string(buf);
        }
        char buf[16];
        snprintf(buf, sizeof(buf), "%c:%2dL", cars[i].tire.abbreviation(), cars[i].tire.age);
        cout << " " << cars[i].position << ". "
             << cars[i].driver.shortName << " | "
             << buf << " | "
             << gap << " | "
             << cars[i].lastLapTime << "s\n";
    }
    cout << "\n";
}

void Race::printFinalResults() {
    cout << "\n=== RACE RESULT: " << track.name << " ===\n";
    cout << string(50, '=') << "\n";
    int pos = 1;
    for (int i = 0; i < (int)cars.size(); i++) {
        if (cars[i].retired) continue;
        string gap;
        if (pos == 1) gap = "       WINNER";
        else {
            char buf[32];
            snprintf(buf, sizeof(buf), "+%10.3fs", cars[i].gapToLeader);
            gap = string(buf);
        }
        string stops = "";
        for (int j = 0; j < (int)cars[i].completedStops.size(); j++) {
            if (!stops.empty()) stops += " -> ";
            string compStr;
            if (cars[i].completedStops[j].newCompound == Compound::SOFT) compStr = "S";
            else if (cars[i].completedStops[j].newCompound == Compound::MEDIUM) compStr = "M";
            else compStr = "H";
                stops += "L" + to_string(cars[i].completedStops[j].lap) + ":" + compStr;
        }
        if (stops.empty()) stops = "NO STOP";
        cout << " " << pos++ << ". "
             << cars[i].driver.shortName << " | "
             << gap << " | " << stops << "\n";
    }
    for (int i = 0; i < (int)cars.size(); i++) {
        if (cars[i].retired)
            cout << "DNF " << cars[i].driver.shortName
                 << " (" << cars[i].driver.team << ")\n";
    }
}