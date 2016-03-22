#include "Padre.h"
#include<iostream>

Padre::Padre(double vida, double dano):vida(vida),dano(dano){

}
Padre::~Padre(){

}
double Padre::ataque(){
	return dano;
}
double Padre::defensa(double dmg){
	if(vida > dmg){
		vida -= dmg;
		return 0;
	}else if (dmg > vida){
		return dmg - vida;
	}else if(vida == dmg){
		return -1;
	}
}
