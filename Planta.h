#include "Padre.h"
#pragma once
#include <string>

using std::string;

class Planta : public Padre{
	int costo;
public:
	Planta(double=50,double=50,int=100);
	~Planta();
	int getCosto();
	virtual double ataque();
	virtual double defensa(double);
	virtual string Descripcion();
};
