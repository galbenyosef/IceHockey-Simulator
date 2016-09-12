#ifndef Forward_H_
#define Forward_H_

#include "Player.h"

class Forward : public Player{

public:
	Forward(unsigned& id,double (&)[_Attributes]);
	~Forward();
	void update(double (&)[_Coordinates], double (&)[_Coordinates], Rink&);
	void print(ostream&)const;
private:
	Forward(const Forward&);
	Forward& operator=(const Forward&);

	static const double alpha;
	static const double beta;
	static const double gamma;
};

#endif