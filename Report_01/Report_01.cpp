#include <iostream>
#include "Logic.h"
#include "Player.h"

/// <summary>
/// ���� �Լ� ����
/// </summary>
int main()
{
	Logic* logic = new Logic();
	logic->setPlayer();
	logic->mainStatusLogic();

	delete logic;
	
	return 0;
}