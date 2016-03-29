#include "Planta.h"
#include <iostream>
#include <string>

using std::string;

Planta::Planta(int x,int y,double vida,double dano,int costo):Padre(x,y,vida,dano),costo(costo){}
Planta::~Planta(){
}
int Planta::getCosto(){
	return costo;
}
int Planta::getX(){
	return x;
}
int Planta::getY(){
	return y;
}
double Planta::ataque(){
	return dano;
}
double Planta::defensa(double dmg){
	if(vida > dmg){
		vida -= dmg;
		return 0;
	}else if(vida <= dmg){
		return -1;
	}
}
string Planta::Descripcion(){
	string info = "Planta Normal\nHP: 50\nAtq: 50\ncosto: 100\nEfecto especial: No tiene";
	return info;
}

string Planta::toString(){
	return "Pl";
}
