#include "Papa.h"
#include "Planta.h"
#include <iostream>
#include <string>

using std::string;

Papa::Papa(double vida,double dano,double escudo,int costo,bool isEscudo):Planta(vida,dano,costo),escudo(escudo),isEscudo(isEscudo){}
Papa::~Papa(){}

int Papa::getCosto(){
	return Planta::getCosto();
}

double Papa::ataque(){
	return 0;
}

double Papa::defensa(double dmg){
	if(isEscudo){
		if(dmg < escudo){
			escudo -= dmg;
			return 0;
		}else if(dmg > escudo){
			isEscudo = false;
			dmg -= escudo;
			escudo = 0;
			return Padre::defensa(dmg);
		}else if(dmg == escudo){
			isEscudo = false;
			escudo = 0;
			return 0;
		}
	}else{
		return Padre::defensa(dmg);
	}
	return 0;
}

string Papa::Descripcion(){
	string info = "Papa\nHP: 200\nAtq: 0\nCosto: 200\nEfecto especial: Tiene un escudo de 300";
	return info;
}
