#include "Cherry.h"
#include "Planta.h"
#include <iostream>
#include <string>

using std::string;

Cherry::Cherry(double vida,double dano,int costo, bool Onehit):Planta(vida,dano,costo),Onehit(Onehit){}
Cherry::~Cherry(){}
int Cherry::getCosto(){
	return Padre::costo;
}
double Cherry::ataque(){
	if(Onehit){
		return 300;
	}else{
		return Padre::dano;
	}
}
double Cherry::defensa(double dmg){
	if(vida > dmg){
		vida -= dmg;
		return 0;
	}else if(vida <= dmg){
		return -1;
	}
	return 0;
}
string Cherry::Descripcion(){
	string info = "Cherry\nHP: 1\nAtq: 150\nCosto: 400\nEfecto especial: Su primer ataque hace el doble de su ataque normal";
	return info;
}
