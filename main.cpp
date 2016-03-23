#include <iostream>
#include "Padre.h"
#include "Planta.h"
#include "Papa.h"
#include "Cherry.h"
#include "Zombie.h"
#include "ZOmbieDeportista.h"
#include "ZombiePortero.h"
#include <vector>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;

int opcionesPlantas(int,int);
int opcionesZombies(int,int);

int main(int argc, char*argv[]){
	int turno = 1,opcion;
	int light = 100, dark = 100,lightgain = 50,darkgain = 50;//lightgain es cuanto gana de ligh por turno,ligh es el dinero de plantas, dark es el dinero de zombies, darkgain es cuanto gana de dark 
	bool salir = true;
	while(salir){
		if(turno == 1){
			opcion = opcionesPlantas(lightgain,light);
			turno += 1;
		}else if (turno == 2){
			opcion = opcionesPlantas(darkgain,dark);
			turno -= 1;
		}
	}
	
	return 0;
}

int opcionesPlantas(int lightgain,int light){
	int opcion;
	while(true){
		cout << "Su ganancia de luz por turno es: " << lightgain << "\nTiene " << light << " luz disponible" << "\n¿Que desea hacer?\n1)Plantar plantas\n2)Invertir luz" << endl;
		cin >> opcion;
		if (opcion == 1 || opcion == 2){
			break;
		}else{
			cout << "Porfavor escoja una opcion valida" << endl;
		}
	}
	return opcion;
}
int opcionesZombies(int darkgain,int dark){
	int opcion;
	while(true){
		cout << "Su ganancia de oscuridad por turno es: " << darkgain << "\nTiene " << dark << " oscuridad disponible" << "\n¿Que desea hacer?\n1)Colocar zombies\n2)Invertir oscuridad" << endl;
		cin >> opcion;
		if (opcion == 1 || opcion == 2){
			break;
		}else{
			cout << "Porfavor escoja una opcion valida" << endl;
		}
	}
	return opcion;
}
