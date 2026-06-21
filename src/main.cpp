#include <iostream>
#include <algorithm>
#include "strategy.h"
#include "race.h"
#include "car.h"
#include "driver.h"
#include "track.h"
#include "tire.h"
#include <random>
using namespace std;

int main(){
    vector<Driver> grid = get2024Grid();
    vector <Track> calender =  get2024Calendar();

    for(int i = 0 ; i< calender.size() ; i++){
        cout << i+1 << " " << calender[i].name << endl;
    }
    int choice ;
    cout << "enter a number to select a track";
    cin >> choice;
    Track selectedTrack = calender[choice - 1];

    vector <Car> cargrid;
    for(int i = 0 ; i < grid.size() ; i++){
        Car car;
        car.driver = grid[i];
        car.teamPerf = getTeamPerf(grid[i].team);
        car.position = i + 1;
        if(i <10){
            car.tire = Tire(Compound::MEDIUM);
        }
        else{
            car.tire = Tire(Compound::HARD);
        }
        car.fuelLoad = selectedTrack.totalLaps * 1.8;
        cargrid.push_back(car);
    }
    Race race (selectedTrack,cargrid);
    race.simulate();
}