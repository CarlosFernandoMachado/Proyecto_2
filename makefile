main: main.o Padre.o Cherry.o Papa.o Planta.o Zombie.o Deportista.o Portero.o
	g++ main.o Padre.o Cherry.o Papa.o Planta.o Zombie.o Deportista.o Portero.o -o a 
	
main.o:	main.cpp Padre.h Cherry.h Papa.h Planta.h Zombie.h Portero.h Deportista.h
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

Deportista.o: Deportista.cpp Deportista.h Zombie.h
	g++ -c Deportista.cpp 

Portero.o: Portero.cpp Portero.h Zombie.h
	g++ -c Portero.cpp
