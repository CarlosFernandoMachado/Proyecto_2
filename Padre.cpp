#include "Padre.h"
#include<iostream>

Padre::Padre(double vida, double dano)vida(vida),dano(dano){

}
Padre::~Padre(){

}
double Padre::ataque(){
	return dano;
}
double Padre::defensa(double dano){
	if(vida > dano){
		vida -= dano;
		return 0;
	}else if (dano > vida){
		return dano - vida;
	}else if(vida == dano){
		return -1;
	}
}