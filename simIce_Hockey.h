#ifndef simIce_Hockey_H_
#define simIce_Hockey_H_

#include "Player.h"
#include "Tree.h"
#include "Goalie.h"
#include "Defensemen.h"
#include "Forward.h"

using namespace std;

class simIceHockey{
public:
	simIceHockey(char* &,char* &);
	~simIceHockey();

	unsigned start();
	void print()const;

private:
	Rink rink;
	Tree<Player> team;
	double target_point[_Coordinates];
	unsigned iterations;
	unsigned players_count;
 
	void config(char* &);
	void initialize(char* &,Rink&);
	
	BstNode<Player>* getglobal(BstNode<Player>*,double*) const;
	void updateRecursive(BstNode<Player>*,double (&)[_Coordinates],Rink&);
	void printRecursive(BstNode<Player>*) const;

	//Big Three Disabled
	simIceHockey(const simIceHockey&);
	simIceHockey& operator=(const simIceHockey&);

};



#endif