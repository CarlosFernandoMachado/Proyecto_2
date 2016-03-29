#include "Portero.h"
#include "Zombie.h"
#include <iostream>
#include <string>

using std::string;

Portero::Portero(int x,int y,double vida, double dano,int costo, int Velocidad_Avance,double puerta) :Zombie(x,y,vida,dano,costo,Velocidad_Avance),puerta(puerta){
}
void Portero::setX(int a){
	x = a;
}
void Portero::setY(int a){
	y = a;
}
int Portero::getX(){
	return x;
}
int Portero::getY(){
	return y;
}
double Portero::ataque(){
	return dano;
}

double Portero::defensa(double damage){
		if (puerta > 0){
			if(damage > puerta){
				damage -= puerta;
				puerta = 0;
				if(vida > damage){
					vida -= damage;
					return 0;
				}else if(vida < damage){
					damage -= vida;
					return damage;
				}else if(vida == damage){
					return -1;
				}
			}else if(damage <= puerta){
				puerta -= damage;
				return 0;
			}
		}else{
			if(vida > damage){
				vida -= damage;
				return 0;
			}else if(vida < damage){
				damage -= vida;
				return damage;
			}else if(vida == damage){
				return -1;
			}
		}
}
int Portero::getCosto(){
	return costo;
}
	
int Portero::Avanzar(){
	return Velocidad_Avance;
}

string Portero::Descripcion(){
	string info = "Zombie Portero\nHP: 300\nAtq: 50\ncosto: 200\nMovimiento: 1 espacio\nEfecto especial: Tiene una puerta que bloquea 100 daño";
	return info;
}

string Portero::toString(){
	return "Po";
}
