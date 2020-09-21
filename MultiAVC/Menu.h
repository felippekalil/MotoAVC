#pragma once
//#define MODO_CHAR
#ifndef _MENUS_h
	#define _MENUS_h

#include "Arduino.h"


namespace MenusEnum
{
	enum Menus
	{
		Principal = 0,
		Processos
	};
}

class Menu
{
	static void vazio() {}
	static void vazio(void (*)(uint8_t[][8], uint8_t)) {}
	static void vazio(MenusEnum::Menus) {}
public:
	Menu() = default;
	void(*onMenuIni)(void(*logoUpdate)(uint8_t logo[][8], uint8_t offset)) = vazio;
	void(*trocaMenu)(MenusEnum::Menus menuEnum) = vazio;
	void(*onLoop)() = vazio;
	void(*onEncdrDec)() = vazio;
	void(*onEncdrInc)() = vazio;
	void(*onClick)() = vazio;
	void(*onVoltar)() = vazio;
#ifdef MODO_CHAR
	char* linhaSuperior = "";
	char* linhaInferior = "";
#else
	String linhaSuperior = "";
	String linhaInferior = "";
#endif
};
#endif
