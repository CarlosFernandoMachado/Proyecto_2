#pragma once
#include "Padre.h"
#include "Zombie.h"
#include <string>

class ZombiePortero{
	double vida;
	double dano;
	int costo;
	int velocidad_Avance;
	int puerta;
	
public:
	ZombiePortero(double , double, int , int, int);
	int getCosto();
	int getVelocidad_Avance();
	int getPuerta();
	virtual double ataque();
	virtual double defensa();
	virtual string Descripcion();
};