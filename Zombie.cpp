#include "Zombie.h"
#include<iostream>

Padre::Padre(double vida, double dano)vida(vida),dano(dano){

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