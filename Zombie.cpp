#include "Zombie.h"
#include <iostream>
#include <sstream>//es sstream no sstring

using std::stringstream;

Zombie::Zombie(double vida, double dano,int costo, int Velocidad_Avance):Padre(vida,dano),costo(costo),Velocidad_Avance(Velocidad_Avance){
	//cuando llamas al constructor del padre solo se hace asi -> : Padre(vida,dano)
}

double Zombie::ataque(){
	return dano;
}

double Zombie::defensa(double dano){
	if(vida >= dano){
		vida -= dano;
		return 0;
	}else{
		return dano - vida;
	}
}

int Zombie::getCosto(){//te saltaste el Zombie::
	return Costo;
}
	
int Zombie::getVelocidad_Avance(){//te saltaste el Zombie::
	return Velocidad_Avance;
}

string Zombie::Descripcion(){
	stringstream ss;
	ss<<"Zombie Normal: "<<"vida: "<<vida<<" dano: "<<dano<<" costo: "<<costo<<"Velocidad de Avance"<<Velocidad_Avance;
	return ss.str();
}
