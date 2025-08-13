#include "Player.h"

/// <summary>
/// 초기 포션 세팅용
/// </summary>
void Player::setPotion(int count, int* p_HPPotion, int* p_MPPotion)
{
	*p_HPPotion = count;
	*p_MPPotion = count;

	std::cout << "* 포션이 지급되었습니다. (HP, MP 포션 각 " << count << "개)" << std::endl;
}
/// <summary>
/// 디버깅용 포션 가진게 맞나 확인용
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
			std::cout << "포션이 부족합니다." << std::endl;
			return;
		}
		std::cout << "* HP가 20 회복되었습니다. 포션이 1개 차감됩니다." << std::endl;
		this->hpPotion--;
		status[STATUS::HP] += POTION_POWER;
		std::cout << "현재 HP : " << status[STATUS::HP] << std::endl;
		std::cout << "남은 포션 수 : " << this->hpPotion << std::endl;
	}
	else if (_enum == MP)
	{
		if (this->mpPotion < 1)
		{
			std::cout << "포션이 부족합니다." << std::endl;
			return;
		}
		std::cout << "* MP가 20 회복되었습니다. 포션이 1개 차감됩니다." << std::endl;
		this->mpPotion--;
		status[STATUS::MP] += POTION_POWER;
		std::cout << "현재 HP : " << status[STATUS::MP] << std::endl;
		std::cout << "남은 포션 수 : " << this->mpPotion << std::endl;
	}

	return;
}

/// <summary>
/// 과제 설명에 연산 방법이 두가지가 있다고 하는데 무엇을 의미하는지 잘 모르겠다...
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
	std::cout << "* " << stat << "가 2배로 증가되었습니다." << std::endl;
	std::cout << "현재 " << stat << " : " << nowStat << std::endl;
}
void Player::defaultAttack()
{
	if (status[STATUS::MP] < 50)
	{
		std::cout << "스킬 사용이 불가합니다." << std::endl;
		std::cout << "남은 MP 포션 수 : " << this->mpPotion << std::endl;
		return;
	}
	status[STATUS::MP] -= 50;
	std::cout << "스킬을 사용하여 MP가 50 소모되었습니다." << std::endl;
	std::cout << "현재 MP : " << status[STATUS::MP] << std::endl;

	return;
}

void Player::specialAttack()
{
	if (status[STATUS::MP] <= 0)
	{
		std::cout << "스킬 사용이 불가합니다." << std::endl;
		std::cout << "남은 MP 포션 수 : " << this->mpPotion << std::endl;
		return;
	}
	status[STATUS::MP] /= 2;
	std::cout << "스킬을 사용하여 MP가 절반 소모되었습니다." << std::endl;
	std::cout << "현재 MP : " << status[STATUS::MP] << std::endl;
	return;
}