/*
Simulation class contains all the physics logic for the simulation
*/

#pragma once

#include "Lander.h"

class Simulation
{
private:
	Lander *lander;
public:
	Simulation(double startX, double startY, double startZ, double startP, double startQ, double startR, double startVelocity, double startVerticalVelocity);
	~Simulation();

	double getXpos();
	double getYpos();
	double getZpos();

	double getVelocity();

	void update();
};

