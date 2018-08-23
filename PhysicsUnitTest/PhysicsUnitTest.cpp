// PhysicsUnitTest.cpp
//

#include "stdafx.h"
#include "../MarsLander/Simulation.h"
#include "../MarsLander/SQLConnect.h"

#include <iostream>
#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>


int main()
{
	Simulation simulation(0, 10000, 0, 0, 0, 0, 1000, -100);

	std::cout << simulation.getXpos() << "\t" << simulation.getYpos() << "\t" << simulation.getZpos() << "\t"
		<< simulation.getPangle() << "\t" << simulation.getQangle()+1.5 << "\t" << simulation.getRangle() << "\t" << simulation.getLanderTime() << "\t" << simulation.getVelocityPangle() << "\t" << simulation.getVelocityQangle() << "\t" << simulation.getVelocity() << std::endl;
	while (getchar() != 'q')
	{
		for(int i=0; i<100; i++)
		simulation.update();
		std::cout << "\n" << simulation.getXpos() << "\t" << simulation.getYpos() << "\t" << simulation.getZpos() << "\t"
			<< simulation.getPangle() << "\t" << simulation.getQangle()+1.5 << "\t" << simulation.getRangle() << "\t" << simulation.getLanderTime() << "\t" << simulation.getVelocityPangle() << "\t" << simulation.getVelocityQangle() << "\t" << simulation.getVelocity() << std::endl;
	}




	/*std::cout << "trying to connect" << std::endl;

	SQLConnector connector(L"cis470.c7yjsuncshex.us-east-1.rds.amazonaws.com", L"MarsLander", L"12345678");

	std::cout << "trying to execute" << std::endl;

	std::cout << connector.execute(L"select @@version");

	std::cout << "done" << std::endl;
	getchar();*/

    return 0;
}

