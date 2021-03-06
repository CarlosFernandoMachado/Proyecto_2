#include "Papa.h"
#include "Planta.h"
#include <iostream>
#include <string>

using std::string;

Papa::Papa(int x,int y,double vida,double dano,double escudo,int costo,bool isEscudo):Planta(x,y,vida,dano,costo),escudo(escudo),isEscudo(isEscudo){}
Papa::~Papa(){}

int Papa::getCosto(){
	return costo;
}

int Papa::getX(){
	return x;
}
int Papa::getY(){
	return y;
}
double Papa::ataque(){
	return dano;
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
			return Planta::defensa(dmg);
		}else if(dmg == escudo){
			isEscudo = false;
			escudo = 0;
			return 0;
		}
	}else{
		return Planta::defensa(dmg);
	}
	return 0;
}

string Papa::Descripcion(){
	string info = "Papa\nHP: 200\nAtq: 0\nCosto: 200\nEfecto especial: Tiene un escudo de 300";
	return info;
}

string Papa::toString(){
	return "Pa";
}
