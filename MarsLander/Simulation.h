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
	Simulation();
	~Simulation();

	void update();
};

