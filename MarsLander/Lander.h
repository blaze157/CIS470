/*
Lander class stores the nodes of the lander, gathers, stores, and sends
sensor data, and runs the logic for the Guidance Control
*/
#pragma once

#include <vector>
#include "Node.h"

class Lander
{
private:
	std::vector<Node*> nodes;

	void correctAngle();
	void sendData();
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
	double getAltitude();
	
	void flightController();

	void update();
};

