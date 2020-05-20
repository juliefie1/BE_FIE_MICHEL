
#include "myactuators.h"
static volatile int luminosite_environnement = 200;

using namespace std;

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

//classe DigitalActuatorLED
DigitalActuatorLED::DigitalActuatorLED(int t):Device(),state(LOW),temps(t){
}

void DigitalActuatorLED::run(){
    while(1){
        if(ptrmem!=NULL)
            state=*ptrmem;
        if (state==LOW)
            cout << "***éteint***\n";
        else
            cout << "***allumé***\n";
        sleep(temps);
    }
}

// classe I2CActuatorScreen
I2CActuatorScreen::I2CActuatorScreen ():Device(){
}

void I2CActuatorScreen::run(){
    while(1){
        if ( (i2cbus!=NULL)&&!(i2cbus->isEmptyRegister(i2caddr))){
            Device::i2cbus->requestFrom(i2caddr, buf, I2C_BUFFER_SIZE);
            cout << "--- SCREEN :"<< buf << endl;
        }
        sleep(1);
    }
}

//classe AnalogSensorTemperature
AnalogSensorLuminosity::AnalogSensorLuminosity(int d):Device(),val(luminosite_environnement),temps(d){
    alea=1;
}

void AnalogSensorLuminosity::run(){
    while(1){
        alea=1-alea;
        if(ptrmem!=NULL)
            *ptrmem=luminosite_environnement+alea;
        sleep(temps);
    }
}

//classe IntelligentDigitalActuatorLED
IntelligentDigitalActuatorLED::IntelligentDigitalActuatorLED(int t):Device(),state(LOW),temps(t){
}

void IntelligentDigitalActuatorLED::run(){
    int previous_state;
    while(1){
        previous_state = state;
        if(ptrmem!=NULL){
            state=*ptrmem;
        }
        if (state==LOW){
            if (previous_state == HIGH)
                luminosite_environnement -= 50;
            cout << "***éteint***\n";
        }
        else{
            if (previous_state == LOW)
                luminosite_environnement += 50;
            cout << "***allumé***\n";
        }
        sleep(temps);
    }
}

ExternalDigitalSensorButton::ExternalDigitalSensorButton(int t){
    Device();
    temps = t;
    if(ifstream("on.txt"))
        state = HIGH;
    else
        state = LOW;
}

void ExternalDigitalSensorButton::run(){
    while(1){
        if(ptrmem!=NULL)
            *ptrmem=state;
        sleep(temps);
    }
}


