#include "Cherry.h"
#include "Planta.h"
#include <iostream>
#include <string>

using std::string;

Cherry::Cherry(int x,int y,double vida,double dano,int costo, bool Onehit):Planta(x,y,vida,dano,costo),Onehit(Onehit){}
Cherry::~Cherry(){}
int Cherry::getCosto(){
	return costo;
}
int Cherry::getX(){
	return x;
}
int Cherry::getY(){
	return y;
}
double Cherry::ataque(){
	if(Onehit){
		Onehit = false;
		return dano*2;
	}else{
		Onehit = true;
		return dano;
	}
}
double Cherry::defensa(double dmg){
	return Planta::defensa(dmg);
}
string Cherry::Descripcion(){
	string info = "Cherry\nHP: 300\nAtq: 150\nCosto: 400\nEfecto especial: Sus ataques van alternando entre el doble y el normal";
	return info;
}

string Cherry::toString(){
	return "Ch";
}
