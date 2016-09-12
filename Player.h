#ifndef Player_H_
#define Player_H_

#include "Rink.h"

using namespace std;

class Player{

public:
	Player();
	Player(unsigned&,double (&)[_Attributes]);
	virtual ~Player();

	Player& operator=(const Player* ao);
	
	friend bool operator==(const Player&,const Player&);
	friend bool operator>(const Player&,const Player&);
	friend ostream& operator<<(ostream&, const Player&);

	unsigned getID()const{return player_id;}

	void setx(const double& x){attributes[v_x]=x;}
	const double getx()const{return attributes[v_x];}

	void sety(const double& y){attributes[v_y]=y;}
	const double gety()const{return attributes[v_y];}

	void setvelocity_x(const double& velocity_x){attributes[v_velocity_x]=velocity_x;}
	const double getvelocity_x()const{return attributes[v_velocity_x];}

	void setvelocity_y(const double& velocity_y){attributes[v_velocity_y]=velocity_y;}
	const double getvelocity_y()const{return attributes[v_velocity_y];}

	void setpersonal_x(const double& p_record){personal_record[v_x]=p_record;}
	const double getpersonal_x()const{return personal_record[v_x];}

	void setpersonal_y(const double& p_record){personal_record[v_y]=p_record;}
	const double getpersonal_y()const{return personal_record[v_y];}

	virtual void update(double (&)[_Coordinates], double (&)[_Coordinates], Rink&){}
	virtual void print(ostream&)const;

private:
	unsigned player_id;
	double attributes[_Attributes]; //[x-coordinate , y-coordinate , velocity_x , velocity_y]
	double personal_record[_Coordinates];

	Player(const Player&);
	
	void copyFrom(const Player&);

};

#endif