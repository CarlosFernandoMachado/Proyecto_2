#include "ZombiePortero.h"
#include <iostream>
#include <sstring>

using std::stringstream;

//Zombie Portero usa una puerta como escudo, recibe dano haste perder la puerta,
ZombiePortero::ZombiePortero(double vida, double dano,int costo, int Velocidad_Avance,int puerta) :Zombie(vida,dano,costo,Velocidad_Avance),puerta(puerta){
}

double ZombiePortero::ataque(){
	return dano;
}

double ZombiePortero::defensa(double dano){
	if(vida >= dano){
		vida -= dano;
		return 0;
	}else{
		return dano - vida;
	}
}
int getPuerta(){
	return puerta;
}
int getCosto(){
	return Costo;
}
	
int getVelocidad_Avance(){
	return Velocidad_Avance;
}

string ZombiePortero::Descripcion(){
	stringstream ss;
	ss<<"ZombiePortero: "<<"vida: "<<vida<<" dano: "<<dano<<" costo: "<<costo<<"Velocidad de Avance"<<Velocidad_Avance<<" puerta: "<<puerta;
	return ss.str();
}
