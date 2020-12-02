// MenusIni.h

#ifndef _MENUSINI_h
#define _MENUSINI_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Icones.h"
#include "MenuPortal.h"

namespace Menus
{
#ifdef TLOOP
    uint16_t tLoop = TLOOP;
#else
    uint16_t tLoop = 50; // lembrar de ajustar no .ino
#endif

    EnumMenus::Menus menuIhmIndex = EnumMenus::Menus::Principal;
    EnumMenus::Menus menuIndexAnterior = EnumMenus::Menus::Principal;

    namespace MenuPrincipal
    {
        String enumModo[] = { "MOTOMAN","CNC", "Step&Dir" };
        uint8_t logoSize = 3, offsetLogo = 15 - logoSize - 1;
        MenuBase::Logo logos[] = {
	        { reinterpret_cast<byte*>(&Icones::logoRobo), offsetLogo}, 
        	{reinterpret_cast<byte*>(&Icones::logoCnc), offsetLogo - 1},
        	{reinterpret_cast<byte*>(&Icones::logoStepDir), offsetLogo}
        };
        uint8_t offset = -(logoSize + 1);
        MenuPortal menu("Modo", &menuIhmIndex, EnumMenus::Principal, 3, enumModo, logos, logoSize, offset, tLoop);
    }

    namespace MenuProcessos
    {
        String enumProcesso[] = { "TIG","TIG HF", " MIG Conv.", " MIG Puls." };
        byte* logos[] = { 
        	reinterpret_cast<byte*>(&Icones::logoTig), 
        	reinterpret_cast<byte*>(&Icones::logoTigHf), 
            reinterpret_cast<byte*>(&Icones::logoMigConv),
            reinterpret_cast<byte*>(&Icones::logoMigPulse) };
        uint8_t logoSize = 3, offset = logoSize + 1, offsetLogo = 2;
        MenuPortal menu("Processo", &menuIhmIndex, EnumMenus::Principal, 4, enumProcesso, logos, logoSize, offset, offsetLogo, tLoop);	    
    }

    MenuBase* menus[2] = { &MenuPrincipal::menu , &MenuProcessos::menu };//*/	
}

#endif

