#include "Player.h"

Player::Player()
{
	pieceCount = 0;
}

void Player::PlayerTurn(int pieces[8][8], std::vector<Possible>& moveflip, bool isPlayerTurn, Possible input_player, std::string input, int* black, int* white) 
{
	input_player.i_awal = int(input[0] - '0');
	input_player.j_awal = int(input[1] - 'A');

	int result;
	int flippedPieces = 0;
	result = board.FlipDisk(pieces, moveflip, input_player, isPlayerTurn, &flippedPieces);
	
	//jumlah putih(user) bertambah, hitam(com) berkurang karna diflip jadi putih
	std::cout << flippedPieces << std::endl;
	*white = *white + flippedPieces + 1;
	*black -= flippedPieces;
	if (result == 1) {
		pieces[input_player.i_awal][input_player.j_awal] = 1;
	}

	//bersihkan daftar valid move - nya (soalnya bisa berubah)
	moveflip.clear();
}

#pragma region Getter-Setter Functions

PieceType Player::getPieceType() const
{
	return PieceType();
}

int Player::getPieceCount() const
{
	return 0;
}

void Player::setPieceCount(int count)
{
	pieceCount = count;
}

#pragma endregion
