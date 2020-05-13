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
    pinMode(3,OUTPUT);
    pinMode(4,INPUT);
}

// la boucle de controle arduino
void Board::loop(){
    char buf[100];
    int val1, val2, val3;
    static int cpt=0;
    static int bascule=0;
    int i=0;
    for(i=0;i<10;i++){
        // lecture sur la pin 1 : capteur de temperature
        val1=analogRead(1);
        // lecture sur la pin 2 : capteur de luminosité
        val2=analogRead(2);
        // lecture sur la pin 4 : bouton
        val3=analogRead(4);
        sprintf(buf,"temperature %d",val1);
        Serial.println(buf);
        sprintf(buf,"luminosité %d",val2);
        Serial.println(buf);
        sprintf(buf,"état du bouton %d", val3);
        Serial.println(buf);

        if(cpt%5==0){
            // tous les 5 fois on affiche sur l ecran la temperature
            sprintf(buf," %d °, %d LUX, bouton %d",val1, val2, val3);
            bus.write(1,buf,100);
        }

        // on eteint et on allume la LED intelligente
        if(cpt%3==0){
            if(bascule)
                digitalWrite(3,HIGH);
            else
                digitalWrite(3,LOW);
            bascule=1-bascule;
        }
        cpt++;
        sleep(1);
        sleep(2);
        sleep(4);
    }
}


