#include "Zombie.h"
#include <iostream>
#include <sstream>//es sstream no sstring

using std::stringstream;

Zombie::Zombie(double vida, double dano,int costo, int Velocidad_Avance):Padre(vida,dano),costo(costo),Velocidad_Avance(Velocidad_Avance){
	//cuando llamas al constructor del padre solo se hace asi -> : Padre(vida,dano)
}

double Zombie::ataque(){
	return Padre::ataque();
}

double Zombie::defensa(double damage){
	return Padre::defensa(damage);	
}

int Zombie::getCosto(){ 
	return costo;
}
	
int Zombie::getVelocidad_Avance(){ 
	return Velocidad_Avance;
}

/*string Zombie::Descripcion(){
	stringstream ss;
	ss<<"Zombie Normal: "<<"vida: "<<Padre::vida<<" dano: "<<Padre::dano<<" costo: "<<costo<<"Velocidad de Avance"<<Velocidad_Avance;
	return ss.str();
}*/
