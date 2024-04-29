#pragma once

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

#include "Board.h"
#include "Model.h"

class Bot
{
private:
	const PieceType pieceType = PieceType::Black;
	int pieceCount;

	Board board;

public:
	PieceType getPieceType() const;

	int getPieceCount() const;
	void setPieceCount(int count);

	void PossibleInput(int pieces[8][8], std::vector<Possible>& moveflip, bool isPlayerTurn);
	int BotTurn(int pieces[8][8], std::vector<Possible>& moveflip, bool isPlayerTurn, int* black, int* white);
};

