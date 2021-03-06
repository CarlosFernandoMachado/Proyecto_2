#include "Zombie.h"
#pragma once
#include <string>

using std::string; 

class Deportista : public Zombie{  	
	double casco;
public:
	Deportista(int,int,double=350.0, double=100.0, int=400.0, int=2, double=150.0);
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
