/*
 Name:		MotoAVC_SOLO.ino
 Created:	11/26/2020 8:55:52 PM
 Author:	Kalil
*/

#define TLOOP 50

#include <LiquidCrystal.h>
#include "MenusIni.h"
#include "IHMv2.h"

using namespace IHMv2;
using namespace Menus;

Ihm ihm(TLOOP);

void setup() {
    Serial.begin(9600);
    Serial.println("Inicializado!");
    tLoop = TLOOP;
    ihm.setup();
    ihm.atualizaMenu(menus[menuIhmIndex]);
}

void loop() {
    if (millis() % TLOOP == 0)
    {
        if (menuIhmIndex != menuIndexAnterior)
            ihm.atualizaMenu(menus[menuIhmIndex]);
        menuIndexAnterior = menuIhmIndex;
        ihm.loop();
    }
}