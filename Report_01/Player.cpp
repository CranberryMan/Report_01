#include "Player.h"

/// <summary>
/// �ʱ� ���� ���ÿ�
/// </summary>
void Player::setPotion(int count, int* p_HPPotion, int* p_MPPotion)
{
	*p_HPPotion = count;
	*p_MPPotion = count;

	std::cout << "* ������ ���޵Ǿ����ϴ�. (HP, MP ���� �� " << count << "��)" << std::endl;
}
/// <summary>
/// ������ ���� ������ �³� Ȯ�ο�
/// </summary>
void Player::getPotion()
{
	std::cout << "HP Potion : " << this->hpPotion << std::endl;
	std::cout << "MP Potion : " << this->mpPotion << std::endl;
}

void Player::usePotion(STATUS _enum)
{
	if (_enum == HP)
	{
		if (this->hpPotion < 1)
		{
			std::cout << "������ �����մϴ�." << std::endl;
			return;
		}
		std::cout << "* HP�� 20 ȸ���Ǿ����ϴ�. ������ 1�� �����˴ϴ�." << std::endl;
		this->hpPotion--;
		status[STATUS::HP] += POTION_POWER;
		std::cout << "���� HP : " << status[STATUS::HP] << std::endl;
		std::cout << "���� ���� �� : " << this->hpPotion << std::endl;
	}
	else if (_enum == MP)
	{
		if (this->mpPotion < 1)
		{
			std::cout << "������ �����մϴ�." << std::endl;
			return;
		}
		std::cout << "* MP�� 20 ȸ���Ǿ����ϴ�. ������ 1�� �����˴ϴ�." << std::endl;
		this->mpPotion--;
		status[STATUS::MP] += POTION_POWER;
		std::cout << "���� HP : " << status[STATUS::MP] << std::endl;
		std::cout << "���� ���� �� : " << this->mpPotion << std::endl;
	}

	return;
}

/// <summary>
/// ���� ���� ���� ����� �ΰ����� �ִٰ� �ϴµ� ������ �ǹ��ϴ��� �� �𸣰ڴ�...
/// </summary>
void Player::enforceStat(STATUS _enum)
{
	std::string stat = "";
	int nowStat = 0;
	if (_enum == HP)
	{
		stat = "HP";
		this->status[STATUS::HP] *= 2;
		nowStat = this->status[STATUS::HP];
	}
	else if (_enum == MP)
	{
		stat = "MP";
		this->status[STATUS::MP] *= 2;
		nowStat = this->status[STATUS::MP];
	}
	std::cout << "* " << stat << "�� 2��� �����Ǿ����ϴ�." << std::endl;
	std::cout << "���� " << stat << " : " << nowStat << std::endl;
}
void Player::defaultAttack()
{
	if (status[STATUS::MP] < 50)
	{
		std::cout << "��ų ����� �Ұ��մϴ�." << std::endl;
		std::cout << "���� MP ���� �� : " << this->mpPotion << std::endl;
		return;
	}
	status[STATUS::MP] -= 50;
	std::cout << "��ų�� ����Ͽ� MP�� 50 �Ҹ�Ǿ����ϴ�." << std::endl;
	std::cout << "���� MP : " << status[STATUS::MP] << std::endl;

	return;
}

void Player::specialAttack()
{
	if (status[STATUS::MP] <= 0)
	{
		std::cout << "��ų ����� �Ұ��մϴ�." << std::endl;
		std::cout << "���� MP ���� �� : " << this->mpPotion << std::endl;
		return;
	}
	status[STATUS::MP] /= 2;
	std::cout << "��ų�� ����Ͽ� MP�� ���� �Ҹ�Ǿ����ϴ�." << std::endl;
	std::cout << "���� MP : " << status[STATUS::MP] << std::endl;
	return;
}