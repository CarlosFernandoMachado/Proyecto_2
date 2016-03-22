#include "Zombie.h"
#include<iostream>

Padre::Padre( double vida, double dano,int costo, int Velocidad_Avance):Padre(vida(vida),dano(dano)),costo(costo),Velocidad_Avance(Velocidad_Avance){

}

double Padre::ataque(){
	return dano;
}

double Padre::defensa(double dano){
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
