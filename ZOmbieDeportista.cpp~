#include "ZombiePortero.h"
#include <iostream>
#include <sstream>
using std::stringstream;

//ZombiDeportista: Un zombi muy rápido y resistente.  solo aumentara su vida y velocidad de avance.{
ZOmbieDeportista::ZOmbieDeportista(double  , double, int , int){

}

int ZOmbieDeportista::getCosto(){
	return costo;
}

int ZOmbieDeportista::getVelocidad_Avance(){
	return Velocidad_Avance;
}

virtual double ZOmbieDeportista::ataque(){
	return ataque;
}

virtual double ZOmbieDeportista::defensa(){

}

virtual string ZOmbieDeportista::Descripcion(){
	stringstream ss;
	ss<<"ZombieDeportista: "<<"vida: "<<vida<<" dano: "<<dano<<" costo: "<<costo<<"Velocidad de Avance"<<Velocidad_Avance;
	return ss.str();
}