#include "Zombie.h"
#include <iostream>
#include <string>

using std::string;

Zombie::Zombie(int x,int y,double vida, double dano,int costo, int Velocidad_Avance):Padre(x,y,vida,dano),costo(costo),Velocidad_Avance(Velocidad_Avance){
}
void Zombie::setX(int a){
	x = a;
}
void Zombie::setY(int a){
	y = a;
}
int Zombie::getX(){
	return x;
}
int Zombie::getY(){
	return y;
}
double Zombie::ataque(){
	return dano;
}

double Zombie::defensa(double dmg){
	if(vida > dmg){
		vida -= dmg;
		return 0;
	}else if(vida < dmg){
		dmg -= vida;
		return dmg;
	}else if(vida == dmg){
		return -1;
	}
}

int Zombie::getCosto(){ 
	return costo;
}
	
int Zombie::Avanzar(){ 
	return Velocidad_Avance;
}

string Zombie::Descripcion(){
	string info = "Zombie Normal\nHP: 150\nAtq: 50\ncosto: 100\nMovimiento: 1 espacio\nEfecto especial: No tiene";
	return info;
}

string Zombie::toString(){
	return "Zo";
}
