#pragma once
#include <string>
#include <cmath>
#include <vector>
#include <random>
#include "car.h"
#include "tire.h"
#include "track.h"
#include "strategy.h"

using namespace std;

class Race{
    public:
    Track track;
    vector<Car> cars;
    RaceState state;
    mt19937 rng;
    random_device rand;
    void printStandings();
    void printFinalResults();

    Race(const Track& track, vector<Car> cars);
    void simulate();

    private:
    void simulateLap();
    void checkSafetyCar();
    void applyPitStops();
    void simulateLapTimes();
    void handleRetirements();
    void updatePositions();
    void updateGaps();
    float randNormal(float stddev);
    bool rollDice(float probability);


};