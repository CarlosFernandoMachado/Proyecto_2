#include "Zombie.h"
#include "Deportista.h"
#include <iostream>
#include <string>
using std::string;

Deportista::Deportista(int x ,int y,double vida, double dano, int costo, int Velocidad_Avance,  double casco):Zombie(x,y,vida,dano,costo,Velocidad_Avance),casco(casco){
}

int Deportista::getCosto(){
	return Zombie::getCosto();
}
void Deportista::setX(int a){
	x = a;
}
void Deportista::setY(int a){
	y = a;
}
int Deportista::getX(){
	return x;
}
int Deportista::getY(){
	return y;
}
int Deportista::Avanzar(){
	Velocidad_Avance += 1;
	return Velocidad_Avance;
}

double Deportista::ataque(){
	return dano;
}

double Deportista::defensa(double damage){
	if(casco > 0){
		if(damage > casco){
			damage -= casco;
			casco = 0;
			if(vida > damage){
				vida -= damage;
				return 0;
			}else if(vida < damage){
				damage -= vida;
				return damage;
			}else if(vida == damage){
				return -1;
			}
		}else if(damage <= casco){
			casco -= damage;
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

string Deportista::Descripcion(){
	string info = "Zombie Deportista\nHP: 350\nAtq: 100\ncosto: 400\nMovimiento: 0\nEfecto especial: Tiene un casco que bloquea 150 daño, su movimiento va aumentando por turno\npuede saltar plantas";
	return info;
}

string Deportista::toString(){
	return "Dp";
}
