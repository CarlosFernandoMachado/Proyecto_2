main: main.o Padre.o Cherry.o Papa.o Planta.o Zombie.o
	g++ main.o Padre.o Cherry.o Papa.o Planta.o Zombie.o -o a 
	
main.o:	main.cpp Padre.h Cherry.h Papa.h Planta.h Zombie.h ZombiePortero.h ZOmbieDeportista.h
	g++ -c main.cpp 

Padre.o:	Padre.cpp Padre.h
	g++ -c Padre.cpp 

Planta.o:	Planta.cpp Planta.h Padre.h
	g++ -c Planta.cpp

Cherry.o:	Cherry.cpp Cherry.h Planta.h
	g++ -c Cherry.cpp

Papa.o:	Papa.cpp Papa.h Planta.h
	g++ -c Papa.cpp

Zombie.o:	Zombie.cpp Zombie.h Padre.h
	g++ -c Zombie.cpp

ZOmbieDeportista.o: ZOmbieDeportista.cpp ZOmbieDeportista.h Zombie.h
	g++ -c ZOmbieDeportista.cpp 

ZombiePortero.o: ZombiePortero.cpp ZombiePortero.h Zombie.h
	g++ -c ZombiePortero.cpp
