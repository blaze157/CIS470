#include "stdafx.h"
#include "Node.h"

#include <cmath>

#include <iostream>

double square(double num)
{
	return num*num;
}

Node::Node(double x, double y, double z, double mass)
{
	this->x = x;
	this->y = y;
	this->z = z;

	if (mass > 0)
	{
		this->mass = mass;
	}
	else
	{
		throw std::invalid_argument("Node mass must be greater than 0");
	}
}

void Node::move(double x, double y, double z)
{
	this->x += x;
	this->y += y;
	this->z += z;
}
void Node::setVeloctiy(double xvel, double yvel, double zvel)
{
	this->xvel = xvel;
	this->yvel = yvel;
	this->zvel = zvel;
}

void Node::connect(Node* to)
{
	connections.push_back(to);
	to->connections.push_back(this);

	double relativeX = (to->x - x);
	double relativeY = (to->y - y);
	double relativeZ = (to->z - z);
	double distance = sqrt(square(relativeX) + square(relativeY) + square(relativeZ));

	distances.push_back(distance);
	to->distances.push_back(distance);
}

void Node::force(double xForce, double yForce, double zForce)
{
	xvel += xForce / mass;
	yvel += yForce / mass;
	zvel += zForce / mass;
}
void Node::gravity(double planetMass)
{
	//12.1 feet/sec/sec
	//divided by 1000 for ms
	force(0, -12.1/1000, 0);
}

void Node::restrain()//Move nodes to where they should be
{
	for (int i = 0; i<connections.size(); i++)
	{
		if (connections[i])
		{
			double relativeX = (connections[i]->x - x);
			double relativeY = (connections[i]->y - y);
			double relativeZ = (connections[i]->z - z);

			double relativeXvel = (connections[i]->xvel - xvel);
			double relativeYvel = (connections[i]->yvel - yvel);
			double relativeZvel = (connections[i]->zvel - zvel);

			double distance = sqrt(square(relativeX) + square(relativeY) + square(relativeZ));
			double nextDist = sqrt(square(relativeX + relativeXvel) + square(relativeY + relativeYvel) + square(relativeZ + relativeZvel));

			//std::cout << i << " expected: " << distances[i] << " actual: " << distance << std::endl;
			if (abs(distances[i] - distance) > 5)
			{
				std::cout << i << " expected: " << distances[i] << " actual: " << distance << std::endl;
			}

			double relativeVel = nextDist - distance;

			//apply force equal to half of the extra distance
			double xForce = relativeX*(1-(distances[i] / distance)) / 10;
			double yForce = relativeY*(1-(distances[i] / distance)) / 10;
			double zFroce = relativeZ*(1-(distances[i] / distance)) / 10;

			//The ifs allow the particles to only restrain when actively moving in the wrong direction
			//It prevents the particles from vibrating back and forth
			if (distance>distances[i] && relativeVel>0)
			{
				force(xForce, yForce, zFroce);
				connections[i]->force(-xForce, -yForce, -zFroce);
			}
			if (distance<distances[i] && relativeVel<0)
			{
				force(xForce, yForce, zFroce);
				connections[i]->force(-xForce, -yForce, -zFroce);
			}
		}
	}
	std::cout << std::endl;
}
void Node::update()//advance node one tick
{
	x += xvel;
	y += yvel;
	z += zvel;
}

double Node::getX()
{
	return x;
}
double Node::getY()
{
	return y;
}
double Node::getZ()
{
	return z;
}

double Node::getVelocity()
{
	return sqrt(square(xvel) + square(yvel) + square(zvel));
}