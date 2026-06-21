#pragma once
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

enum Compound{
    SOFT ,
    MEDIUM ,
    HARD ,
    INTER ,
    WET,
};

class Tire{
    public:
    Compound compound;
    int age;
    
    explicit Tire(Compound c) : compound(c), age(0) {}

    void wearlap(){
        age ++;
    }

    float degPenalty() const{
        double penalty = 0.0;
        int cliff =cliffLap();
        double base = baseWearRate();
        if (age < cliff){
            penalty = age * base;
        }
        else {
            penalty = cliff * base + pow(age - cliff, 1.8) * 0.04;

        }
        return penalty;
    }

    float grip() const{
        double g = 1.0- degPenalty();
        if (g < 0.4){
            g = 0.4;
        }
        if (g>1.0){
            g = 1.0;
        }
        return static_cast<float>(g);
    }

    string name() const{
        switch(compound){
            case Compound::SOFT:
            return "SOFT";

            case Compound::MEDIUM:
            return "MEDIUM";
            
            
            case Compound::HARD:
            return "HARD";
        

            case Compound::INTER:
            return "INTER";

            case Compound::WET:
            return "WET";

            default:
            return "UNKNOWN";
        }
    }

    char abbreviation() const{

        switch(compound){
            case Compound::SOFT:
            return 'S';

            case Compound::MEDIUM:
            return 'M';
            
            
            case Compound::HARD:
            return 'H';
        

            case Compound::INTER:
            return 'I';

            case Compound::WET:
            return 'W';
            
            default:
            return '?';
        }

    }

    int cliffLap() const{
        switch(compound){
            case Compound::SOFT:
            return 12;
            
            case Compound::MEDIUM:
            return 22;
            
            
            case Compound::HARD:
            return 35;
        

            case Compound::INTER:
            return 20;

            case Compound::WET:
            return 30;

            default:
            return 20;

        }

    }
    private:

    double baseWearRate() const{
         switch(compound){
            case Compound::SOFT:
            return 0.08;
            
            case Compound::MEDIUM:
            return 0.05;
            
            
            case Compound::HARD:
            return 0.03;
        

            case Compound::INTER:
            return 0.06;

            case Compound::WET:
            return 0.04;

            default:
            return 0.05;

        }
    }

};