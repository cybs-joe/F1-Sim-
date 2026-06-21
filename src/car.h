#pragma once
#include <string>
#include <cmath>
#include <vector>
#include <random>
#include "driver.h"
#include "tire.h"
using namespace std;

struct TeamPerf{
    string name;
    float carPace;
    float pitStopTime;
    float reliability;
};

inline TeamPerf getTeamPerf(string teamName){
    if (teamName == "Red Bull"){
        return TeamPerf{"Red Bull" , -0.6 , 2.4 , 0.998};
    }
    else if(teamName == "Ferrari"){
        return TeamPerf{"Ferrari" , -0.4 , 2.5 , 0.997};
    }
    else if(teamName == "McLaren"){
        return TeamPerf{"McLaren" , -0.5 , 2.3 , 0.998};
    }
    else if(teamName == "Mercedes"){
        return TeamPerf{"Mercedes" , -0.3 , 2.6 , 0.997};
    }
    else if(teamName == "Aston Martin"){
        return TeamPerf{"Aston Martin" , -0.1 , 2.7 , 0.996};
    }
    else if(teamName == "RB"){
        return TeamPerf{"RB" , +0.3 ,2.8 , 0.995};
    }
    else if(teamName == "Alpine"){
        return TeamPerf{"Alpine" , +0.4 , 2.9 , 0.994 };
    }
    else if(teamName == "Williams"){
        return TeamPerf{"Williams" , +0.5 , 3.0 , 0.994};
    }
    else if(teamName == "Haas"){
        return TeamPerf{"Haas" , +0.5 , 3.1 , 0.993};
    }
    else if(teamName == "Kick Sauber"){
        return TeamPerf{"Kick Sauber" , +0.7 , 3.2 , 0.992};
    }
    else{
        return TeamPerf{};
    }
}

struct PitStop{
    int lap;
    Compound newCompound;
};

class Car{
    public:
    Driver driver;
    TeamPerf teamPerf;
    Tire tire;
    float fuelLoad;
    float gapToLeader;
    float gapToCarAhead;
    int position;
    bool retired;
    bool inPit;
    float lastLapTime;
    float totalRaceTime;
    Car(): tire(Compound::SOFT){};
    vector<PitStop> completedStops;

   float calcLapTime(float baseLapTime, float wearMultiplier, bool underSC, float noise) const{
        double tire_mgmt_factor = 1.0 - (driver.tireManagement - 70.0) / 300.0;
         noise = (100 - driver.consistency) / 2000.0;

        if (underSC == true){
            return baseLapTime +15.0;
        }
        else{
        double lapTime = baseLapTime + teamPerf.carPace + tire.degPenalty()* wearMultiplier * tire_mgmt_factor + fuelLoad * 0.03 -(driver.pace - 80.0)/40.0 + noise;
        return lapTime;
        }
    }
    void pit(Compound newCompound){
        inPit = true;
        tire = Tire(newCompound);
        
        PitStop stop;
        stop.lap = 0;
        stop.newCompound = newCompound;
        completedStops.push_back(stop);
    }
    bool hasMandatoryHardStop() const{
        bool softUsed , mediumUsed , hardUsed;
        int drycounter = 0; 
        softUsed = false;
        mediumUsed = false;
        hardUsed = false;

        
        if (tire.compound == Compound::SOFT){
            softUsed = true;
        } 
        else if (tire.compound == Compound::MEDIUM){
            mediumUsed = true;
        }
        else if (tire.compound == Compound::HARD){
            hardUsed = true;
        }
        for (int i =0 ; i< completedStops.size() ; i++){
    
            if (completedStops[i].newCompound == Compound::SOFT){
                softUsed = true;
            }
            else if (completedStops[i].newCompound == Compound::MEDIUM){
                mediumUsed = true;
               
            }
            else if (completedStops[i].newCompound == Compound::HARD){
                hardUsed = true;
                
            }
        }
        if(softUsed){
            drycounter++;
        }
        if(mediumUsed){
            drycounter++;
        }
        if(hardUsed){
            drycounter++;
        }
        return drycounter <2;
        
    }
};
