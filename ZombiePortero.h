#pragma once
#include "Zombie.h"//no tenes que incluir a padre.h zombie.h ya lo hace
#include <string>

using std::string;//te falto using

class ZombiePortero{
	int puerta;//vida dano costo y avance ya se heredan de zombie
	
public:
	ZombiePortero(double , double, int , int, int);
	int getCosto();
	int getVelocidad_Avance();
	int getPuerta();
	virtual double ataque();
	virtual double defensa();
	virtual string Descripcion();
};