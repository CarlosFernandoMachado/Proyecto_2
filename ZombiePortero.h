#pragma once
#include "Zombie.h"//no tenes que incluir a padre.h zombie.h ya lo hace
#include <string>

using std::string;//te falto using

class ZombiePortero{
	double puerta;//vida dano costo y avance ya se heredan de zombie
	
public:
	ZombiePortero(double=300, double=100, int=200, int=2, double=100);
	int getCosto();
	int getVelocidad_Avance();
	int getPuerta();
	virtual double ataque();
	virtual double defensa(double);
	//virtual string Descripcion();
};
