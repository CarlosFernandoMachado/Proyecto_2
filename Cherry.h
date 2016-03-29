#include "Planta.h"
#pragma once
#include <string>

using std::string;

class Cherry : public Planta{
	bool Onehit;
public:
	Cherry(int,int,double=300.0,double=150.0,int=400,bool=true);
	~Cherry();
	virtual int getX();
	virtual int getY();
	virtual int getCosto();
	virtual double ataque();
	virtual double defensa(double);
	virtual string Descripcion();
	virtual string toString();
};
