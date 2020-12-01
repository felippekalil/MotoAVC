#pragma once

#include <LiquidCrystal.h>
#include "MenuBase.h"
#ifndef _IHMV2_H
	#define _IHMV2_H

namespace IHMv2
{
	inline void pause() { while (true) {} }

	class Ihm
	{
		const int encoderPinA = 2;
		const int encoderPinB = 4;
		const int buzzer = 11;
		uint16_t tempoBuzzerInc;
		const int SWITCH = 3;
		uint16_t tempoVoltar;
		uint16_t tempoAguardaMenu;
		const uint16_t duracaoBuzzer = 50;
		const uint16_t duracaoVoltar = 600;
		const uint16_t duracaoAguardaMenu = 600;
		byte(*logoIni)[8];

		const int rs = A4, en = A5, d4 = A0, d5 = A1, d6 = A2, d7 = A3;
		LiquidCrystal lcd;
		static Ihm* instancia;
		volatile uint16_t aguardaMenu = 0, apitaBuzzer = 0, freqBuzzer = 0, clickVoltar = 0;
		volatile uint8_t modoBuzzer = 0;
		uint8_t nCharLogo = 0, offsetLogo = 0;

		static void setFreqBuzzer(uint8_t nFreq);

		void apitarBuzzerInc();

		void apitarBuzzerEnter();

		void apitarBuzzerVoltar();

		void processaBuzzer();

		void handleEncoder();

		void handleSwitch();

		void imprimeInterface();

		MenuBase* menuAtual{};

	public:
		explicit Ihm(uint16_t tLoop);
		explicit Ihm(MenuBase* menu, uint16_t tLoop);

		void atualizaMenu(MenuBase* menu);

		bool varAjustadas() const;

		void imprimeLogo();

		void createChar(uint8_t index, uint8_t customChar[]);

		void createLogo(MenuBase::Logo logo);

		void telaInicialLabsolda();

		void setup();

		void loop();
	};
}
#endif