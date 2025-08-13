#pragma once
#include <iostream>
#include <memory>
#include <string>
#define POTION_POWER 20
#define SKILL_MP 50

enum STATUS
{
	HP,
	MP,
	ATK,
	DEF,
};

class Player
{
public:
	Player(int _hp = 50, int _mp = 50, int _atk = 1, int _def = 1) :
		hpPotion(0),
		mpPotion(0)
	{
		status[STATUS::HP] = _hp;
		status[STATUS::MP] = _mp;
		status[STATUS::ATK] = _atk;
		status[STATUS::DEF] = _def;
	};
	~Player()
	{
		std::cout << "player out" << std::endl;
	};
	void setPotion(int count, int* p_HPPotion, int* p_MPPotion);
	void getPotion();
	int* getHpPotion() { return &this->hpPotion; };
	int* getMpPotion() { return &this->mpPotion; };
	void usePotion(STATUS _enum);
	void enforceStat(STATUS _enum);
	void defaultAttack();
	void specialAttack();

private:
	int status[STATUS::DEF + 1]{};
	int hpPotion;
	int mpPotion;
};

