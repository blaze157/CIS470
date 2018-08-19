#include "stdafx.h"
#include "Node.h"

#include <cmath>
#include "math.h"

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
	double poundsForce = 32.1740486;//convert pounds force to pounds mass
	xvel += xForce * poundsForce / mass / 1000 / 1000;//1000 for sec to ms
	yvel += yForce * poundsForce / mass / 1000 / 1000;
	zvel += zForce * poundsForce / mass / 1000 / 1000;
}
void Node::gravity()
{
	//12.1 feet/sec/sec on mars
	yvel -= 12.1 / 1000 / 1000;
}

void Node::restrain()//Move nodes to where they should be
{
	//strength of node connection
	//low for squishy
	//high for ridgid but twitchy
	const double scale = 10000;
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
			double relativeVel = nextDist - distance;

			//apply force proportional to the extra distance
			double xForce = (relativeX / distance) * square(distance - distances[i]) * scale;
			double yForce = (relativeY / distance) * square(distance - distances[i]) * scale;
			double zForce = (relativeZ / distance) * square(distance - distances[i]) * scale;

			//The ifs allow the nodes to only restrain when actively moving in the wrong direction
			//It prevents the particles from vibrating back and forth
			if (distance>distances[i] && relativeVel>0)
			{
				force(xForce, yForce, zForce);
				connections[i]->force(-xForce, -yForce, -zForce);
			}
			if (distance<distances[i] && relativeVel<0)
			{
				force(-xForce, -yForce, -zForce);
				connections[i]->force(xForce, yForce, zForce);
			}
		}
	}
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

double Node::getXVelocity()
{
	return xvel;
}
double Node::getYVelocity()
{
	return yvel;
}
double Node::getZVelocity()
{
	return zvel;
}