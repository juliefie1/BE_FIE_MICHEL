//
//  mysensors.hpp
//  BE
//
//  Created by Julie Fié on 20/05/2020.
//  Copyright © 2020 Julie Fié. All rights reserved.
//

#ifndef mysensors_hpp
#define mysensors_hpp

#include <stdio.h>
#include <iostream>
#include <thread>
#include <unistd.h>
#include <string.h>
#include "core_simulation.h"
#include <fstream>


// Capteur de la température extérieure
class AnalogSensorTemperature: public Device {
private:
    // fait osciller la valeur du capteur de 1
    int alea;
    // valeur de temperature mesuree
    int val;
    // temps entre 2 prises de valeurs
    int temps;
    
public:
    //constructeur ne pas oublier d'initialiser la classe mere
    AnalogSensorTemperature(int d,int  t);
    // thread representant le capteur et permettant de fonctionner independamment de la board
    virtual void run();
};

// Capteur de la luminosité extérieure
class AnalogSensorLuminosity: public Device {
private:
    // fait osciller la valeur du capteur de 1
    int alea;
    // valeur de temperature mesuree
    int val;
    // temps entre 2 prises de valeurs
    int temps;
    
public:
    AnalogSensorLuminosity(int d);
    // thread representant le capteur et permettant de fonctionner independamment de la board
    virtual void run();
};


#endif /* mysensors_hpp */
