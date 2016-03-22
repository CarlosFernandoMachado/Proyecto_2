#include "Planta.h"
#include <iostream>
#include <string>

using std::string;

Planta::Planta(double vida,double dano,int costo):Padre(vida,dano),costo(costo){}
Planta::~Planta(){
}
int Planta::getCosto(){
	return costo;
}
double Planta::ataque(){
	return Padre::ataque();
}
double Planta::defensa(double dmg){
	return Padre::defensa(dmg);
}
string Planta::Descripcion(){
	string info = "Planta Normal\nHP: 50\nAtq: 50\ncosto: 100\nEfecto especial: No tiene";
	return info;
}
