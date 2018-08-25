#include "stdafx.h"
#include "Simulation.h"


Simulation::Simulation(double startX, double startY, double startZ, double startP, double startQ, double startR, double startVelocity, double startVerticalVelocity)
{
	lander = new Lander();
	lander->move(startX, startY, startZ);
	lander->tilt(startP, startQ, startR);
	lander->setVelocity(0, startVerticalVelocity, startVelocity);
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
double Simulation::getVelocityPangle()
{
	return lander->getVelocityPangle();
}
double Simulation::getVelocityQangle()
{
	return lander->getVelocityQangle();
}

int Simulation::getLanded()
{
	return lander->getLanded();
}

double Simulation::getThrust(int engine)
{
	return lander->getThrust(engine);
}

double Simulation::getXaccel()
{
	return lander->getXaccel();
}

double Simulation::getYaccel()
{
	return lander->getYaccel();
}

double Simulation::getZaccel()
{
	return lander->getZaccel();
}

unsigned int Simulation::getLanderTime()
{
	return lander->getTime();
}
