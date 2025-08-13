#include "Logic.h"

/// <summary>
/// 플레이어 객체 설정
/// hp, mp, atk, def의 기본 스탯을 입력 받고
/// 초기 포션 5개를 세팅한다.
/// </summary>
void Logic::setPlayer()
{
	// std::cout << "set Player Start" << std::endl;
	int hp = 0, mp = 0, atk = 0, def = 0;
	bool flag = true;
	while (flag)
	{
		std::cout << "HP와 MP를 입력해 주세요 : ";
		std::cin >> hp >> mp;
		if (hp <= 30 && mp <= 30)
		{
			std::cout << "HP나 MP의 값이 너무 작습니다. 다시 입력해주세요." << std::endl;
			std::cout << "hint! 31이상";
		}
		else
			flag = false;
	}
	flag = true;
	while (flag)
	{
		std::cout << "공격력과 방어력을 입력해 주세요 : ";
		std::cin >> atk >> def;
		if (hp <= 0 && mp <= 0)
		{
			std::cout << "ATK나 DEF의 값이 너무 작습니다. 다시 입력해주세요." << std::endl;
			std::cout << "hint! 1이상";
		}
		else
			flag = false;
	}

	// 디버깅때 써봄
	// int hp = 50, mp = 50, atk = 30, def = 30;

	nowPlayer = new Player(hp, mp, atk, def);
	nowPlayer->setPotion(5, nowPlayer->getHpPotion(), nowPlayer->getMpPotion());
	
	// 디버깅때 써봄
	// nowPlayer->getPotion();
	
	return;
}

/// <summary>
/// 스탯 관리 시스템
/// </summary>
void Logic::mainStatusLogic()
{
	/// 플레이어 체크
	if (!nowPlayer)
	{
		std::cout << "PLAYER ERROR" << std::endl;
		return;
	}

	std::cout << "<스탯 관리 시스템>" << std::endl;
	std::cout << "1. HP 회복" << std::endl;
	std::cout << "2. MP 회복" << std::endl;
	std::cout << "3. HP 강화" << std::endl;
	std::cout << "4. MP 강화" << std::endl;
	std::cout << "5. 공격 스킬 사용" << std::endl;
	std::cout << "6. 필살기 사용" << std::endl;
	std::cout << "7. 나가기" << std::endl;
	bool logicFlag = true;
	while (logicFlag)
	{
		int chooseNumber = 0;
		std::cout << "번호를 선택해 주세요 : ";
		std::cin >> chooseNumber;
		switch (chooseNumber)
		{
		case 1:
			nowPlayer->usePotion(STATUS::HP);
			break;
		case 2:
			nowPlayer->usePotion(STATUS::MP);
			break;
		case 3:
			nowPlayer->enforceStat(STATUS::HP);
			break;
		case 4:
			nowPlayer->enforceStat(STATUS::MP);
			break;
		case 5:
			nowPlayer->defaultAttack();
			break;
		case 6:
			nowPlayer->specialAttack();
			break;
		case 7:
		{
			std::cout << "7. 나가기" << std::endl;
			logicFlag = false;
		}
			break;
		default:
		{
			std::cout << "올바른 숫자를 입력해 주세요." << std::endl;
			break;
		}
		}

	}
	return;
}