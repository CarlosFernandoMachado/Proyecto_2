#include "Padre.h"
#pragma once
#include <string>

using std::string;

class Zombie : public Padre{ 
protected:
	int costo;
	int Velocidad_Avance;
	
public:
	Zombie(int,int,double=150.0, double=50.0, int=100, int=1);
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
