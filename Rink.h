#ifndef Rink_H_																
#define Rink_H_

#include "Utilities.h"

class OneMeterSquared{
public:
	
	const unsigned& value() const {return players_in;}; //return value of players_in
	
	OneMeterSquared():players_in(0){} //auto-reset by default ctor
	~OneMeterSquared(){}

	OneMeterSquared(const OneMeterSquared& cc){copyFrom(cc);};
	OneMeterSquared& operator=(const OneMeterSquared& ao){ if (this != &ao) {copyFrom(ao);} return *this ;};

	//Implemention of ++ post/prefix
	OneMeterSquared operator+(int n)
		{players_in+=n;return *this;}
	OneMeterSquared& operator++()
		{*this = *this + 1; return *this;} //pre-fix
	const OneMeterSquared operator++(int)
		{OneMeterSquared temp = *this; *this = *this + 1; return temp;}//post-fix
	//Implemention of -- post/prefix
	OneMeterSquared operator-(int n) 
		{players_in-=n;return *this;};
	OneMeterSquared& operator--()
		{*this = *this - 1; return *this;} //pre-fix
	const OneMeterSquared operator--(int)
		{OneMeterSquared temp = *this; *this = *this - 1; return temp;}//post-fix

private:
	unsigned players_in; //represents how many players currently in cell

	void copyFrom(const OneMeterSquared& ao){players_in=ao.players_in;}; //for copy ctor/operator
};

class Rink{

public:
	Rink(){};
	~Rink(){};
	const unsigned operator() (const double& i,const double& j) const
	{
		if (i<=FIELD_XMAX && i>=0 && j <=FIELD_YMAX && j>=0) return field[(unsigned)i][(unsigned)j].value();
			return 0;
	}
	void dec(const double& i,const double& j)
		{field[(unsigned)i][(unsigned)j]--;}
		//--field[(unsigned)i][(unsigned)j];};
	void inc(const double& i,const double& j)
		{field[(unsigned)i][(unsigned)j]++;}
		//++field[(unsigned)i][(unsigned)j];};

private:

	Rink(const Rink&);
	Rink& operator=(const Rink&);

	OneMeterSquared field[FIELD_XMAX][FIELD_YMAX];
};

#endif                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 