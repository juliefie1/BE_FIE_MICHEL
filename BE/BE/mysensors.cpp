//
//  mysensors.cpp
//  BE
//
//  Created by Julie Fié on 20/05/2020.
//  Copyright © 2020 Julie Fié. All rights reserved.
//

#include "mysensors.hpp"

//classe AnalogSensorTemperature
AnalogSensorTemperature::AnalogSensorTemperature(int d,int  t):Device(),val(t),temps(d){
    alea=1;
}

void AnalogSensorTemperature::run(){
    while(1){
        alea=1-alea;
        if(ptrmem!=NULL)
            *ptrmem=val+alea;
        sleep(temps);
    }
}
