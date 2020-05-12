#include <unistd.h>
#include "core_simulation.h"

// la fonction d'initialisation d'arduino
void Board::setup(){
    // on configure la vitesse de la liaison
    Serial.begin(9600);
    // on fixe les pin en entree et en sorite en fonction des capteurs/actionneurs mis sur la carte
    pinMode(1,INPUT);
    pinMode(0,OUTPUT);
    pinMode(2,INPUT);
}

// la boucle de controle arduino
void Board::loop(){
    char buf[100];
    int val1, val2;
    static int cpt=0;
    static int bascule=0;
    int i=0;
    for(i=0;i<10;i++){
        // lecture sur la pin 1 : capteur de temperature
        val1=analogRead(1);
        // lecture sur la pin 2 : capteur de luminosité
        val2=analogRead(2);
        sprintf(buf,"temperature %d",val1);
        Serial.println(buf);
        if(cpt%5==0){
            // tous les 5 fois on affiche sur l ecran la temperature
            sprintf(buf,"%d",val1);
            bus.write(1,buf,100);
        }
        sprintf(buf,"luminosité %d",val2);
        Serial.println(buf);
        if(cpt%5==0){
            // tous les 5 fois on affiche sur l ecran la luminosité
            sprintf(buf,"%d",val2);
            bus.write(1,buf,100);
        }
        cpt++;
        sleep(1);
        sleep(2);        
        
    }
    // on eteint et on allume la LED
    if(bascule)
        digitalWrite(0,HIGH);
    else
        digitalWrite(0,LOW);
    bascule=1-bascule;
}


