// 
// 
// 

#include "Menus.h"


void MenusClass::iniciaMenuProc()
{
    const auto logoSize = 3, offset = logoSize + 1, offsetLogo = 2;
    portaisProc[0] = { "TIG HF", {reinterpret_cast<uint8_t*>(&Icones::logoTig), offsetLogo, reinterpret_cast<uint8_t*>(&Icones::charRaio), 2}, Execucao };
    portaisProc[1] = { "TIG", {reinterpret_cast<uint8_t*>(&Icones::logoTig), offsetLogo}, Obras };
    portaisProc[2] = { " MIG Conv.", {reinterpret_cast<uint8_t*>(&Icones::logoMig), offsetLogo, reinterpret_cast<uint8_t*>(&Icones::charCurto), 2 }, Obras };
    portaisProc[3] = { " MIG Puls.", {reinterpret_cast<uint8_t*>(&Icones::logoMig), offsetLogo, reinterpret_cast<uint8_t*>(&Icones::charPulse), 2 }, Obras };
    menuProcessos.ini("Processo", &menuIhmIndex, Processos, 4, portaisProc, logoSize, offset, tLoop);
}

void MenusClass::iniciaMenuObras()
{
    const auto logoSize = 3, offset = logoSize + 0, offsetLogo = 2;
    logoObras = { reinterpret_cast<uint8_t*>(&Icones::logoMartelo), offsetLogo };
    menuEmObras.ini("EM", "OBRAS!", &menuIhmIndex, logoObras, logoSize, offset, tLoop);
}

void MenusClass::atualizaCharExec()
{

}

void MenusClass::iniciaMenuExec()
{
    AdjGenerico<float>  referencia = { &ref, 0.1, 99.9, 0.1, false };
    AdjGenerico<float> zonaMorta = { &zm, 0.1, 99.9, 0.1, false };
    linhas[0] = { "Ref: ", referencia, 1, 4, "V" };
    linhas[1] = { "Z.M: ", zonaMorta, 1, 4, "V" };
    linhas[2] = { " In: ", ref, 1, 4, "V" };
    const auto logoSize = 3, offset = logoSize + 1, offsetLogo = 0;
    logoExec = { reinterpret_cast<uint8_t*>(&Icones::logoTig), offsetLogo };
    menuExecucao.ini(&menuIhmIndex, logoExec, linhas, 3, atualizaCharExec, logoSize, offset, tLoop);
}

MenusClass::MenusClass()
{
     menus[Processos] = &menuProcessos;
     menus[Obras] = &menuEmObras;
     menus[Execucao] = &menuExecucao;
}

void MenusClass::init(int tLoop)
{
    iniciaMenuProc();
    iniciaMenuObras();
    iniciaMenuExec();
}


MenusClass Menus;

