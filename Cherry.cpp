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
		return 300;
	}else{
		return Padre::ataque();
	}
}
double Cherry::defensa(double dmg){
	return Padre::defensa(dmg);
}
string Cherry::Descripcion(){
	string info = "Cherry\nHP: 1\nAtq: 150\nCosto: 400\nEfecto especial: Su primer ataque hace el doble de su ataque normal";
	return info;
}
