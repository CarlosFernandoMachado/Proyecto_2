#pragma once
# include <string>

using std::string;

class Padre{
protected:
	int x,y;
	double vida;
	double dano;
public:
	Padre(int,int,double=0.0,double=0.0);
	 ~Padre();
	virtual int getX()=0;
	virtual int getY()=0;
	virtual double ataque()=0;
	virtual double defensa(double)=0;
	virtual string Descripcion()=0;
	virtual string toString()=0;
};
