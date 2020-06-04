//
//  Plants!.hpp
//  std_lib_facilities_mac
//
//  Created by Viroshaan Uthayamoorthy on 25/04/2019.
//  Copyright © 2019 Lars Musaus. All rights reserved.
//

#ifndef Plants__hpp
#define Plants__hpp

#include <stdio.h>

#endif /* Plants__hpp */
#include "std_lib_facilities.h"

enum PlantStatus{
    HAPPY_PLANT, WATER_LOW, WATER_HIGH, SENSOR_ERROR
};

class plant{
private:
    string name;
    string location;
    int sensorId;
    float humidityMin;
    float humidityMax;
    float humidity;
public:
    void setname(string name1){name  = name1;}
    string getname(){return name;}
    plant(string name, string location, int sensorId, float humidityMin, float humidityMax):
    name{name}, location{location}, sensorId{sensorId}, humidityMin{humidityMin}, humidityMax{humidityMax}, humidity{-1.0}{}
    float readHumidity();
    PlantStatus getstatus();
    bool operator ==(plant& rhs);
    friend ostream &operator<<(ostream& out, plant &p){
        out << p.name << " @ " << p.location;
        return out;
    }
};

class garden{
    string name;
    vector<plant> plants;
public:
    garden(string name):name{name}{}
    void addPlant(plant p);
    void removePlant(plant p);
    vector<plant>needsHelp();
    void monitor(int interval);
};

