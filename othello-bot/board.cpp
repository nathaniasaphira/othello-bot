#include "Board.h"

Board::Board()
{
	memset(pieces, 0, sizeof(pieces));
}

void Board::Display(int pieces[8][8]) {
	std::cout << "   ";
	//Print indeks huruf (atas)
	for (int j = 0; j < 65; j++) {
		if ((j / 8) * 8 + 4 == j)
			std::cout << (char)(j / 8 + 65);
		else
			std::cout << " ";
	}

	std::cout << std::endl;
	//Print indeks angka (kiri)
	for (int i = 0; i < 33; i++) {
		if ((i / 4) * 4 + 2 == i) {
			std::cout << " ";
			std::cout << i / 4 + 1;
			std::cout << " ";
		}
		else
			std::cout << "   ";
		
		for (int j = 0; j < 65; j++) {
			if (i == 0 && j == 0)
				std::cout << (char)201;
			else if (i == 0 && j == 64)
				std::cout << (char)187;
			else if (i == 32 && j == 0)
				std::cout << (char)200;
			else if (i == 32 && j == 64)
				std::cout << (char)188;
			else if (i % 4 == 0 && j != 0 && j != 64)
				std::cout << (char)205;
			else if (j % 8 == 0)
				std::cout << (char)186;
			//Player --> 1 = putih | COM --> 2 = hitam 
			else if (((i / 4) * 4 + 2 == i && (j / 8) * 8 + 4 == j && pieces[i / 4][j / 8] == 1) || ((i / 4) * 4 + 2 == i && ((j + 1) / 8) * 8 + 4 == j + 1 && pieces[i / 4][(j + 1) / 8] == 1) || ((i / 4) * 4 + 2 == i && ((j - 1) / 8) * 8 + 4 == j - 1 && pieces[i / 4][(j - 1) / 8] == 1) || ((i / 4) * 4 + 2 == i && ((j - 2) / 8) * 8 + 4 == j - 2 && pieces[i / 4][(j - 2) / 8] == 1) || ((i / 4) * 4 + 2 == i && ((j + 2) / 8) * 8 + 4 == j + 2 && pieces[i / 4][(j + 2) / 8] == 1) || (((i - 1) / 4) * 4 + 2 == i - 1 && ((j + 1) / 8) * 8 + 4 == j + 1 && pieces[(i - 1) / 4][(j + 1) / 8] == 1) || (((i - 1) / 4) * 4 + 2 == i - 1 && ((j - 1) / 8) * 8 + 4 == j - 1 && pieces[(i - 1) / 4][(j - 1) / 8] == 1) || (((i - 1) / 4) * 4 + 2 == i - 1 && (j / 8) * 8 + 4 == j && pieces[(i - 1) / 4][j / 8] == 1) || (((i + 1) / 4) * 4 + 2 == i + 1 && ((j + 1) / 8) * 8 + 4 == j + 1 && pieces[(i + 1) / 4][(j + 1) / 8] == 1) || (((i + 1) / 4) * 4 + 2 == i + 1 && ((j - 1) / 8) * 8 + 4 == j - 1 && pieces[(i + 1) / 4][(j - 1) / 8] == 1) || (((i + 1) / 4) * 4 + 2 == i + 1 && (j / 8) * 8 + 4 == j && pieces[(i + 1) / 4][j / 8] == 1)) {
				std::cout << (char)219;
			}
			else if (((i / 4) * 4 + 2 == i && (j / 8) * 8 + 4 == j && pieces[i / 4][j / 8] == 2) || ((i / 4) * 4 + 2 == i && ((j + 1) / 8) * 8 + 4 == j + 1 && pieces[i / 4][(j + 1) / 8] == 2) || ((i / 4) * 4 + 2 == i && ((j - 1) / 8) * 8 + 4 == j - 1 && pieces[i / 4][(j - 1) / 8] == 2) || ((i / 4) * 4 + 2 == i && ((j - 2) / 8) * 8 + 4 == j - 2 && pieces[i / 4][(j - 2) / 8] == 2) || ((i / 4) * 4 + 2 == i && ((j + 2) / 8) * 8 + 4 == j + 2 && pieces[i / 4][(j + 2) / 8] == 2) || (((i - 1) / 4) * 4 + 2 == i - 1 && ((j + 1) / 8) * 8 + 4 == j + 1 && pieces[(i - 1) / 4][(j + 1) / 8] == 2) || (((i - 1) / 4) * 4 + 2 == i - 1 && ((j - 1) / 8) * 8 + 4 == j - 1 && pieces[(i - 1) / 4][(j - 1) / 8] == 2) || (((i - 1) / 4) * 4 + 2 == i - 1 && (j / 8) * 8 + 4 == j && pieces[(i - 1) / 4][j / 8] == 2) || (((i + 1) / 4) * 4 + 2 == i + 1 && ((j + 1) / 8) * 8 + 4 == j + 1 && pieces[(i + 1) / 4][(j + 1) / 8] == 2) || (((i + 1) / 4) * 4 + 2 == i + 1 && ((j - 1) / 8) * 8 + 4 == j - 1 && pieces[(i + 1) / 4][(j - 1) / 8] == 2) || (((i + 1) / 4) * 4 + 2 == i + 1 && (j / 8) * 8 + 4 == j && pieces[(i + 1) / 4][j / 8] == 2)) {
				std::cout << (char)177;
			}
			else
				std::cout << " ";
		}
		std::cout << std::endl;
	}
}

int Board::FlipDisk(int pieces[8][8], std::vector<Possible>& moveflip, Possible input_now, int turn, int* flipped) {
	int flag = 0;
	for (int i = 0; i < moveflip.size(); i++) {
		if (moveflip[i].i_awal == input_now.i_awal && moveflip[i].j_awal == input_now.j_awal) {
			//flip ke bawah
			if (moveflip[i].i_akhir > moveflip[i].i_awal) {
				for (int j = 1; j < moveflip[i].i_akhir - moveflip[i].i_awal; j++) {
					//flip ke vertical bawah
					if (moveflip[i].j_awal == moveflip[i].j_akhir) {
						pieces[moveflip[i].i_awal + j][moveflip[i].j_awal] = turn;
						*flipped = *flipped + 1;
					}

					//flip ke diagonal bawah kanan
					if (moveflip[i].j_awal < moveflip[i].j_akhir) {
						pieces[moveflip[i].i_awal + j][moveflip[i].j_awal + j] = turn;
						*flipped = *flipped + 1;
					}
					//flip ke diagonal bawah kiri
					if (moveflip[i].j_awal > moveflip[i].j_akhir) {
						pieces[moveflip[i].i_awal + j][moveflip[i].j_awal - j] = turn;
						*flipped = *flipped + 1;
					}
				}
			}
			//flip ke atas
			else if (moveflip[i].i_akhir < moveflip[i].i_awal) {
				for (int j = 1; j < moveflip[i].i_awal - moveflip[i].i_akhir; j++) {
					//flip ke vertical atas
					if (moveflip[i].j_awal == moveflip[i].j_akhir) {
						pieces[moveflip[i].i_awal - j][moveflip[i].j_awal] = turn;
						*flipped = *flipped + 1;
					}
					//flip ke diagonal atas kanan
					if (moveflip[i].j_awal < moveflip[i].j_akhir) {
						pieces[moveflip[i].i_awal - j][moveflip[i].j_awal + j] = turn;
						*flipped = *flipped + 1;
					}
					//flip ke diagonal atas kiri
					if (moveflip[i].j_awal > moveflip[i].j_akhir) {
						pieces[moveflip[i].i_awal - j][moveflip[i].j_awal - j] = turn;
						*flipped = *flipped + 1;
					}
				}
			}
			//flip ke kanan dan kiri
			else if (moveflip[i].i_akhir == moveflip[i].i_awal) {
				for (int j = 1; j < abs(moveflip[i].j_awal - moveflip[i].j_akhir); j++) {
					//flip ke kanan
					if (moveflip[i].j_awal < moveflip[i].j_akhir) {
						pieces[moveflip[i].i_awal][moveflip[i].j_awal + j] = turn;
						*flipped = *flipped + 1;
					}
					//flip ke kiri
					if (moveflip[i].j_awal > moveflip[i].j_akhir) {
						pieces[moveflip[i].i_awal][moveflip[i].j_awal - j] = turn;
						*flipped = *flipped + 1;
					}
				}
			}
			flag = 1;
		}

	}
	return flag;
}

#pragma region Getter-Setter Functions

void Board::setPiece(int row, int col, int value)
{
	if (row >= 0 && row < 8 && col >= 0 && col < 8)
	{
		pieces[row][col] = value;
	}
}

#pragma endregion
