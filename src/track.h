#pragma once
#include <string>
#include <cmath>
#include <vector>
using namespace std;

struct Track{
    string name;
    string location;
    int totalLaps;
    float trackLength;
    float baseLapTime;
    float pitLossTIme;
    float wearMultiplier;
    float overtakingDifficulty;
    float scProbPerLap;
};

inline vector<Track> get2024Calendar(){
    vector<Track> tracks;

    Track t1 = {"Bahrain GP", "", 57, 5.412, 93.0, 22, 1.2, 1.0, 0.04};
    tracks.push_back(t1);

    Track t2 = {"Saudi Arabian GP", "", 50, 6.174, 90.0, 23, 0.8, 0.86, 0.06};
    tracks.push_back(t2);

    Track t3 = {"Australian GP", "", 58, 5.278, 81.0, 26, 1.0, 1.0, 0.07};
    tracks.push_back(t3);

    Track t4 = {"Japanese GP", "", 53, 5.807, 92.0, 24, 1.3, 1.1, 0.03};
    tracks.push_back(t4);

    Track t5 = {"Chinese GP", "", 56, 5.451, 93.0, 25, 1.1, 0.9, 0.05};
    tracks.push_back(t5);

    Track t6 = {"Miami GP", "", 57, 5.412, 91.0, 24, 1.0, 1.0, 0.05};
    tracks.push_back(t6);

    Track t7 = {"Emilia Romagna GP", "", 63, 4.909, 77.0, 25, 1.1, 1.3, 0.04};
    tracks.push_back(t7);

    Track t8 = {"Monaco GP", "", 78, 3.337, 74.0, 22, 0.7, 2.5, 0.06};
    tracks.push_back(t8);

    Track t9 = {"Canadian GP", "", 70, 4.361, 75.0, 23, 0.9, 0.9, 0.08};
    tracks.push_back(t9);

    Track t10 = {"Spanish GP", "", 66, 4.657, 80.0, 24, 1.4, 1.2, 0.03};
    tracks.push_back(t10);

    Track t11 = {"Austrian GP", "", 71, 4.318, 67.0, 24, 1.3, 0.9, 0.05};
    tracks.push_back(t11);

    Track t12 = {"British GP", "", 52, 5.891, 88.0, 24, 1.2, 1.0, 0.05};
    tracks.push_back(t12);

    Track t13 = {"Hungarian GP", "", 70, 4.381, 80.0, 24, 1.2, 1.4, 0.04};
    tracks.push_back(t13);

    Track t14 = {"Belgian GP", "", 44, 7.004, 106.0, 24, 1.1, 0.9, 0.06};
    tracks.push_back(t14);

    Track t15 = {"Dutch GP", "", 72, 4.259, 72.0, 24, 1.3, 1.5, 0.04};
    tracks.push_back(t15);

    Track t16 = {"Italian GP", "", 53, 5.793, 80.0, 25, 0.8, 0.8, 0.04};
    tracks.push_back(t16);

    Track t17 = {"Azerbaijan GP", "", 51, 6.003, 103.0, 24, 0.9, 0.9, 0.08};
    tracks.push_back(t17);

    Track t18 = {"Singapore GP", "", 62, 4.940, 96.0, 24, 1.0, 1.6, 0.06};
    tracks.push_back(t18);

    Track t19 = {"US GP (COTA)", "", 56, 5.513, 96.0, 24, 1.1, 1.0, 0.05};
    tracks.push_back(t19);

    Track t20 = {"Mexico City GP", "", 71, 4.304, 79.0, 24, 1.0, 1.0, 0.04};
    tracks.push_back(t20);

    Track t21 = {"São Paulo GP", "", 71, 4.309, 72.0, 23, 1.0, 0.9, 0.07};
    tracks.push_back(t21);

    Track t22 = {"Las Vegas GP", "", 50, 6.120, 96.0, 24, 0.8, 0.8, 0.05};
    tracks.push_back(t22);

    Track t23 = {"Qatar GP", "", 57, 5.419, 83.0, 24, 1.2, 0.9, 0.04};
    tracks.push_back(t23);

    Track t24 = {"Abu Dhabi GP", "", 58, 5.281, 86.0, 24, 0.9, 1.0, 0.03};
    tracks.push_back(t24);

    return tracks;
};