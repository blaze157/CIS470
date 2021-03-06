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
	Simulation simulation(0, 5, 0, 0, 0, 0, 0, 0);

	std::cout << simulation.getXpos() << "\t" << simulation.getYpos() << "\t" << simulation.getZpos() << "\t"
		<< simulation.getPangle() << "\t" << simulation.getQangle()+1.5 << "\t" << simulation.getRangle() << "\t" << simulation.getLanderTime() << "\t" << simulation.getVelocityPangle() << "\t" << simulation.getVelocityQangle() << "\t" << simulation.getVelocity() << std::endl;
	while (getchar() != 'q')
	{
		for(int i=0; i<100; i++)
		simulation.update();
		std::cout << "\n" << simulation.getXpos() << "\t" << simulation.getYpos() << "\t" << simulation.getZpos() << "\t"
			<< simulation.getPangle() << "\t" << simulation.getQangle()+1.5 << "\t" << simulation.getRangle() << "\t" << simulation.getLanderTime() << "\t" << simulation.getVelocityPangle() << "\t" << simulation.getVelocityQangle() << "\t" << simulation.getVelocity() << "\t" << simulation.getLanded() << std::endl;
	}


	/*std::cout << "trying to connect" << std::endl;

	SQLConnector connector(L"cis470.c7yjsuncshex.us-east-1.rds.amazonaws.com", L"MarsLander", L"12345678");

	std::cout << "trying to upload" << std::endl;

	//connector.execute(L"execute position_sp @longitude = N'0', @londirection = N'test', @latdirection = N'test';");

	std::cout << "trying to execute" << std::endl;

	std::cout << connector.execute(L"SELECT * FROM soilsample;");

	std::cout << "done" << std::endl;
	getchar();*/

    return 0;
}

