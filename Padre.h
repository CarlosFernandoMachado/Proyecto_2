#pragma once

class Padre{
	double vida;
	double dano;
public:
	Padre(double,double);
	virtual ~Padre();
	virtual double ataque()=0;
	virtual double defensa(double)=0;
};
