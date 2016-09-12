#include "Player.h"

//Player ctor
Player::Player()
{

}
Player::~Player()
{

}

Player::Player(unsigned& plyr_id,double (&attr)[_Attributes])
{
	player_id = plyr_id; 
	for (int i=0;i<_Attributes;i++) 
		attributes[i] = attr[i];
	personal_record[v_x]=attributes[v_x];
	personal_record[v_y]=attributes[v_y];
}

Player& Player::operator=(const Player* ao)
{ 
	if (this != *&ao)
		{copyFrom(*ao);}
	return *this;
}

void Player::copyFrom(const Player& ao)
{
	for(unsigned i=0;i<_Attributes;i++) 
		attributes[i]=ao.attributes[i];
	for(unsigned i=0;i<_Coordinates;i++)
		personal_record[i]=ao.personal_record[i];
}

bool operator==(const Player& lhs,const Player& rhs)
{
	return (lhs.player_id == rhs.player_id);
}

bool operator>(const Player& lhs,const Player& rhs)
{
	return (lhs.player_id > rhs.player_id);
}

ostream& operator<<(ostream& out, const Player& p)
{
	p.print(out);
	return out;
}

void Player::print(ostream&)const
{
	cout << ((double)((int)(getx()*100)))/100 << " " 
		<< ((double)((int)(gety()*100)))/100 << endl;
}
