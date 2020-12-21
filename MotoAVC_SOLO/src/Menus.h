// Menus.h

#ifndef _MENUS_h
#define _MENUS_h

#include "Icones.h"
#include "MenuMensagem.h"
#include "MenuPortal.h"
#include "MenuLinhas.h"
#include "ControleAVC.h"

class MenusClass
{
	uint16_t tLoop = 50;
	Portal portaisProc[4];
	MenuPortal menuProcessos;
	void iniciaMenuProc();

	MenuBase::Logo logoObras{};
	MenuMensagem menuEmObras;
	void iniciaMenuObras();

	MenuBase::Logo logoExec{};
	const int nLinhasProc = 5;
	LinhaValor<float> linhas[5];
	void atualizaCharExec();
	MenuLinhas menuExecucao;
	void iniciaMenuExec();

public:
	MenusClass();
	void init(int tLoop);
	EnumMenus menuIhmIndex = Processos;
	EnumMenus menuIndexAnterior = Processos;
	MenuBase* menus[3]{};
	static MenusClass* pntExterno;

	int* linhasMenuExec();
};

extern MenusClass Menus;

#endif

