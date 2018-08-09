#pragma once

#include <vector>

class Node
{
private:
	double x, y, z;
	double xvel, yvel, zvel;
	double mass;

	std::vector<double> distances;
	std::vector<Node*> connections;

public:
	Node(double x, double y, double z, double mass);

	//This changes position ignoring physics
	void move(double x, double y, double z); 
	void setVeloctiy(double xvel, double yvel, double zvel);

	void connect(Node* to);

	void force(double xForce, double yForce, double zForce);
	void gravity(double planetMass);
	
	void restrain();//Move nodes to where they should be
	void update();//advance node one tick

	double getX();
	double getY();
	double getZ();

	double getVelocity();
};

