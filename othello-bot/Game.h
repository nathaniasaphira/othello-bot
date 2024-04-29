#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "Board.h"
#include "Bot.h"
#include "Model.h"
#include "Player.h"


class Game
{
public:
	void Start();

private:
	void initialState(Board* board, Player* player, Bot* bot);
	
	void displayHeader();
	void displayInputInfo();
};

