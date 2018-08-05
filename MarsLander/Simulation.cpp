#include "stdafx.h"
#include "Simulation.h"


Simulation::Simulation()
{
	lander = new Lander();
}
Simulation::~Simulation()
{
	delete lander;
}

void Simulation::update()
{
	lander->update();
}