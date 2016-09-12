#ifndef Defensemen_H_
#define Defensemen_H_

#include "Player.h"

class Defensemen : public Player{

public:
	Defensemen(unsigned& id,double (&attr)[_Attributes]);
	~Defensemen();
	void update(double (&)[_Coordinates], double (&)[_Coordinates], Rink&);
	void print(ostream&)const;
private:
	Defensemen(const Defensemen&);
	Defensemen& operator=(const Defensemen&);

	static const double alpha;
	static const double beta;
	static const double gamma;
};

#endif