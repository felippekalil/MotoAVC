#include "MenuMensagem.h"

void MenuMensagem::atualizaLogo() const
{
	if (updateLogo == nullptr || logo.logoPtr == nullptr)
		return;
	updateLogo(logo);
}

MenuMensagem::MenuMensagem(const String& textoSuperior, const String& textoInferior, EnumMenus::Menus* menuAtual, const EnumMenus::Menus menuVoltar,
                           const Logo logo, const uint8_t logoSize, const uint8_t offset, const uint16_t tLoop) :
	tLoop(tLoop), pisca(tAceso, tApagado, tLoop)
{
	this->textoSuperior = textoSuperior;
	this->textoInferior = textoInferior;
	menuIhm = menuAtual;
	this->menuVoltar = menuVoltar;
	this->logo = logo;
	this->logoSize = logoSize;
	this->offset = offset;
}

void MenuMensagem::onMenuIni(void(*logoUpdate)(Logo logos))
{
	updateLogo = logoUpdate;
	atualizaLogo();
}


void MenuMensagem::onLoop()
{
	const auto imprime = pisca.aceso();
	if (imprime)
	{
		linhaSuperior = MenuExtensoes::LinhaBase::textoCenter(textoSuperior, offset);
		linhaInferior = MenuExtensoes::LinhaBase::textoCenter(textoInferior, offset);
	}
	else
	{
		linhaSuperior = MenuExtensoes::LinhaBase::limpa();
		linhaInferior = MenuExtensoes::LinhaBase::limpa();
	}
}

void MenuMensagem::onVoltar()
{
	*menuIhm = menuVoltar;
}