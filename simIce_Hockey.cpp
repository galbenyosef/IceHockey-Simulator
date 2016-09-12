#include "simIce_Hockey.h"

simIceHockey::simIceHockey(char* &config_file,char* &init_file)
	:players_count(0)
{
	config(config_file);
	initialize(init_file,rink);
}

simIceHockey::~simIceHockey()
{
	cout << "closed game" << endl;
}

BstNode<Player>* simIceHockey::getglobal(BstNode<Player>* node,double* euclidean) const
{
    BstNode<Player>* ret_l;
	BstNode<Player>* ret_r;   
    double global_r, global_l;   /* variables in order to save grade */
    if(!node)              /* if tree is empty */
    {
        return NULL;
    }

    *euclidean = EuclideanDistance(node->getData()->getx(),node->getData()->gety(),
		target_point[v_x],target_point[v_y]);  /* calculate grade on course */
    ret_l = getglobal(node->getLeft(), &global_l);	/* call left node */
	if (!ret_l)
		global_l=90;
    ret_r = getglobal(node->getRight(), &global_r);	/* call right node */
	if (!ret_r)
		global_r=90;
    if(ret_l && (global_l < global_r) && (global_l < *euclidean))  /* check grade from left node */
        return ret_l;	/* return ID from left node */

    if(ret_r && (global_r < global_l) && (global_r < *euclidean))  /* check grade from right node */
        return ret_r;	/* return ID from right node */

    return node;	/* return source ID */
}

void simIceHockey::updateRecursive(BstNode<Player>* node,double (&global)[_Coordinates],Rink& _rink) 
{
	if ( node == NULL )
	{
		return;
	}
	updateRecursive(node->getLeft(),global,_rink);
	node->getData()->update(target_point,global,_rink);
	updateRecursive(node->getRight(),global,_rink);
}

unsigned simIceHockey::start()
{
	double global;
	BstNode<Player>* global_node;
	bool target_point_is_empty = 1;
	unsigned k=0;
	while (k<iterations)
	{
		if (!target_point_is_empty)
			return k;
		global_node = getglobal(team.root(),&global);
		double global_coordinates[_Coordinates];
		global_coordinates[v_x]=global_node->getData()->getx();
		global_coordinates[v_y]=global_node->getData()->gety();
		updateRecursive(team.root(),global_coordinates,rink);
		if (rink(target_point[v_x],target_point[v_y]) > 0)
			target_point_is_empty = 0;
		++k;
	}
	return k;
}

void simIceHockey::print() const
{
	printRecursive( team.root() );
}

void simIceHockey::printRecursive(BstNode<Player>* root) const
{
	if ( root == NULL )
	{
		return;
	}
	printRecursive(root->getLeft());
	cout << *root->getData();
	printRecursive(root->getRight());
}

void simIceHockey::config(char* &config_file)
{
	string buffer;
	ifstream myStream(config_file);

	if (!myStream.is_open())
	{
		cout << "Error opening config file" << endl;
		myStream.close();
		exit(0);
	}

	while( !myStream.eof() )
	{
		myStream >> target_point[v_x] >> target_point[v_y] >> iterations;
		if (myStream.fail())
		{
			myStream.close();
			exit(0);
		}
		//correct if outbound
		if (target_point[v_x]>FIELD_XMAX)
			target_point[v_x]=FIELD_XMAX;
		if (target_point[v_x]<0)
			target_point[v_x]=0;
		if (target_point[v_y]>FIELD_YMAX)
			target_point[v_y]=FIELD_YMAX;
		if (target_point[v_y]<0)
			target_point[v_y]=0;
	}
	myStream.close();
}

void simIceHockey::initialize(char* &init_file,Rink& _rink) //as makeTeam()
{
	char position;
	ifstream myStream;
	double vector[_Attributes];
	unsigned total_players;

	myStream.open(init_file);
	if (!myStream.is_open())
	{
		cout << "Error opening init file" << endl;
		exit(0);
	}

	myStream >> total_players;
	if (myStream.fail() || total_players < 0 || total_players > 100)
	{
		myStream.close();
		exit(0);
	}
	while (!myStream.eof())
	{
		myStream >> position >> vector[v_x] >> vector[v_y] >> vector[v_velocity_x] >> vector[v_velocity_y];
		if (myStream.fail())
		{
			team.Clear();
			myStream.close();
			exit(0);
		}
		//correct if outbound
		if (vector[v_x]>FIELD_XMAX)
			vector[v_x]=FIELD_XMAX;
		if (vector[v_x]<0)
			vector[v_x]=0;
		if (vector[v_y]>FIELD_YMAX)
			vector[v_y]=FIELD_YMAX;
		if (vector[v_y]<0)
			vector[v_y]=0;
		switch (position)
		{
			case ('G'):
				team.Insert(new Goalie(++players_count,vector));
				_rink.inc(vector[v_x],vector[v_y]);
				break;
			case ('D'):
				team.Insert(new Defensemen(++players_count,vector));
				_rink.inc(vector[v_x],vector[v_y]);
				break;
			case ('F'):
				team.Insert(new Forward(++players_count,vector));
				_rink.inc(vector[v_x],vector[v_y]);
				break;
			default:
				exit (0);
		}
	}
	if (total_players != players_count)
	{
		team.Clear();
		myStream.close();
		exit(0);
	}
	myStream.close();
}
