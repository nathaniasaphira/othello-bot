#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Board.h"
#include "Model.h"

class Player
{
private:
	const PieceType pieceType = PieceType::White;
	int pieceCount;

	Board board;

public:
	Player();

	PieceType getPieceType() const;
	
	int getPieceCount() const;
	void setPieceCount(int count);

	void PlayerTurn(int pieces[8][8], std::vector<Possible>& moveflip, bool isPlayerTurn, Possible input_player, std::string input, int* black, int* white);
};

