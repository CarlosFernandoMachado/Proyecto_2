#include "Padre.h"
#pragma once
#include <string>

using std::string; 

//ZombiDeportista: Un zombi muy rápido y resistente.  solo aumentara su vida y velocidad de avance.
class ZOmbieDeportista : public Padre{  	
	double casco;
public:
	ZOmbieDeportista(double=350, double=100, int=400, int=2, double=150);
	int getCosto();
	int getVelocidad_Avance();
	virtual double ataque();
	virtual double defensa(double);
	//virtual string Descripcion();
};
