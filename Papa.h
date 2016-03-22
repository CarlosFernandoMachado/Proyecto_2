#include "Planta.h"
#pragma once
#include <string>

using std::string;

class Papa : public Planta{
	double escudo;
	bool isEscudo;
public:
	Papa(double=200,double=0,double=300,int=200,bool=true);
	~Papa();
	virtual int getCosto();
	virtual double ataque();
	virtual double defensa(double);
	virtual string Descripcion();
};
