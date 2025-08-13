#pragma once
#include <iostream>
#include <memory>
#include "Player.h"

class Logic
{
public:
	Logic()	{};
	~Logic() {
		if (nowPlayer != nullptr)
		{
			delete nowPlayer;
		}
		else
		{
			printf("\nPLAYER OUT");
		}
	};

	void setPlayer();
	void mainStatusLogic();
private:
	Player* nowPlayer = nullptr;

};

