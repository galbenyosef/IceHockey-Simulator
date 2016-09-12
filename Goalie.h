#ifndef Goalie_H_
#define Goalie_H_

#include "Player.h"

class Goalie : public Player{

public:
	Goalie(unsigned& id,double (&)[_Attributes]);
	~Goalie();
	void update(double (&target_point)[_Coordinates], double (&global)[_Coordinates], Rink&);
	void print(ostream&)const;
private:
	Goalie(const Goalie&);
	Goalie& operator=(const Goalie&);

	static const double alpha;
	static const double beta;
	static const double gamma;
};

#endif