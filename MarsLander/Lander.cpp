#include "stdafx.h"
#include "Lander.h"

#include "math.h"

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
	nodes.push_back(new Node(7, 0, 0, 1));//5
	nodes.push_back(new Node(3.5, 0, -6.0622, 1));//6
	nodes.push_back(new Node(-3.5, 0, -6.0622, 1));//7

	//top sides
	nodes.push_back(new Node(-4.9, 2.8, 0, 1));//8
	nodes.push_back(new Node(-2.45, 2.8, 4.2435, 1));//9
	nodes.push_back(new Node(2.45, 2.8, 4.2435, 1));//10
	nodes.push_back(new Node(4.9, 2.8, 0, 1));//11
	nodes.push_back(new Node(2.45, 2.8, -4.2435, 1));//12
	nodes.push_back(new Node(-2.45, 2.8, -4.2435, 1));//13

	//feet
	nodes.push_back(new Node(-2.45, -3.5, -1.4073, 1));//14
	nodes.push_back(new Node(2.45, -3.5, -1.4073, 1));//15
	nodes.push_back(new Node(0, -3.5, 2.8363, 1));//16

	//bottom thrusters
	nodes.push_back(new Node(-2.45, 0, -1.4073, 1));//17
	nodes.push_back(new Node(0, 0, 2.8363, 1));//18
	nodes.push_back(new Node(2.45, 0, -1.4073, 1));//19

	//rotation thrusters
	nodes.push_back(new Node(-4.7358, 1.4, -2.7605, 1));//20
	nodes.push_back(new Node(0, 1.4, 5.1529, 1));//21
	nodes.push_back(new Node(4.7358, 1.4, -2.7605, 1));//22

	//connections
	//center to top
	nodes[0]->connect(nodes[1]);

	//top to top sides
	for(int i = 8; i <= 13; i++)
		nodes[0]->connect(nodes[i]);

	//center to sides
	for (int i = 2; i <= 7; i++)
		nodes[0]->connect(nodes[i]);

	//top to sides
	for (int i = 2; i <= 7; i++)
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

	time = 0;

	//connector = new SQLConnector(L"cis470.c7yjsuncshex.us-east-1.rds.amazonaws.com", L"MarsLander", L"12345678");
}


Lander::~Lander()
{
	for (int i = 0; i < nodes.size(); i++)
	{
		delete nodes[i];
	}
	nodes.clear();

	delete connector;
}

void Lander::move(double x, double y, double z)
{
	for (int i = 0; i < nodes.size(); i++)
	{
		nodes[i]->move(x,y,z);
	}
}
void Lander::tilt(double p, double q, double r)
{
	;
}
void Lander::setVelocity(double xvel, double yvel, double zvel)
{
	for (int i = 0; i < nodes.size(); i++)
	{
		nodes[i]->setVeloctiy(xvel, yvel, zvel);
	}
}

void Lander::sendData()
{
	connector->execute(L"some sql code");
}

double Lander::getPangle()
{
	double relativeX, relativeZ;
	relativeX = nodes[2]->getX() - nodes[0]->getX();
	relativeZ = nodes[2]->getZ() - nodes[0]->getZ();

	return atan2(relativeZ, relativeX);
}
double Lander::getQangle()
{
	double relativeX, relativeY, relativeZ;
	relativeX = nodes[1]->getX() - nodes[0]->getX();
	relativeY = nodes[1]->getY() - nodes[0]->getY();
	relativeZ = nodes[1]->getZ() - nodes[0]->getZ();

	double distance = sqrt(square(relativeZ) + square(relativeX));
	double angle = atan2(relativeZ, relativeX) + pi / 2;

	double zDist = cos(angle - getPangle()) * distance;

	return atan2(zDist, relativeY);
}
double Lander::getRangle()
{
	double relativeX, relativeY, relativeZ;
	relativeX = nodes[1]->getX() - nodes[0]->getX();
	relativeY = nodes[1]->getY() - nodes[0]->getY();
	relativeZ = nodes[1]->getZ() - nodes[0]->getZ();

	double distance = sqrt(square(relativeZ) + square(relativeX));
	double angle = atan2(relativeZ, relativeX) + pi / 2;

	double xDist = sin(angle - getPangle()) * distance;

	return atan2(xDist, relativeY);
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
	double average = 0;
	average += nodes[14]->getY();
	average += nodes[15]->getY();
	average += nodes[16]->getY();
	average /= 3;
	return average;
}

unsigned int Lander::getTime()
{
	return time;
}

void Lander::fireThruster(int number, double force)
{
	if (number >= 17 && number <= 19)
	{
		//get normalized vector from center to top
		//basicly a vector pointing up relative to the lander
		double xvect, yvect, zvect;
		xvect = (nodes[1]->getX() - nodes[0]->getX()) / 2.8;
		yvect = (nodes[1]->getY() - nodes[0]->getY()) / 2.8;
		zvect = (nodes[1]->getZ() - nodes[0]->getZ()) / 2.8;

		//apply force along vector
		nodes[number]->force(force*xvect, force*yvect, force*zvect);
	}
}
void Lander::rotionalThrust(int force)
{
	double xForce, yForce, zForce;
	double scale;

	xForce = nodes[7]->getX() - nodes[2]->getX();
	yForce = nodes[7]->getY() - nodes[2]->getY();
	zForce = nodes[7]->getZ() - nodes[2]->getZ();

	scale = sqrt(square(xForce) + square(yForce) + square(zForce));

	xForce /= scale;
	yForce /= scale;
	zForce /= scale;

	xForce *= force;
	yForce *= force;
	zForce *= force;

	nodes[20]->force(xForce, yForce, zForce);


	xForce = nodes[4]->getX() - nodes[3]->getX();
	yForce = nodes[4]->getY() - nodes[3]->getY();
	zForce = nodes[4]->getZ() - nodes[3]->getZ();

	scale = sqrt(square(xForce) + square(yForce) + square(zForce));

	xForce /= scale;
	yForce /= scale;
	zForce /= scale;

	xForce *= force;
	yForce *= force;
	zForce *= force;

	nodes[21]->force(xForce, yForce, zForce);


	xForce = nodes[6]->getX() - nodes[5]->getX();
	yForce = nodes[6]->getY() - nodes[5]->getY();
	zForce = nodes[6]->getZ() - nodes[5]->getZ();

	scale = sqrt(square(xForce) + square(yForce) + square(zForce));

	xForce /= scale;
	yForce /= scale;
	zForce /= scale;

	xForce *= force;
	yForce *= force;
	zForce *= force;

	nodes[22]->force(xForce, yForce, zForce);
}

void Lander::flightController()
{
	if (time == 0)
	{
		rotionalThrust(100);
	}

	/*if (time == 10000)
	{
		rotionalThrust(-100);
		//fireThruster(17, 23 / 3.0);
		//fireThruster(18, 1000);
		//fireThruster(19, 23 / 3.0);
	}*/

	/*if (time == 20000)
	{
		//fireThruster(17, 23 / 3.0);
		fireThruster(18, 1000);
		//fireThruster(19, 23 / 3.0);
	}*/

	time++;

	//sendData();
}

void Lander::update()
{
	for (int i = 0; i < nodes.size(); i++)
	{
		//nodes[i]->gravity();
	}
	for (int i = 0; i < nodes.size(); i++)
	{
		nodes[i]->restrain();
	}
	for (int i = 0; i < nodes.size(); i++)
	{
		nodes[i]->update();
	}
}