#include "Planta.h"
#pragma once
#include <string>

using std::string;

class Cherry : public Planta{
	bool Onehit;
public:
	Cherry(double=1,double=150,int=400,bool=true);
	~Cherry();
	int getCosto();
	virtual double ataque();
	virtual double defensa(double);
	virtual string Descripcion();
};