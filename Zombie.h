#include "Padre.h"
#pragma once
#include <string>

class Zombie{
	int costo;
	int velocidad_Avance;
	double vida;
	double dano;
	
public:
	Padre(double  , double,int , int);
	int getCosto();
	int getVelocidad_Avance();
	double ataque();
	double defensa();

};