#include "Padre.h"
#pragma once
#include <string>

using std::string; 

//ZombiDeportista: Un zombi muy rápido y resistente.  solo aumentara su vida y velocidad de avance.
class ZOmbieDeportita : public Padre{  	
public:
	ZOmbieDeportita(double  , double, int , int);
	int getCosto();
	int getVelocidad_Avance();
	virtual double ataque();
	virtual double defensa();
	virtual string Descripcion();
};