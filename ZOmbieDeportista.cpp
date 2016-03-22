#include "ZombiePortero.h"
#include <iostream>
#include <sstream>
using std::stringstream;

//ZombiDeportista: Un zombi muy rápido y resistente.  solo aumentara su vida y velocidad de avance.{
ZOmbieDeportista::ZOmbieDeportista(double  , double, int , int,  double ):Zombie(vida,dano,costo,Velocidad_Avance),casco(casco){

}

int ZOmbieDeportista::getCosto(){
	return Zombie::costo;
}

int ZOmbieDeportista::getVelocidad_Avance(){
	return Zombie::Velocidad_Avance+1;
}

double ZOmbieDeportista::ataque(){
	return Padre::ataque();
}

double ZOmbieDeportista::defensa(double damage){
	if(damage>casco){
			damage-=casco;
			puerta=0;
			return	Padre::defensa(damage);
		}else if(damage<casco){
			casco-=damage;
			return Padre::defensa(damge);
		}else if(damage==casco){
			puerta=0;
			return 0;
		}
}

/*string ZOmbieDeportista::Descripcion(){
	stringstream ss;
	ss<<"ZombieDeportista: "<<"vida: "<<Padre::vida<<" dano: "<<Padre::dano<<" costo: "<<Zombie::costo<<"Velocidad de Avance"<<Zombie::Velocidad_Avance<<" casco: "<<casco;
	return ss.str();
}*/
