/*
Lander class stores the nodes of the lander, gathers, stores, and sends
sensor data, and runs the logic for the Guidance Control
*/
#pragma once

#include <vector>
#include <string>
#include "Node.h"
#include "SQLConnect.h"

class Lander
{
private:
	std::vector<Node*> nodes;

	SQLConnector* connector;

	void sendData();

	//Fire bottom thrusters 17 18 and 19
	void fireThruster(int number, double force);
	void rotionalThrust(int force);

	unsigned int time;
public:
	Lander();
	~Lander();

	//These changes proproties ignoring physics
	void move(double x, double y, double z);
	void tilt(double p, double q, double r);
	void setVelocity(double xvel, double yvel, double zvel);

	double getPangle();
	double getQangle();
	double getRangle();

	double getXpos();
	double getYpos();
	double getZpos();

	double getVelocity();
	double getVelocityPangle();
	double getVelocityQangle();

	double getAltitude();//height measured from lander feet

	unsigned int getTime();
	
	void flightController();

	void update();
};

