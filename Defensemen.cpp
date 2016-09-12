#include "Defensemen.h"

const double Defensemen::alpha = 0.01;
const double Defensemen::beta = -0.1;
const double Defensemen::gamma = -0.25;


Defensemen::Defensemen(unsigned& id,double (&attr)[_Attributes]):Player(id,attr)
{

}

Defensemen::~Defensemen()
{

}

void Defensemen::print(ostream&)const
{
	cout << "D " ; Player::print(cout);
}

void Defensemen::update(double (&target_point)[_Coordinates], double (&global)[_Coordinates], Rink& _rink)
{
	double new_velocity_x; //as v+1,x
	double new_velocity_y; //as v+1,y
	// global; //y(t) global
	double new_personal; //yi(t) personal
	double old_personal;
	double random1,random2; //r1 and r2
	
	//r1 and r2
	std::srand((unsigned int)time(NULL));
	random1 = ((double)(rand())/RAND_MAX);
	random2 = ((double)(rand())/RAND_MAX);
	//Mathematical expression #2 for X
	new_velocity_x = ( alpha * getvelocity_x() + ( beta * random1 * ( getpersonal_x()-getx() ) )
		+ ( gamma * random2 * ( global[v_x]-getx() ) ) );
	//Mathematical expression #2 for Y
	new_velocity_y = ( alpha * getvelocity_y() + ( beta * random1 * ( getpersonal_y()-gety() ) )
		+ ( gamma * random2 * ( global[v_y]-gety() ) ) );

	_rink.dec( getx(), gety() );

	//Mathematical expression #1 for X
	setx( getx() + new_velocity_x );
	if (getx() > FIELD_XMAX)
		setx(FIELD_XMAX);
	if (getx() < 0 )
		setx(0);
	//Mathematical expression #1 for Y
	sety( gety() + new_velocity_y );
	if (gety() > FIELD_YMAX)
		sety(FIELD_YMAX);
	if (gety() < 0 )
		sety(0);
	_rink.inc( getx(), gety() );

	new_personal = EuclideanDistance(getx(),gety(),target_point[v_x],target_point[v_y]);
	old_personal = EuclideanDistance(getpersonal_x(),getpersonal_y(),target_point[v_x],target_point[v_y]);

	//each personal record is saving its lowest distance from target_point
	if (new_personal < old_personal)
	{
		setpersonal_x( getx() );
		setpersonal_y( gety() );
	}
}