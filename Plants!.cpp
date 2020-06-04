//
//  Plants!.cpp
//  std_lib_facilities_mac
//
//  Created by Viroshaan Uthayamoorthy on 25/04/2019.
//  Copyright © 2019 Lars Musaus. All rights reserved.
//

#include "Plants!.hpp"

float readSensor(int id){
    return id;
}

void sleep(int seconds){
}

float plant::readHumidity(){
    humidity = readSensor(sensorId);
    return readSensor(sensorId);
}

PlantStatus plant::getstatus(){
    if (humidity > humidityMin and humidity < humidityMax){
        return PlantStatus::HAPPY_PLANT;
    } else if (humidity < humidityMin){
        return PlantStatus::WATER_LOW;
    } else if (humidity > humidityMax){
        return PlantStatus::WATER_HIGH;
    }
    if (sensorId == -1){
        return PlantStatus::SENSOR_ERROR;
    }
    return HAPPY_PLANT;
}

bool plant::operator ==(plant& rhs){
    if (sensorId == rhs.sensorId){
        return true;
    }
    return false;
}

void garden::addPlant(plant p){
    plants.push_back(p);
}

void garden::removePlant(plant p){
    for (auto i = plants.begin() ; i != plants.end(); ++i){
        if(*i == p){
            plants.erase(i);
        }
    }
}

vector<plant> garden::needsHelp(){
    vector<plant> needhelp;
    for(auto i: plants){
        if (i.getstatus() != PlantStatus::HAPPY_PLANT){
            needhelp.push_back(i);
        }
    }
    return needhelp;
}

string enumtransform(PlantStatus ps){
    if (ps == HAPPY_PLANT){
        return "HAPPY_PLANT";
    } else if (ps == WATER_LOW){
        return "WATER_LOW";
    } else if (ps == WATER_HIGH){
        return "WATER_HIGH";
    } else{
        return "SENSOR ERROR";
    }
}

void garden::monitor(int interval){
    vector<plant> needhelp;
    while (1==1){
        needhelp = needsHelp();
        for (auto i: needhelp){
            cout << i << " : " << enumtransform(i.getstatus()) << endl;
        }
        sleep(interval);
    }
}
