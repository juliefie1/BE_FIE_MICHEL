#include "core_simulation.h"
#include "myactuators.h"


int main(){
    // creation d'une board
    Board esp8266;
    // achat des senseurs et actionneurs
    AnalogSensorTemperature temperature(DELAY,TEMP);
    DigitalActuatorLED led1(DELAY);
    I2CActuatorScreen screen;
    AnalogSensorLuminosity luminosity(DELAY);
    IntelligentDigitalActuatorLED led2(DELAY);
    ExternalDigitalSensorButton button(DELAY);
    
    // branchement des capteurs actionneurs
    esp8266.pin(1,temperature);
    //esp8266.pin(0,led1);
    esp8266.i2c(1,screen);
    esp8266.pin(2, luminosity);
    esp8266.pin(3, led2);
    esp8266.pin(4, button);
    
    // allumage de la carte
    esp8266.run();
    return 0;
}


