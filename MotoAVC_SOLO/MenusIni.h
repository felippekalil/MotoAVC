// MenusIni.h

#ifndef _MENUSINI_h
#define _MENUSINI_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Icones.h"
#include "MenuMensagem.h"
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
        uint8_t logoSize = 3, offsetLogo = 15 - logoSize - 1;
        Portal portalModo[] = {
            {"MOTOMAN",  {reinterpret_cast<uint8_t*>(&Icones::logoRobo), offsetLogo}, EnumMenus::Processos},
            { "CNC", {reinterpret_cast<uint8_t*>(&Icones::logoCnc), offsetLogo - 1}, EnumMenus::Obras},
            {"Step&Dir", {reinterpret_cast<uint8_t*>(&Icones::logoStepDir), offsetLogo}, EnumMenus::Obras}
        };
        uint8_t offset = -(logoSize + 1);
        MenuPortal menu("Modo", &menuIhmIndex, EnumMenus::Principal, 3, portalModo, logoSize, offset, tLoop);
    }

    namespace MenuProcessos
    {
        uint8_t logoSize = 3, offset = logoSize + 1, offsetLogo = 2;
        Portal portaisProc[] = {
            {"TIG", {reinterpret_cast<uint8_t*>(&Icones::logoTig), offsetLogo}, EnumMenus::Obras},
        	{"TIG HF", {reinterpret_cast<uint8_t*>(&Icones::logoTig), offsetLogo, reinterpret_cast<uint8_t*>(&Icones::charRaio), 2}, EnumMenus::Nada},
            {" MIG Conv.", {reinterpret_cast<uint8_t*>(&Icones::logoMig), offsetLogo, reinterpret_cast<uint8_t*>(&Icones::charCurto), 2 }, EnumMenus::Obras},
            {" MIG Puls.", {reinterpret_cast<uint8_t*>(&Icones::logoMig), offsetLogo, reinterpret_cast<uint8_t*>(&Icones::charPulse), 2 }, EnumMenus::Obras }};
        MenuPortal menu("Processo", &menuIhmIndex, EnumMenus::Principal, 4, portaisProc, logoSize, offset, tLoop);
    }

    namespace MenuEmObras
    {
        uint8_t logoSize = 3, offset = logoSize + 0, offsetLogo = 2;
        MenuBase::Logo logo;// = { reinterpret_cast<uint8_t*>(&Icones::logoMartelo), offsetLogo };
        MenuMensagem menu;// ("EM", "OBRAS!", &menuIhmIndex, logo, logoSize, offset, tLoop);

        inline void iniciaMenu()
        {
            logo = { reinterpret_cast<uint8_t*>(&Icones::logoMartelo), offsetLogo };
        	menu.ini("EM", "OBRAS!", &menuIhmIndex, logo, logoSize, offset, tLoop);
         }
    }

    //namespace MenuExecucao
    //{
    //    using namespace MenuExtensoes;
    //    uint8_t logoSize = 3, offset = logoSize + 1, offsetLogo = 0;
    //    float ref = 0, zm = 0;

    //    AdjGenerico<float> referencia = { &ref, 0.1, 99.9, 0.1 };
    //    LinhaValor<float> linhaRef = { "Ref: ", referencia, 1, 2, "V" };
    //    AdjGenerico<float> zonaMorta = { &zm, 0.1, 99.9, 0.1 };
    //    LinhaValor<float> linhaZM = { "Z.M.: ", zonaMorta, 1, 2, "V" };
    //    LinhaValor<float> linhas[] = { linhaRef, // 0
    //    								linhaZM }; // 1

    //    Portal portaisProc[] = {
    //        {"TIG", {reinterpret_cast<uint8_t*>(&Icones::logoTig), offsetLogo}, EnumMenus::Obras},
    //        {"TIG HF", {reinterpret_cast<uint8_t*>(&Icones::logoTig), offsetLogo}, EnumMenus::Nada}};
    //    MenuPortal menu("Processo", &menuIhmIndex, EnumMenus::Principal, 4, portaisProc, logoSize, offset, tLoop);
    //}

    inline void iniciaMenus()
    {
        MenuEmObras::iniciaMenu();
    }

    MenuBase* menus[3] = { &MenuPrincipal::menu , &MenuProcessos::menu, &MenuEmObras::menu };//*/	
}

#endif

