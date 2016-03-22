#include "ZombiePortero.h"
#include <iostream>
#include <sstream>//sstream

using std::stringstream;

//Zombie Portero usa una puerta como escudo, recibe dano haste perder la puerta,
ZombiePortero::ZombiePortero(double vida, double dano,int costo, int Velocidad_Avance,int puerta) :Zombie(vida,dano,costo,Velocidad_Avance),puerta(puerta){
}

double ZombiePortero::ataque(){
	return Padre::ataque();
}

double ZombiePortero::defensa(double damage){//si vas a usar una puerta hace como hice con la papa porque hay que usar polimorfismo este metodo se mira  igual al de zombie normal
		if(damage>puerta){
			damage-=puerta;
			puerta=0;
			return	Padre::defensa(damage);
		}else if(damage<puerta){
			puerta-=damage;
			return Padre::defensa(damge);
		}else if(damage==puerta){
			puerta=0;
			return 0;
		}
}
int ZombiePortero::getPuerta(){
	return puerta;
}
int ZombiePortero::getCosto(){
	return Zombie::costo;
}
	
int ZombiePortero::getVelocidad_Avance(){
	return Zombie::Velocidad_Avance;
}

/*string ZombiePortero::Descripcion(){
	stringstream ss;
	ss<<"ZombiePortero: "<<"vida: "<<Padre::vida<<" dano: "<<Padre::dano<<" costo: "<<Zombie::costo<<"Velocidad de Avance"<<Zombie::Velocidad_Avance<<" puerta: "<<puerta;
	return ss.str();
}*/
