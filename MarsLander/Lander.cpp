#include "stdafx.h"
#include "Lander.h"

#include "math.h"

#include <iostream>

Lander::Lander()
{
	//center
	nodes.push_back(new Node(0, 0, 0, 53));//0
	//top
	nodes.push_back(new Node(0, 2.8, 0, 53));//1

	//sides
	nodes.push_back(new Node(-7, 0, 0, 53));//2
	nodes.push_back(new Node(-3.5, 0, 6.0622, 53));//3
	nodes.push_back(new Node(3.5, 0, 6.0622, 53));//4
	nodes.push_back(new Node(7, 0, 0, 53));//5
	nodes.push_back(new Node(3.5, 0, -6.0622, 53));//6
	nodes.push_back(new Node(-3.5, 0, -6.0622, 53));//7

	//top sides
	nodes.push_back(new Node(-4.9, 2.8, 0, 53));//8
	nodes.push_back(new Node(-2.45, 2.8, 4.2435, 53));//9
	nodes.push_back(new Node(2.45, 2.8, 4.2435, 53));//10
	nodes.push_back(new Node(4.9, 2.8, 0, 53));//11
	nodes.push_back(new Node(2.45, 2.8, -4.2435, 53));//12
	nodes.push_back(new Node(-2.45, 2.8, -4.2435, 53));//13

	//feet
	nodes.push_back(new Node(-2.45, -3.5, -1.4073, 53));//14
	nodes.push_back(new Node(2.45, -3.5, -1.4073, 53));//15
	nodes.push_back(new Node(0, -3.5, 2.8363, 53));//16

	//bottom thrusters
	nodes.push_back(new Node(-2.45, 0, -1.4073, 53));//17
	nodes.push_back(new Node(0, 0, 2.8363, 53));//18
	nodes.push_back(new Node(2.45, 0, -1.4073, 53));//19

	//rotation thrusters
	nodes.push_back(new Node(-4.7358, 1.4, -2.7605, 53));//20
	nodes.push_back(new Node(0, 1.4, 5.1529, 53));//21
	nodes.push_back(new Node(4.7358, 1.4, -2.7605, 53));//22

	//connections
	//center to top
	nodes[0]->connect(nodes[1]);

	//top to top sides
	for(int i = 8; i <= 13; i++)
		nodes[1]->connect(nodes[i]);

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
		//divide by 1000 to convert to feet/millisecond
		nodes[i]->setVeloctiy(xvel / 1000, yvel / 1000, zvel / 1000);
	}
}

void Lander::sendData()
{
	connector->execute(L"some sql code");
}

double Lander::getPangle()
{
	double relativeX, relativeZ;
	relativeX = nodes[3]->getX() - nodes[7]->getX();
	relativeZ = nodes[3]->getZ() - nodes[7]->getZ();

	return atan2(relativeX, relativeZ);
}
double Lander::getQangle()
{
	double relativeX, relativeY, relativeZ;
	relativeX = nodes[3]->getX() - nodes[7]->getX();
	relativeY = nodes[3]->getY() - nodes[7]->getY();
	relativeZ = nodes[3]->getZ() - nodes[7]->getZ();

	double distance = sqrt(square(relativeZ) + square(relativeX));

	return atan2(-relativeY,distance);
}
double Lander::getRangle()
{
	double relativeX, relativeY, relativeZ;
	relativeX = nodes[2]->getX() - nodes[0]->getX();
	relativeY = nodes[2]->getY() - nodes[0]->getY();
	relativeZ = nodes[2]->getZ() - nodes[0]->getZ();

	double distance = sqrt(square(relativeZ) + square(relativeX));

	if (nodes[1]->getY() < nodes[0]->getY())//upside down?
	{
		return atan2(relativeY, -distance);//other side of circle
	}

	return atan2(relativeY, distance);
}

double Lander::getPvelocity()
{
	return circularDistance(getPangle(), previousP);
}
double Lander::getQvelocity()
{
	return getQangle() - previousQ;
}
double Lander::getRvelocity()
{
	return getRangle() - previousR;
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
	return sqrt(square(nodes[0]->getXVelocity()) + square(nodes[0]->getYVelocity()) + square(nodes[0]->getZVelocity())) * 1000;
}
double Lander::getVelocityPangle()
{
	return atan2(nodes[0]->getXVelocity(), nodes[0]->getZVelocity());
}
double Lander::getVelocityQangle()
{
	double distance = sqrt(square(nodes[0]->getZVelocity()) + square(nodes[0]->getXVelocity()));

	return atan2(distance, nodes[0]->getYVelocity())-pi/2;
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
{// sorry about the mess. This part isn't finished quite yet.
	double thrust17 = 0, thrust18 = 0, thrust19 = 0;
	double throttle = 0;

	//disconnect 5000
	if (getAltitude() < 5000 && getAltitude() > 100)
	{
		throttle = 1;// getVelocity()*sin(getVelocityPangle());

		if (throttle > 1)
			throttle = 1;

		bool fireEngines = false;

		double pDistance = circularDistance(getVelocityPangle(), getPangle());
		double desiredQ = pi / 2;
			
		if(getVelocity() > 1)
		desiredQ = getVelocityQangle() + (pi / 2 - getVelocityQangle())/1.1/* / (getVelocity())*/;

		if (abs(getPangle()) < pi / 2)// not upside down
		{
			//fire thrusters if ponted the right direction
			if (getVelocity() > 5 && getVelocityQangle() > .1
				&& (pDistance > -.1 && pDistance < .1
					&& getQangle() + pi / 2 > getVelocityQangle()	&& getRangle() + pDistance < .1
					&& getQangle() + pi / 2 < pi - getVelocityQangle()/2 && getRangle() + pDistance > -.1)
				|| (getVelocityQangle() > 1.3 && getQangle() + pi / 2 > 1.3))
			{
				fireEngines = true;
				std::cout << "!";
			}

			//std::cout << getPvelocity() << " ";
			if (((pDistance < 0 && getPvelocity() < 0)
				|| (pDistance < -1 && getPvelocity() < .001)
				|| getPvelocity() < -.001)
				/*&& getQangle() + pi / 2 < 1.5*/)
			{
				//std::cout << "r";
				rotionalThrust(600);
			}
			if (((pDistance > 0 && getPvelocity() > 0)
				|| (pDistance > 1 && getPvelocity() > -.001)
				|| getPvelocity() > .001)
				/*&& getQangle() + pi / 2 < 1.5*/)
			{
				//std::cout << "l";
				rotionalThrust(600);
			}

			if ((getQangle() + pi / 2 > desiredQ && getQvelocity() > 0)
				|| (getQangle() + pi / 2 > desiredQ + .1 && getQvelocity() > -.0001)
				|| getQvelocity() > .0001)
			{
				thrust18 += abs(getQangle() + getQvelocity() + pi / 2 - desiredQ) * 600;
			}
			if ((getQangle() + pi / 2 < desiredQ && getQvelocity() < 0)
				|| (getQangle() + pi / 2 < desiredQ - .1 && getQvelocity() < .0001)
				|| getQvelocity() < -.0001)
			{
				thrust17 += abs(getQangle() + getQvelocity() + pi / 2 - desiredQ) * 600;
				thrust19 += abs(getQangle() + getQvelocity() + pi / 2 - desiredQ) * 600;
			}

			if (getRangle() + pDistance > 0 && getRvelocity() > 0
				|| getRangle() + pDistance > .1 && getRvelocity() > -.0001)
			{
				thrust19 += abs(getRangle()) * 700;
				thrust18 += abs(getRangle()) * 200;
			}
			if (getRangle() + pDistance < 0 && getRvelocity() < 0
				|| getRangle() + pDistance < -.1 && getRvelocity() < .0001)
			{
				thrust17 += abs(getRangle()) * 700;
				thrust18 += abs(getRangle()) * 200;
			}
		}
		else
		{
			if (getQangle() < 0)
			{
				thrust17 = 600;
				thrust19 = 600;
			}
			else
			{
				thrust18 = 600;
			}
		}


		double maximum = max (max(thrust17, thrust18), thrust19);

		if (maximum > 600)
		{
			thrust17 /= maximum;
			thrust17 *= 600 * throttle;
			thrust18 /= maximum;
			thrust18 *= 600 * throttle;
			thrust19 /= maximum;
			thrust19 *= 600 * throttle;
		}

		double thrust = 600;

		if (getVelocity() * 10 < 600)
			thrust = getVelocity() * 10;

		if (fireEngines)
		{

			fireThruster(17, thrust - thrust18/2 - thrust19 / 2);
			fireThruster(18, thrust - thrust17/2 - thrust19 / 2);
			fireThruster(19, thrust - thrust17/2 - thrust18 / 2);
		}
		else
		{
			fireThruster(17, thrust17);
			fireThruster(18, thrust18);
			fireThruster(19, thrust19);
		}

	}

	if (getAltitude() < 100 && getAltitude() > 10)
	{
		if (getVelocity() > 1 && getVelocityQangle() > 1)
		{
			fireThruster(17, 600);
			fireThruster(18, 600);
			fireThruster(19, 600);
		}
	}


	time++;

	//sendData();
}

void Lander::update()
{
	previousP = getPangle();
	previousQ = getQangle();
	previousR = getRangle();
	for (int i = 0; i < nodes.size(); i++)
	{
		nodes[i]->gravity();
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