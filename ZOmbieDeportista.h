#include "Padre.h"
#pragma once
#include <string>

using std::string; 

//ZombiDeportista: Un zombi muy rápido y resistente.  solo aumentara su vida y velocidad de avance.
class ZOmbieDeportista : public Padre{  	
	double casco;
public:
	ZOmbieDeportista(double, double, int , int , double );
	int getCosto();
	int getVelocidad_Avance();
	virtual double ataque();
	virtual double defensa(double);
	//virtual string Descripcion();
};
