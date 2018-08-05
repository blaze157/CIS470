#include "stdafx.h"
#include "Lander.h"


Lander::Lander()
{
	//center
	nodes.push_back(new Node(0, 0, 0, 1));//0
	//top
	nodes.push_back(new Node(0, 2.8, 0, 1));//1

	//sides
	nodes.push_back(new Node(-7, 0, 0, 1));//2
	nodes.push_back(new Node(-3.5, 0, 6.0622, 1));//3
	nodes.push_back(new Node(3.5, 0, 6.0622, 1));//4
	nodes.push_back(new Node(-7, 0, 0, 1));//5
	nodes.push_back(new Node(3.5, 0, -6.0622, 1));//6
	nodes.push_back(new Node(-3.5, 0, -6.0622, 1));//7

	//top sides
	nodes.push_back(new Node(-4.9, 2.8, 0, 1));//8
	nodes.push_back(new Node(-2.45, 2.8, 4.2435, 1));//9
	nodes.push_back(new Node(2.45, 2.8, 4.2435, 1));//10
	nodes.push_back(new Node(4.9, 2.8, 0, 1));//11
	nodes.push_back(new Node(2.45, 2.8, -4.2435, 1));//12
	nodes.push_back(new Node(2.45, 2.8, -4.2435, 1));//13

	//feet
	nodes.push_back(new Node(-2.45, -3.5, -1.4073, 1));//14
	nodes.push_back(new Node(2.45, -3.5, -1.4073, 1));//15
	nodes.push_back(new Node(0, -3.5, 2.8363, 1));//16

	//bottom thrusters
	nodes.push_back(new Node(-2.45, 0, 1.4073, 1));//17
	nodes.push_back(new Node(0, 0, -2.8363, 1));//18
	nodes.push_back(new Node(2.45, 0, 1.4073, 1));//19

	//rotation thrusters
	nodes.push_back(new Node(-4.7358, 1.4, -2.7605, 1));//20
	nodes.push_back(new Node(0, 1.4, 5.1529, 1));//21
	nodes.push_back(new Node(4.7358, 1.4, -2.7605, 1));//22

	//connections
	//center to top
	nodes[0]->connect(nodes[1]);

	//top to top sides
	for(int i = 2; i <= 7; i++)
		nodes[0]->connect(nodes[i]);

	//center to sides
	for (int i = 8; i <= 13; i++)
		nodes[0]->connect(nodes[i]);

	//sides to top sides
	for (int i = 2; i <= 7; i++)
		nodes[i]->connect(nodes[i+6]);

	//sides to sides
	for (int i = 2; i <= 7; i++)
		nodes[i]->connect(nodes[i<7 ? i+1 : 2]);

	//top sides to top sides
	for (int i = 8; i <= 13; i++)
		nodes[i]->connect(nodes[i<13 ? i+1 : 8]);

	//sides to top sides crossed
	//keeps top of lander from twisting
	for (int i = 2; i <= 7; i++)
		nodes[i]->connect(nodes[i<7 ? i+7 : 8]);

	//feet to body
	nodes[14]->connect(nodes[0]);
	nodes[14]->connect(nodes[2]);
	nodes[14]->connect(nodes[7]);

	nodes[15]->connect(nodes[0]);
	nodes[15]->connect(nodes[3]);
	nodes[15]->connect(nodes[4]);

	nodes[16]->connect(nodes[0]);
	nodes[16]->connect(nodes[5]);
	nodes[16]->connect(nodes[6]);

	//bottom thrusters to body
	nodes[17]->connect(nodes[0]);
	nodes[17]->connect(nodes[2]);
	nodes[17]->connect(nodes[3]);

	nodes[18]->connect(nodes[0]);
	nodes[18]->connect(nodes[4]);
	nodes[18]->connect(nodes[5]);

	nodes[19]->connect(nodes[0]);
	nodes[19]->connect(nodes[6]);
	nodes[19]->connect(nodes[7]);

	//rotation thrusters to body
	nodes[20]->connect(nodes[2]);
	nodes[20]->connect(nodes[7]);
	nodes[20]->connect(nodes[8]);
	nodes[20]->connect(nodes[13]);

	nodes[21]->connect(nodes[3]);
	nodes[21]->connect(nodes[4]);
	nodes[21]->connect(nodes[9]);
	nodes[21]->connect(nodes[10]);

	nodes[22]->connect(nodes[5]);
	nodes[22]->connect(nodes[6]);
	nodes[22]->connect(nodes[11]);
	nodes[22]->connect(nodes[12]);
}


Lander::~Lander()
{
	for (int i = 0; i < nodes.size(); i++)
	{
		delete nodes[i];
	}
	nodes.clear();
}

void Lander::sendData()
{
	//upload sensor data to the server
}

double Lander::getPangle()
{
	//get angle in P demention (see diagram in files)
	//should measure angle between Nodes[0] and Nodes[1]
	return 0;
}
double Lander::getQangle()
{
	//get angle in Q demention (see diagram in files)
	//should measure angle between Nodes[0] and Nodes[1]
	return 0;
}
double Lander::getRangle()
{
	//get angle in R demention (see diagram in files)
	//should measure angle between Nodes[0] and Nodes[1]
	return 0;
}

double Lander::getXpos()
{
	return nodes[0]->getX();
}
double Lander::getYpos()
{
	return nodes[0]->getY();
}
double Lander::getZpos()
{
	return nodes[0]->getZ();
}

double Lander::getVelocity()
{
	return nodes[0]->getVelocity();
}
double Lander::getAltitude()
{
	//should get distance from the ground
	//probably the same as y position
	return 0;
}

void Lander::update()
{
	for (int i = 0; i < nodes.size(); i++)
	{
		nodes[i]->update();
	}
}