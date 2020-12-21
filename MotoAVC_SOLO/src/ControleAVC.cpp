// 
// 
// 

#include "ControleAVC.h"

ControleAVC Controle;

float ControleAVC::leTensaoArco() const
{
	return static_cast<float>(500.0 * (analogRead(tensaoDoArco)) / (11264.0));
}

void ControleAVC::setupControle() const
{
	pinMode(tensaoDoArco, INPUT);
	pinMode(saidaComarc, OUTPUT);
}

void ControleAVC::setaSaida(const float leitura)
{
	valorSaida = leitura * (-5) / (2 * referencia) + 5;

	if (valorSaida < 0)
		valorSaida = 0;
	if (valorSaida > 5)
		valorSaida = 5;
	valorSaidaCorrente = valorSaida * 100;
	analogWrite(saidaComarc, static_cast<int>(255 * (valorSaida) / 5));
}

String ControleAVC::imprime() const
{
	auto texto = static_cast<String>(millis() / 1000.0);
	texto += "\t";
	texto += valorTensaoDoArco;
	texto += "\t";
	texto += 500.0 * leituraEntradaAnalogica / 11264.0;
	texto += "\t";
	texto += valorSaida;
	return texto;
}

void ControleAVC::atua()
{
	valorTensaoDoArco = leTensaoArco();
	if (valorTensaoDoArco < 3 || valorTensaoDoArco > 30)
		setaSaida(referencia);
	//  valorTensaoDoArco = referencia;
	else
		setaSaida(valorTensaoDoArco);
}

