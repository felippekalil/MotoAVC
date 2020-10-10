/*
 Name:		MultiAVC.ino
 Created:	9/11/2020 3:09:05 PM
 Author:	Felippe Kalil Mendon�a
*/
#include <LiquidCrystal.h>
#include "MenusIni.h"
#include "IHMv2.h"

using namespace IHMv2;
constexpr uint16_t tLoop = 200;

Ihm ihm(tLoop);

void setup() {
    Serial.begin(9600);
    Serial.println("Inicializado!");
    ihm.setup();    
    ihm.atualizaMenu(Menus::menus[Menus::menuIhm]);
}

void loop() {
    if (millis() % tLoop == 0)
    {
        if(Menus::menuIhm != Menus::menuAnterior)
            ihm.atualizaMenu(Menus::menus[Menus::menuIhm]);
        Menus::menuAnterior = Menus::menuIhm;
        ihm.loop();
    }
}
