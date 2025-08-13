#include "Logic.h"

/// <summary>
/// �÷��̾� ��ü ����
/// hp, mp, atk, def�� �⺻ ������ �Է� �ް�
/// �ʱ� ���� 5���� �����Ѵ�.
/// </summary>
void Logic::setPlayer()
{
	// std::cout << "set Player Start" << std::endl;
	int hp = 0, mp = 0, atk = 0, def = 0;
	bool flag = true;
	while (flag)
	{
		std::cout << "HP�� MP�� �Է��� �ּ��� : ";
		std::cin >> hp >> mp;
		if (hp <= 30 && mp <= 30)
		{
			std::cout << "HP�� MP�� ���� �ʹ� �۽��ϴ�. �ٽ� �Է����ּ���." << std::endl;
			std::cout << "hint! 31�̻�";
		}
		else
			flag = false;
	}
	flag = true;
	while (flag)
	{
		std::cout << "���ݷ°� ������ �Է��� �ּ��� : ";
		std::cin >> atk >> def;
		if (hp <= 0 && mp <= 0)
		{
			std::cout << "ATK�� DEF�� ���� �ʹ� �۽��ϴ�. �ٽ� �Է����ּ���." << std::endl;
			std::cout << "hint! 1�̻�";
		}
		else
			flag = false;
	}

	// ����붧 �ẽ
	// int hp = 50, mp = 50, atk = 30, def = 30;

	nowPlayer = new Player(hp, mp, atk, def);
	nowPlayer->setPotion(5, nowPlayer->getHpPotion(), nowPlayer->getMpPotion());
	
	// ����붧 �ẽ
	// nowPlayer->getPotion();
	
	return;
}

/// <summary>
/// ���� ���� �ý���
/// </summary>
void Logic::mainStatusLogic()
{
	/// �÷��̾� üũ
	if (!nowPlayer)
	{
		std::cout << "PLAYER ERROR" << std::endl;
		return;
	}

	std::cout << "<���� ���� �ý���>" << std::endl;
	std::cout << "1. HP ȸ��" << std::endl;
	std::cout << "2. MP ȸ��" << std::endl;
	std::cout << "3. HP ��ȭ" << std::endl;
	std::cout << "4. MP ��ȭ" << std::endl;
	std::cout << "5. ���� ��ų ���" << std::endl;
	std::cout << "6. �ʻ�� ���" << std::endl;
	std::cout << "7. ������" << std::endl;
	bool logicFlag = true;
	while (logicFlag)
	{
		int chooseNumber = 0;
		std::cout << "��ȣ�� ������ �ּ��� : ";
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
			std::cout << "7. ������" << std::endl;
			logicFlag = false;
		}
			break;
		default:
		{
			std::cout << "�ùٸ� ���ڸ� �Է��� �ּ���." << std::endl;
			break;
		}
		}

	}
	return;
}