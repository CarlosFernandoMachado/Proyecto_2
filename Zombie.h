#include "Padre.h"
#pragma once
#include <string>

class Zombie{
	int costo;
	int velocidad_Avance;
	double vida;
	double dano;
	
public:
	Zombie(double  , double, int , int);
	int getCosto();
	int getVelocidad_Avance();
	virtual double ataque();
	virtual double defensa();
	virtual string Descripcion();
};