#include <iostream>
#include "Padre.h"
#include "Planta.h"
#include "Papa.h"
#include "Cherry.h"
#include "Zombie.h"
#include "Deportista.h"
#include "Portero.h"
#include <vector>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

void Instrucciones(int);
int OpcionesPlantas(int,int);
int OpcionesZombies(int,int);
int MenuInvertirLight(int,int);
int MenuInvertirDark(int,int);
int MenuPlantar(int);
int MenuColocar(int);
void LlenarMatriz(vector<Planta>&,vector<Cherry>&,vector<Papa>&,vector<Zombie>&,vector<Deportista>&,vector<Portero>&,string**);
void ImprimirMatriz(string**);
void BorrarMatriz(string**);
string** CrearMatriz();
bool ValidarPlantar(vector<Planta>&,vector<Cherry>&,vector<Papa>&,vector<Zombie>&,vector<Deportista>&,vector<Portero>&,int,int);
bool ValidarColocar(vector<Planta>&,vector<Cherry>&,vector<Papa>&,int,int);
bool GaneZombies(vector<Zombie>&,vector<Deportista>&,vector<Portero>&);
void MoverZombies(vector<Planta>&,vector<Cherry>&,vector<Papa>&,vector<Zombie>&,vector<Deportista>&,vector<Portero>&);
int CombatePlantas(vector<Planta>&,vector<Cherry>&,vector<Papa>&,vector<Zombie>&,vector<Deportista>&,vector<Portero>&,int);
void CombateZombies(vector<Planta>&,vector<Cherry>&,vector<Papa>&,vector<Zombie>&,vector<Deportista>&,vector<Portero>&);

int main(int argc, char*argv[]){
	string** matriz = CrearMatriz();
	vector <Planta> plantas;
	vector <Cherry> cherrys;
	vector <Papa> papas;
	vector <Zombie> zombies;
	vector <Deportista> deportistas;
	vector <Portero> porteros;	
	int deadzombies;
	while(true){
		cout << "Cuantos zombies desea eliminar para ganar: ";
		cin >> deadzombies;
		if (deadzombies > 0){
			break;
		}else{
			cout << "Ingrese un numero positivo y mayor a cero" << endl;
		}
	}
	int turno = 1,opcion;
	int light = 10000, dark = 100000,lightgain = 50,darkgain = 100;
	bool salir = true;
	int x = 0,y = 0;
	Instrucciones(deadzombies);
	while(salir){
		if(turno == 1){
			cout << "EMPIEZA TURNO DE LAS PLANTAS" << endl;
			light += lightgain;
			while(true){
				opcion = OpcionesPlantas(lightgain,light);
				if(opcion == 1){
					opcion = MenuPlantar(light);
					if(opcion == 1){
						if(light < 100){
							//planta vida=150,dano=50,costo=100
							cout << "No puede pagarlo" << endl;
						}else{
							LlenarMatriz(plantas,cherrys,papas,zombies,deportistas,porteros,matriz);
							ImprimirMatriz(matriz);
							cout << "Ingrese la coordenada en x: ";
							cin >> x;
							cout << "Ingrese la coordenada en y: ";
							cin >> y;
							if(ValidarPlantar(plantas,cherrys,papas,zombies,deportistas,porteros,x,y)){
								cout << "No puede colocar plantas en posiciones ocupadas\ny no puede plantar plantas en la ultima columna" << endl;
							}else{
								Planta nueva(x,y);
								plantas.push_back(nueva);
								cout << "Ha plantado su planta!" << endl;
								light -= 100;
							}							
						}
					}else if(opcion == 2){
						//papa vida=200,dano=0,costo=200,escudo=300
						if(light < 200){
							cout << "No puede pagarlo" << endl;
						}else{
							LlenarMatriz(plantas,cherrys,papas,zombies,deportistas,porteros,matriz);
							ImprimirMatriz(matriz);
							cout << "Ingrese la coordenada en x: ";
							cin >> x;
							cout << "Ingrese la coordenada en y: ";
							cin >> y;
							if(ValidarPlantar(plantas,cherrys,papas,zombies,deportistas,porteros,x,y)){
								cout << "No puede colocar plantas en posiciones ocupadas\ny no puede plantar plantas en la ultima columna" << endl;
							}else{
								Papa nueva(x,y);
								papas.push_back(nueva);
								cout << "Ha plantado su papa!" << endl;
								light -= 200;
							}
						}
					}else if(opcion == 3){
						//cherry vida=300,dano=150,costo=400
						if(light < 400){
							cout << "No puede pagarlo" << endl;
						}else{
							LlenarMatriz(plantas,cherrys,papas,zombies,deportistas,porteros,matriz);
							ImprimirMatriz(matriz);
							cout << "Ingrese la coordenada en x: ";
							cin >> x;
							cout << "Ingrese la coordenada en y: ";
							cin >> y;
							if(ValidarPlantar(plantas,cherrys,papas,zombies,deportistas,porteros,x,y)){
								cout << "No puede colocar plantas en posiciones ocupadas\ny no puede plantar plantas en la ultima columna" << endl;
							}else{
								Cherry nueva(x,y);
								cherrys.push_back(nueva);
								cout << "Ha plantado su cherry!" << endl;
								light -= 400;
							}
						}
					}
				}else if(opcion == 2){
					opcion = MenuInvertirLight(lightgain,light);
					if(opcion == 1){
						if(light >= lightgain){
							light -= lightgain;
							lightgain += lightgain;
						}else{
							cout << "No puede pagarlo" << endl;
						}
					}
				}else{
					break;
				}
			}
			turno = 2;
			deadzombies = CombatePlantas(plantas,cherrys,papas,zombies,deportistas,porteros,deadzombies);
			if(deadzombies <= 0){
				cout << "HAN GANADO LAS PLANTAS" << endl;
				salir = false;
			}
		}else if (turno == 2){
			cout << "EMPIEZA TURNO DE ZOMBIES" << endl;
			dark += darkgain;
			while(true){
				opcion = OpcionesZombies(darkgain,dark);
				if(opcion == 1){
					opcion = MenuColocar(dark);
					if(opcion == 1){
						if(dark < 100){
							//Zombie Normal HP: 150 Atq: 50 costo: 100 Movimiento: 1 espacio
							cout << "No puede pagarlo" << endl;
						}else{
							LlenarMatriz(plantas,cherrys,papas,zombies,deportistas,porteros,matriz);
							ImprimirMatriz(matriz);
							cout << "Ingrese la coordenada en x: ";
							cin >> x;
							cout << "Ingrese la coordenada en y: ";
							cin >> y;
							if(ValidarColocar(plantas,cherrys,papas,x,y)){
								cout << "No puede colocar zombies en posiciones ocupadas por plantas\ny solo puede colocar zombies en la ultima columna" << endl;
							}else{
								Zombie nueva(x,y);
								zombies.push_back(nueva);
								cout << "Ha colocado su zombie! BRAAAAAAAAINS" << endl;
								dark -= 100;
							}							
						}
					}else if(opcion == 2){
						//Zombie Portero HP: 300 Atq: 50 costo: 200 Movimiento: 1 espacio
						if(dark < 200){
							cout << "No puede pagarlo" << endl;
						}else{
							LlenarMatriz(plantas,cherrys,papas,zombies,deportistas,porteros,matriz);
							ImprimirMatriz(matriz);
							cout << "Ingrese la coordenada en x: ";
							cin >> x;
							cout << "Ingrese la coordenada en y: ";
							cin >> y;
							if(ValidarColocar(plantas,cherrys,papas,x,y)){
								cout << "No puede colocar zombies en posiciones ocupadas por plantas\ny solo puede colocar zombies en la ultima columna" << endl;
							}else{
								Portero nueva(x,y);
								porteros.push_back(nueva);
								cout << "Ha colocado su zombie portero! BRAAAAAAAAINS" << endl;
								dark -= 200;
							}
						}
					}else if(opcion == 3){
						//Zombie Deportista HP: 350 Atq: 100 costo: 400 Movimiento: 1 o 2 espacios
						if(dark < 400){
							cout << "No puede pagarlo" << endl;
						}else{
							LlenarMatriz(plantas,cherrys,papas,zombies,deportistas,porteros,matriz);
							ImprimirMatriz(matriz);
							cout << "Ingrese la coordenada en x: ";
							cin >> x;
							cout << "Ingrese la coordenada en y: ";
							cin >> y;
							if(ValidarColocar(plantas,cherrys,papas,x,y)){
								cout << "No puede colocar zombies en posiciones ocupadas por plantas\ny solo puede colocar zombies en la ultima columna" << endl;
							}else{
								Deportista nueva(x,y);
								deportistas.push_back(nueva);
								cout << "Ha colocado su zombie deportista! BRAAAAAAAAINS" << endl;
								dark -= 400;
							}
						}
					}
				}else if(opcion == 2){
					opcion = MenuInvertirDark(darkgain,dark);
					if(opcion == 1){
						if(dark >= darkgain){
							dark -= darkgain;
							darkgain += darkgain;
						}else{
							cout << "No puede pagarlo" << endl;
						}
					}
				}else{
					break;
				}
			}
			turno = 1;
			MoverZombies(plantas,cherrys,papas,zombies,deportistas,porteros);
			salir = GaneZombies(zombies,deportistas,porteros);
			if(!salir){
				cout << "HAN GANADO LOS ZOMBIES BRAAAAAAAAINS" << endl;
			}
			CombateZombies(plantas,cherrys,papas,zombies,deportistas,porteros);
		}
	}
	BorrarMatriz(matriz);
	return 0;
}
void CombateZombies(vector<Planta>& plantas, vector<Cherry>& cherrys, vector<Papa>& papas, vector<Zombie>& zombies, vector<Deportista>& deportistas, vector<Portero>& porteros){
	int x,y;
	double dano;
	if(zombies.size() > 0){
		for(int i = 0;i < zombies.size(); i++){
			x = zombies[i].getX() - zombies[i].Avanzar();
			y = zombies[i].getY();
			if(plantas.size() > 0){
				for(int j = 0;j < plantas.size(); j++){
					if(plantas[j].getX() == x && plantas[j].getY() == y){
						dano = plantas[j].defensa(zombies[i].ataque());
						if(dano == -1){
							plantas.erase(plantas.begin()+j);
							j -= 1;
						}
					}
				}
			}
			if(cherrys.size() > 0){
				for(int j = 0;j < cherrys.size(); j++){
					if(cherrys[j].getX() == x && cherrys[j].getY() == y){
						dano = cherrys[j].defensa(zombies[i].ataque());
						if(dano == -1){
							cherrys.erase(cherrys.begin()+j);
							j -= 1;
						}
					}
				}
			}
			if(papas.size() > 0){
				for(int j = 0;j < papas.size(); j++){
					if(papas[j].getX() == x && papas[j].getY() == y){
						dano = papas[j].defensa(zombies[i].ataque());
						if(dano == -1){
							papas.erase(papas.begin()+j);
							j -= 1;
						}
					}
				}
			}
		}
	}
	if(deportistas.size() > 0){
		for(int i = 0;i < deportistas.size(); i++){
			x = deportistas[i].getX() - deportistas[i].Avanzar();
			y = deportistas[i].getY();
			if(plantas.size() > 0){
				for(int j = 0;j < plantas.size(); j++){
					if(plantas[j].getX() == x && plantas[j].getY() == y){
						dano = plantas[j].defensa(deportistas[i].ataque());
						if(dano == -1){
							plantas.erase(plantas.begin()+j);
							j -= 1;
						}
					}
				}
			}
			if(cherrys.size() > 0){
				for(int j = 0;j < cherrys.size(); j++){
					if(cherrys[j].getX() == x && cherrys[j].getY() == y){
						dano = cherrys[j].defensa(deportistas[i].ataque());
						if(dano == -1){
							cherrys.erase(cherrys.begin()+j);
							j -= 1;
						}
					}
				}
			}
			if(papas.size() > 0){
				for(int j = 0;j < papas.size(); j++){
					if(papas[j].getX() == x && papas[j].getY() == y){
						dano = papas[j].defensa(deportistas[i].ataque());
						if(dano == -1){
							papas.erase(papas.begin()+j);
							j -= 1;
						}
					}
				}
			}
		}
	}
	if(porteros.size() > 0){
		for(int i = 0;i < porteros.size(); i++){
			x = porteros[i].getX() - porteros[i].Avanzar();
			y = porteros[i].getY();
			if(plantas.size() > 0){
				for(int j = 0;j < plantas.size(); j++){
					if(plantas[j].getX() == x && plantas[j].getY() == y){
						dano = plantas[j].defensa(porteros[i].ataque());
						if(dano == -1){
							plantas.erase(plantas.begin()+j);
							j -= 1;
						}
					}
				}
			}
			if(cherrys.size() > 0){
				for(int j = 0;j < cherrys.size(); j++){
					if(cherrys[j].getX() == x && cherrys[j].getY() == y){
						dano = cherrys[j].defensa(porteros[i].ataque());
						if(dano == -1){
							cherrys.erase(cherrys.begin()+j);
							j -= 1;
						}
					}
				}
			}
			if(papas.size() > 0){
				for(int j = 0;j < papas.size(); j++){
					if(papas[j].getX() == x && papas[j].getY() == y){
						dano = papas[j].defensa(porteros[i].ataque());
						if(dano == -1){
							papas.erase(papas.begin()+j);
							j -= 1;
						}
					}
				}
			}
		}
	}
}
int CombatePlantas(vector<Planta>& plantas, vector<Cherry>& cherrys, vector<Papa>& papas, vector<Zombie>& zombies, vector<Deportista>& deportistas, vector<Portero>& porteros, int deadzombies){
	double dano = 0;	
	for(int y = 0;y < 5; y++){
		if(plantas.size() > 0){
			for(int j = 0;j < plantas.size(); j++){
				if(plantas[j].getY() == y){
					dano += plantas[j].ataque();
				}
			}
		}
		if(cherrys.size() > 0){
			for(int j = 0;j < cherrys.size(); j++){
				if(cherrys[j].getY() == y){
					dano += cherrys[j].ataque();
				}
			}
		}
		if(dano > 0 && zombies.size() > 0){
			for(int j = 0;j < zombies.size(); j++){
				if(zombies[j].getY() == y && dano > 0){
					dano = zombies[j].defensa(dano);
					if(dano == -1 || dano > 0){
						deadzombies -= 1;
						zombies.erase(zombies.begin()+j);
						j -= 1;
					}
				}
			}
		}
		if(dano > 0 && deportistas.size() > 0){
			for(int j = 0;j < deportistas.size(); j++){
				if(deportistas[j].getY() == y && dano > 0){
					dano = deportistas[j].defensa(dano);
					if(dano == -1 || dano > 0){
						deadzombies -= 1;
						deportistas.erase(deportistas.begin()+j);
						j -= 1;
					}
				}
			}
		}
		if(dano > 0 && porteros.size() > 0){
			for(int j = 0;j < porteros.size(); j++){
				if(porteros[j].getY() == y && dano > 0){
					dano = porteros[j].defensa(dano);
					if(dano == -1 || dano > 0){
						deadzombies -= 1;
						porteros.erase(porteros.begin()+j);
						j -= 1;
					}
				}
			}
		}	
	}
	return deadzombies;
}
void MoverZombies(vector<Planta>& plantas, vector<Cherry>& cherrys, vector<Papa>& papas, vector<Zombie>& zombies, vector<Deportista>& deportistas, vector<Portero>& porteros){
	int x,y;
	bool autorizacion = true;
	if(zombies.size() > 0){
		for(int i = 0;i < zombies.size(); i++){
			x = zombies[i].getX() - zombies[i].Avanzar();
			if(x < 0){
				x = 0;
			}
			y = zombies[i].getY();
			if(plantas.size() > 0){
				for(int j = 0;j < plantas.size(); j++){
					if(plantas[j].getX() == x && plantas[j].getY() == y){
						autorizacion = false;
					}
					if(autorizacion == false){
						break;
					}
				}
			}
			if(cherrys.size() > 0 && autorizacion == true){
				for(int j = 0;j < cherrys.size(); j++){
					if(cherrys[j].getX() == x && cherrys[j].getY() == y){
						autorizacion = false;
					}
					if(autorizacion == false){
						break;
					}
				}
			}
			if(papas.size() > 0 && autorizacion == true){
				for(int j = 0;j < papas.size(); j++){
					if(papas[j].getX() == x && papas[j].getY() == y){
						autorizacion = false;
					}
					if(autorizacion == false){
						break;
					}
				}
			}
			if(autorizacion == true){
				zombies[i].setX(x);
			}else{
				autorizacion = true;
			}
		}
	}
	autorizacion = true;
	if(deportistas.size() > 0){
		for(int i = 0;i < deportistas.size(); i++){
			x = deportistas[i].getX() - deportistas[i].Avanzar();
			if(x < 0){
				x = 0;
			}
			y = deportistas[i].getY();
			if(plantas.size() > 0){
				for(int j = 0;j < plantas.size(); j++){
					if(plantas[j].getX() == x && plantas[j].getY() == y){
						autorizacion = false;
					}
					if(autorizacion == false){
						break;
					}
				}
			}
			if(cherrys.size() > 0 && autorizacion == true){
				for(int j = 0;j < cherrys.size(); j++){
					if(cherrys[j].getX() == x && cherrys[j].getY() == y){
						autorizacion = false;
					}
					if(autorizacion == false){
						break;
					}
				}
			}
			if(papas.size() > 0 && autorizacion == true){
				for(int j = 0;j < papas.size(); j++){
					if(papas[j].getX() == x && papas[j].getY() == y){
						autorizacion = false;
					}
					if(autorizacion == false){
						break;
					}
				}
			}
			if(autorizacion == true){
				deportistas[i].setX(x);
			}else{
				autorizacion = true;
			}
		}
	}
	autorizacion = true;
	if(porteros.size() > 0){
		for(int i = 0;i < porteros.size(); i++){
			x = porteros[i].getX() - porteros[i].Avanzar();
			if(x < 0){
				x = 0;
			}
			y = porteros[i].getY();
			if(plantas.size() > 0){
				for(int j = 0;j < plantas.size(); j++){
					if(plantas[j].getX() == x && plantas[j].getY() == y){
						autorizacion = false;
					}
					if(autorizacion == false){
						break;
					}
				}
			}
			if(cherrys.size() > 0 && autorizacion == true){
				for(int j = 0;j < cherrys.size(); j++){
					if(cherrys[j].getX() == x && cherrys[j].getY() == y){
						autorizacion = false;
					}
					if(autorizacion == false){
						break;
					}
				}
			}
			if(papas.size() > 0 && autorizacion == true){
				for(int j = 0;j < papas.size(); j++){
					if(papas[j].getX() == x && papas[j].getY() == y){
						autorizacion = false;
					}
					if(autorizacion == false){
						break;
					}
				}
			}
			if(autorizacion == true){
				porteros[i].setX(x);
			}else{
				autorizacion = true;
			}
		}
	}
}
bool GaneZombies(vector<Zombie>& zombies,vector<Deportista>& deportistas,vector<Portero>& porteros){
	for(int i = 0;i < zombies.size(); i++){
		if(zombies[i].getX() == 0){
			return false;
		}
	}
	for(int i = 0;i < deportistas.size(); i++){
		if(deportistas[i].getX() == 0){
			return false;
		}
	}
	for(int i = 0;i < porteros.size(); i++){
		if(porteros[i].getX() == 0){
			return false;
		}
	}
	return true;
}
bool ValidarColocar(vector<Planta>& plantas, vector<Cherry>& cherrys, vector<Papa>& papas,int x,int y){
	for(int i = 0;i < plantas.size(); i++){
		if(plantas[i].getX() == x && plantas[i].getY() == y){
			return true;
		}
	}
	for(int i = 0;i < cherrys.size(); i++){
		if(cherrys[i].getX() == x && cherrys[i].getY() == y){
			return true;
		}
	}
	for(int i = 0;i < papas.size(); i++){
		if(papas[i].getX() == x && papas[i].getY() == y){
			return true;
		}
	}
	if(x != 8){
		return true;
	}
	return false;
}
bool ValidarPlantar(vector<Planta>& plantas, vector<Cherry>& cherrys, vector<Papa>& papas, vector<Zombie>& zombies, vector<Deportista>& deportistas, vector<Portero>& porteros,int x,int y){
	for(int i = 0;i < plantas.size(); i++){
		if(plantas[i].getX() == x && plantas[i].getY() == y){
			return true;
		}
	}
	for(int i = 0;i < cherrys.size(); i++){
		if(cherrys[i].getX() == x && cherrys[i].getY() == y){
			return true;
		}
	}
	for(int i = 0;i < papas.size(); i++){
		if(papas[i].getX() == x && papas[i].getY() == y){
			return true;
		}
	}
	for(int i = 0;i < zombies.size(); i++){
		if(zombies[i].getX() == x && zombies[i].getY() == y){
			return true;
		}
	}
	for(int i = 0;i < deportistas.size(); i++){
		if(deportistas[i].getX() == x && deportistas[i].getY() == y){
			return true;
		}
	}
	for(int i = 0;i < porteros.size(); i++){
		if(porteros[i].getX() == x && porteros[i].getY() == y){
			return true;
		}
	}
	if(x == 8){
		return true;
	}
	return false;
}
void LlenarMatriz(vector<Planta>& plantas, vector<Cherry>& cherrys, vector<Papa>& papas, vector<Zombie>& zombies, vector<Deportista>& deportistas, vector<Portero>& porteros,string** matriz){
	for(int i = 0;i < 5; i++){
		for(int j = 0;j < 9; j++){
			matriz[i][j] = "+++";
		}
	}
	//x es 9 y es 5
	string espacio = "";
	for(int y = 0;y < 5; y++){
		for(int x = 0;x < 9; x++){
			if(plantas.size() > 0){
				for(int i = 0;i < plantas.size(); i++){
					if(plantas[i].getX() == x && plantas[i].getY() == y){
						espacio += plantas[i].toString();
						espacio += ",";
					}
				}
			}
			if(cherrys.size() > 0){
				for(int i = 0;i < cherrys.size(); i++){
					if(cherrys[i].getX() == x && cherrys[i].getY() == y){
						espacio += cherrys[i].toString();
						espacio += ",";
					}
				}
			}
			if(papas.size() > 0){
				for(int i = 0;i < papas.size(); i++){
					if(papas[i].getX() == x && papas[i].getY() == y){
						espacio += papas[i].toString();
						espacio += ",";
					}
				}
			}
			if(zombies.size() > 0){
				for(int i = 0;i < zombies.size(); i++){
					if(zombies[i].getX() == x && zombies[i].getY() == y){
						espacio += zombies[i].toString();
						espacio += ",";
					}
				}
			}
			if(deportistas.size() > 0){
				for(int i = 0;i < deportistas.size(); i++){
					if(deportistas[i].getX() == x && deportistas[i].getY() == y){
						espacio += deportistas[i].toString();
						espacio += ",";
					}
				}
			}
			if(porteros.size() > 0){
				for(int i = 0;i < porteros.size(); i++){
					if(porteros[i].getX() == x && porteros[i].getY() == y){
						espacio += porteros[i].toString();
						espacio += ",";
					}
				}
			}
			if (espacio != ""){
				matriz[y][x] = espacio;
				espacio = "";
			}
		}
	}
}
void BorrarMatriz(string** matriz){
	for (int i = 0; i < 5; i++)
		delete[] matriz[i];
	delete[] matriz;
}
void ImprimirMatriz(string** matriz){
	cout << " --0---1---2---3---4---5---6---7---8--- <- x" << endl;
	for(int i = 0;i < 5; i++){
		cout << i << " ";
		for(int j = 0;j < 9; j++){
			if(j == 8){
				cout << matriz[i][j] << endl;
			}else{
				cout << matriz[i][j] << "-";
			}
		}
	}
	cout << "y" << endl;
}
string** CrearMatriz(){
	string** matriz = new string*[5];
	for(int i = 0;i < 5; i++)
		matriz[i] = new string[9];
	return matriz;
}
int MenuPlantar(int light){
	int opcion;
	Planta planta(0,0);
	Cherry cherry(0,0);
	Papa papa(0,0);
	while(true){
		cout << "Tiene " << light << " luz disponible\n" <<"Puede plantar las siguientes plantas\n1)Planta normal\n2)Papa\n3)Cherry" << endl;
		cout << planta.Descripcion() << endl;
		cout << cherry.Descripcion() << endl;
		cout << papa.Descripcion() << endl;
		cin >> opcion;
		if(opcion == 1 || opcion == 2 || opcion == 3){
			break;
		}
	}
	return opcion;
}
int MenuColocar(int dark){
	int opcion;
	Zombie zombie(0,0);
	Deportista deportista(0,0);
	Portero portero(0,0);
	while(true){
		cout << "Tiene " << dark << " oscuridad disponible" <<"\nPuede colocar los siguientes zombies\n1)Zombie normal\n2)Portero\n3)Deportista" << endl;
		cout << zombie.Descripcion() << endl;
		cout << deportista.Descripcion() << endl;
		cout << portero.Descripcion() << endl;
		cin >> opcion;
		if(opcion == 1 || opcion == 2 || opcion == 3){
			break;
		}
	}
	return opcion;
}
void Instrucciones(int zombies){
	cout << "Plantas vs Zombies\nEs un juego de dos jugadores, se juega en turnos, primero empiezan las plantas\nLas plantas ganan cuando eliminan a " << zombies << " zombies\nLos zombies ganan cuando llegan al otro lado del matriz\nPara plantar plantas necesita luz que ira ganando al empezar el turno\nPara colocar zombies necesita oscuridad que ira ganando al empezar el turno\nEl combate y el movimiento se hace de forma automatica\nLas plantas pueden ser plantadas en cualquier lugar de la arena excepto en el final del lado derecho\nLos zombis solo pueden ser colocados al final del lado derecho\nPl = Planta\nCh = Cherry\nPa = Papa\nZo = Zombie\nDe = Deportista\nPo = Portero" << endl;
}
int OpcionesPlantas(int lightgain,int light){
	int opcion;
	while(true){
		cout << "Su ganancia de luz por turno es: " << lightgain << "\nTiene " << light << " luz disponible" << "\n¿Que desea hacer?\n1)Plantar plantas\n2)Invertir luz\n3)Pasar turno" << endl;
		cin >> opcion;
		if (opcion == 1 || opcion == 2 || opcion == 3){
			break;
		}else{
			cout << "Porfavor escoja una opcion valida" << endl;
		}
	}
	return opcion;
}
int OpcionesZombies(int darkgain,int dark){
	int opcion;
	while(true){
		cout << "Su ganancia de oscuridad por turno es: " << darkgain << "\nTiene " << dark << " oscuridad disponible" << "\n¿Que desea hacer?\n1)Colocar zombies\n2)Invertir oscuridad\n3)Pasar turno" << endl;
		cin >> opcion;
		if (opcion == 1 || opcion == 2 || opcion == 3){
			break;
		}else{
			cout << "Porfavor escoja una opcion valida" << endl;
		}
	}
	return opcion;
}
int MenuInvertirLight(int lightgain, int light){
	int opcion;
	while(true){
		cout << "Tiene " << light << " de luz disponible" <<"\nPara poder invertir en su ganancia de luz por turno tiene que pagar: " << lightgain << "\nGanara cuanto pague" <<"\nDesea hacerlo? \n1)si\n2)no" << endl;
		cin >> opcion;
		if(opcion == 1 || opcion == 2){
			break;
		}else{
			cout << "Ingrese una opcion valida" << endl;
		}
	}
	return opcion;
}
int MenuInvertirDark(int darkgain,int dark){
	int opcion;
	while(true){
		cout << "Tiene " << dark << " de oscuridad disponible" <<"\nPara poder invertir en su ganancia de oscuridad por turno tiene que pagar: " << darkgain << "\nGanara cuanto pague" <<"\nDesea hacerlo? \n1)si\n2)no" << endl;
		cin >> opcion;
		if(opcion == 1 || opcion == 2){
			break;
		}else{
			cout << "Ingrese una opcion valida" << endl;
		}
	}
	return opcion;
}
