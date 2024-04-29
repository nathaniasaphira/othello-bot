#pragma once

#include <iostream>
#include <vector>

#include "Model.h"

class Board
{
private:

public:
	Board();

	int pieces[8][8];
	void setPiece(int row, int col, int value);

	void Display(int pieces[8][8]);
	int FlipDisk(int pieces[8][8], std::vector<Possible>& moveflip, Possible input_now, int turn, int* flipped);
};