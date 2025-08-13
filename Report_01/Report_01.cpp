#include <iostream>
#include "Logic.h"
#include "Player.h"

/// <summary>
/// 메인 함수 진입
/// </summary>
int main()
{
	Logic* logic = new Logic();
	logic->setPlayer();
	logic->mainStatusLogic();

	delete logic;
	
	return 0;
}