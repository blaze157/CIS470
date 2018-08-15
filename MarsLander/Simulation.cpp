#include "stdafx.h"
#include "Simulation.h"


Simulation::Simulation(double startX, double startY, double startZ, double startP, double startQ, double startR, double startVelocity, double startVerticalVelocity)
{
	lander = new Lander();
	lander->move(startX, startY, startZ);
	lander->tilt(startP, startQ, startR);
	lander->setVelocity(startVelocity, startVerticalVelocity, 0);
}
Simulation::~Simulation()
{
	delete lander;
}

void Simulation::update()
{
	lander->flightController();
	lander->update();
}

double Simulation::getPangle()
{
	return lander->getPangle();
}
double Simulation::getQangle()
{
	return lander->getQangle();
}
double Simulation::getRangle()
{
	return lander->getRangle();
}

double Simulation::getXpos()
{
	return lander->getXpos();
}
double Simulation::getYpos()
{
	return lander->getYpos();
}
double Simulation::getZpos()
{
	return lander->getZpos();
}

double Simulation::getVelocity()
{
	return lander->getVelocity();
}

unsigned int Simulation::getLanderTime()
{
	return lander->getTime();
}
