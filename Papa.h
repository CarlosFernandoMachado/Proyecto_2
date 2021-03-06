#include "Planta.h"
#pragma once
#include <string>

using std::string;

class Papa : public Planta{
	double escudo;
	bool isEscudo;
public:
	Papa(int,int,double=200.0,double=0.0,double=300.0,int=200,bool=true);
	~Papa();
	virtual int getX();
	virtual int getY();
	virtual int getCosto();
	virtual double ataque();
	virtual double defensa(double);
	virtual string Descripcion();
	virtual string toString();
};
