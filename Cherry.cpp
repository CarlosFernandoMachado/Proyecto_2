#include "Cherry.h"
#include "Planta.h"
#include <iostream>
#include <string>

using std::string;

Cherry::Cherry(double vida,double dano,int costo, bool Onehit):Planta(vida,dano,costo),Onehit(Onehit){}
Cherry::~Cherry(){}
int Cherry::getCosto(){
	return Planta::getCosto();
}
double Cherry::ataque(){
	if(Onehit){
		Onehit = false;
		return 300;
	}else{
		Onehit = true;
		return Padre::ataque();
	}
}
double Cherry::defensa(double dmg){
	return Padre::defensa(dmg);
}
string Cherry::Descripcion(){
	string info = "Cherry\nHP: 300\nAtq: 150\nCosto: 400\nEfecto especial: Sus ataques van alternando entre el doble y el normal";
	return info;
}
