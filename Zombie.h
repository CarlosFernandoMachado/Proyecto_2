#include "Padre.h"
#pragma once
#include <string>

using std::string;//te falto el using string

class Zombie : public Padre{ //en la clase hija pones despues de class Zombie, : public (nombre del padre)
	int costo;
	int velocidad_Avance;
	//no hay necesidad de que pongas vida y dano porque ya lo heredan de padre
	
public:
	Zombie(double  , double, int , int);
	int getCosto();
	int getVelocidad_Avance();
	virtual double ataque();
	virtual double defensa();
	virtual string Descripcion();
};
