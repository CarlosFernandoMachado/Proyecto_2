#pragma once
#include "Zombie.h"
#include <string>

using std::string;

class Portero : public Zombie{
	double puerta;
	
public:
	Portero(int,int,double=300.0, double=50.0, int=200, int=1, double=100.0);
	int getCosto();
	virtual void setX(int);
	virtual void setY(int);
	virtual int getX();
	virtual int getY();
	virtual int Avanzar();
	virtual double ataque();
	virtual double defensa(double);
	virtual string Descripcion();
	virtual string toString();
};
