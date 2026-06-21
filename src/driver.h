#pragma once
#include <string>
#include <cmath>
#include <vector>
using namespace std;

struct Driver{
    string name;
    string shortName;
    string team;
    int number;
    float pace;
    float tireManagement;
    float racecraft;
    float consistency;
};

inline vector<Driver> get2024Grid(){
    vector<Driver> drivers;
    Driver d1 = {"Max Verstappen" , "VER" , "Red Bull" ,1, 99 , 95 , 98 , 97};
    drivers.push_back(d1);

    Driver d2 = {"Sergio Perez" , "PER" , "Red Bull" , 11 , 88 , 85 , 84 , 82};
    drivers.push_back(d2);

    Driver d3= {"Lewis Hamilton" , "HAM" , "Mercedes" , 44 , 93 , 90 , 96 , 91};
    drivers.push_back(d3);

    Driver d4 = {"George Russell" , "RUS" , "Mercedes" , 63 , 89 , 82 , 86 , 88};
    drivers.push_back(d4);

    Driver d5 = {"Charles Leclerc" , "LEC" , "Ferrari" , 16 , 95 , 80 , 90 , 87};
    drivers.push_back(d5);

    Driver d6 = {"Carlos Sainz" , "SAI" , "Ferrari" , 55 , 90 , 88 , 89 , 90 };
    drivers.push_back(d6);
    
    Driver d7 = {"Lando Norris" , "NOR" , "McLaren" , 4,  93 , 85 , 91 , 89 };
    drivers.push_back(d7);

    Driver d8 = {"Oscar Piastri" , "PIA" , "McLaren" , 81 , 88 , 86 , 85 ,88};
    drivers.push_back(d8);

    Driver d9 = {"Fernando Alonso" , "ALO" , "Aston Martin" , 14 , 91 , 95 , 94 , 92};
    drivers.push_back(d9);

    Driver d10 = {"Lance Stroll" , "STR" , "Aston Martin" , 18 , 78 , 75 , 74 ,76};
    drivers.push_back(d10);

    Driver d11 = {"Pierre Gasly" , "GAS" , "Alpine" , 10 , 83 , 80 , 82 , 81};
    drivers.push_back(d11);

    Driver d12 = {"Esteban Ocon" , "OCO" , "Alpine" , 31 , 81 , 78 ,79 ,80};
    drivers.push_back(d12);

    Driver d13 = {"Yuki Tsunoda" , "TSU" , "RB" , 22, 82 , 74 , 80 , 77};
    drivers.push_back(d13);

    Driver d14 = {"Daniel Ricciardo" , "RIC" , "RB" , 3 , 83 , 80 , 85 ,78};
    drivers.push_back(d14);

    Driver d15 = {"Valtteri Bottas" , "BOT" , "Kick Sauber" , 77 , 82 , 82 ,80 ,81};
    drivers.push_back(d15);


    Driver d16 ={"Zhou Guanyu" , "ZHO" , "Kick Sauber" , 24 , 76 , 74 ,72 ,75};
    drivers.push_back(d16);

    Driver d17 = {"Kevin Magnussen" , "MAG" , "Haas" , 20  ,78  , 72 , 79 , 74};
    drivers.push_back(d17);

    Driver d18 = {"Nico Hulkenberg" , "HUL" , "Haas" , 27 , 80 , 78 , 78  ,79};
    drivers.push_back(d18); 

    Driver d19 = {"Alexander Albon" , "ALB" , "Williams" , 23, 82 , 80 , 80 , 81};
    drivers.push_back(d19);

    Driver d20 = {"Logan Sargeant" , "SAR" , "Williams" , 2 ,72 , 68 , 68 , 69};
    drivers.push_back(d20);

    return drivers;
};