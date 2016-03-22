#include "Zombie.h"
#include <iostream>
#include <sstring>

using std::stringstream;

Zombie::Zombie(double vida, double dano,int costo, int Velocidad_Avance):Padre(vida(vida),dano(dano)),costo(costo),Velocidad_Avance(Velocidad_Avance){
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

int getCosto(){
	return Costo;
}
	
int getVelocidad_Avance(){
	return getVelocidad_Avance;
}

string Zombie::Descripcion(){
	stringstream ss;
	ss<<"Zombie Normal: "<<"vida: "<<vida<<" dano: "<<dano<<" costo: "<<costo<<"Velocidad de Avance"<<Velocidad_Avance;
	return ss.str();
}
