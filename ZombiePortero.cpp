#include "ZombiePortero.h"
#include <iostream>
#include <sstream>//sstream

using std::stringstream;

//Zombie Portero usa una puerta como escudo, recibe dano haste perder la puerta,
ZombiePortero::ZombiePortero(double vida, double dano,int costo, int Velocidad_Avance,int puerta) :Zombie(vida,dano,costo,Velocidad_Avance),puerta(puerta){
}

double ZombiePortero::ataque(){
	return dano;
}

double ZombiePortero::defensa(double dano){
	if (puerta > 0){
		if(dano < puerta){
			puerta -= dano;
			return 0;
		}else if(dano > puerta){
			dano -= puerta;
			puerta = 0;
			return dano;
		}else if(dano == puerta){
			puerta = 0;
			return 0;
		}
	}else{
		if(vida >= dano){
			vida -= dano;
			return 0;
		}else{
			return dano - vida;
		}
	}
}
int ZombiePortero::getPuerta(){// te falto ZombiePortero::
	return puerta;
}
int ZombiePortero::getCosto(){// te falto ZombiePortero::
	return Costo;
}
	
int ZombiePortero::getVelocidad_Avance(){// te falto ZombiePortero::
	return Velocidad_Avance;
}

string ZombiePortero::Descripcion(){
	stringstream ss;
	ss<<"ZombiePortero: "<<"vida: "<<vida<<" dano: "<<dano<<" costo: "<<costo<<"Velocidad de Avance"<<Velocidad_Avance<<" puerta: "<<puerta;
	return ss.str();
}
