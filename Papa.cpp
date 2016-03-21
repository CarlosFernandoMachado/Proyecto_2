#include "Papa.h"
#include "Planta.h"
#include <iostream>
#include <string>

using std::string;

Papa::Papa(double vida,double dano,double escudo,int costo,bool isEscudo):Planta(vida,dano,costo),escudo(escudo),isEscudo(isEscudo){}
Papa::~Papa(){}
int Papa::getCosto(){
	return costo;
}
double Papa::ataque(){
	return dano;
}
double Papa::defensa(double dano){
	if(isEscudo){
		if(dano < escudo){
			escudo -= dano;
			return 0;
		}else if(dano > escudo){
			isEscudo = false;
			dano -= escudo;
			escudo = 0;
			if(vida > dano){
				vida -= dano;
				return 0;
			}else if(vida <= dano){
				return -1;
			}
		}else if(dano == escudo){
			isEscudo = false;
			escudo = 0;
			return 0;
		}
	}else{
		if(vida > dano){
			vida -= dano;
			return 0;
		}else if(vida <= dano){
			return -1;
		}
	}
	return 0;
}
string Papa::Descripcion(){
	string info = "Papa\nHP: 200\nAtq: 0\nCosto: 200\nEfecto especial: Tiene un escudo de 300";
	return info;
}
