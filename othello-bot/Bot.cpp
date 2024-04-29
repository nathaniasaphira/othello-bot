#include "Bot.h"

void Bot::PossibleInput(int pieces[8][8], std::vector<Possible>& moveflip, bool isPlayerTurn) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (pieces[i][j] == 0) {
				//cek ke bawah
				if (pieces[i + 1][j] != isPlayerTurn && pieces[i + 1][j] != 0) {
					Possible baru;
					//ngecek satu - satu apakah ada disk pemain --> tanda bisa diflip dan valid
					for (int k = 2; k < 8; k++) {
						if (i + k > 7)
							break;
						//ketemu, lalu ditambahkan ke struct "baru" untuk menampung
						if (pieces[i + k][j] == isPlayerTurn) {
							baru.i_akhir = i + k;
							baru.j_akhir = j;
							baru.i_awal = i;
							baru.j_awal = j;
							moveflip.push_back(baru);
							break;
						}
						//kalo setelah ditelusuri nemu kosong, berarti ga ada --> tanda ga bisa diflip
						if (pieces[i + k][j] == 0)
							break;
					}
				}
				
				//cek ke atas
				if (pieces[i - 1][j] != isPlayerTurn && pieces[i - 1][j] != 0) {
					Possible baru;
					for (int k = 2; k < 8; k++) {
						if (i - k < 0)
							break;

						if (pieces[i - k][j] == isPlayerTurn) {
							baru.i_akhir = i - k;
							baru.j_akhir = j;
							baru.i_awal = i;
							baru.j_awal = j;
							moveflip.push_back(baru);
							break;
						}
						if (pieces[i - k][j] == 0)
							break;
					}
				}

				//cek ke kanan
				if (pieces[i][j + 1] != isPlayerTurn && pieces[i][j + 1] != 0) {
					Possible baru;
					for (int k = 2; k < 8; k++) {
						if (j + k > 7)
							break;
						if (pieces[i][j + k] == isPlayerTurn) {
							baru.i_akhir = i;
							baru.j_akhir = j + k;
							baru.i_awal = i;
							baru.j_awal = j;
							moveflip.push_back(baru);
							break;
						}
						if (pieces[i][j + k] == 0)
							break;
					}
				}

				//cek ke kiri
				if (pieces[i][j - 1] != isPlayerTurn && pieces[i][j - 1] != 0) {
					Possible baru;
					for (int k = 2; k < 8; k++) {
						if (j - k < 0)
							break;
						if (pieces[i][j - k] == isPlayerTurn) {
							baru.i_akhir = i;
							baru.j_akhir = j - k;
							baru.i_awal = i;
							baru.j_awal = j;
							moveflip.push_back(baru);
							break;
						}
						if (pieces[i][j - k] == 0)
							break;
					}
				}

				//cek ke diagonal bawah kanan
				if (pieces[i + 1][j + 1] != isPlayerTurn && pieces[i + 1][j + 1] != 0) {
					Possible baru;
					for (int k = 2; k < 8; k++) {
						if (i + k > 7 || j + k > 7)
							break;
						if (pieces[i + k][j + k] == isPlayerTurn) {
							baru.i_akhir = i + k;
							baru.j_akhir = j + k;
							baru.i_awal = i;
							baru.j_awal = j;
							moveflip.push_back(baru);
							break;
						}
						if (pieces[i + k][j + k] == 0)
							break;
					}
				}

				//cek ke diagonal bawah kiri
				if (pieces[i + 1][j - 1] != isPlayerTurn && pieces[i + 1][j - 1] != 0) {
					Possible baru;
					for (int k = 2; k < 8; k++) {
						if (i + k > 7 || j - k < 0)
							break;
						if (pieces[i + k][j - k] == isPlayerTurn) {
							baru.i_akhir = i + k;
							baru.j_akhir = j - k;
							baru.i_awal = i;
							baru.j_awal = j;
							moveflip.push_back(baru);
							break;
						}
						if (pieces[i + k][j - k] == 0)
							break;
					}
				}

				//cek ke diagonal atas kanan
				if (pieces[i - 1][j + 1] != isPlayerTurn && pieces[i - 1][j + 1] != 0) {
					Possible baru;
					for (int k = 2; k < 8; k++) {
						if (i - k < 0 || j + k > 7)
							break;
						if (pieces[i - k][j + k] == isPlayerTurn) {
							baru.i_akhir = i - k;
							baru.j_akhir = j + k;
							baru.i_awal = i;
							baru.j_awal = j;
							moveflip.push_back(baru);
							break;
						}
						if (pieces[i - k][j + k] == 0)
							break;
					}
				}

				//cek ke diagonal atas kiri
				if (pieces[i - 1][j - 1] != isPlayerTurn && pieces[i - 1][j - 1] != 0) {
					Possible baru;
					for (int k = 2; k < 8; k++) {
						if (i - k < 0 || j - k < 0)
							break;
						if (pieces[i - k][j - k] == isPlayerTurn) {
							baru.i_akhir = i - k;
							baru.j_akhir = j - k;
							baru.i_awal = i;
							baru.j_awal = j;
							moveflip.push_back(baru);
							break;
						}
						if (pieces[i - k][j - k] == 0)
							break;
					}
				}

			}
		}
	}
}

int Bot::BotTurn(int pieces[8][8], std::vector<Possible>& moveflip, bool isPlayerTurn, int* black, int* white) {
	if (moveflip.size() == 0) {
		return 0;
	}

	//turn = 2;
	//int flippedArrayComp[moveflip.size()];
	int max = -99999; // Cabang Minimax yang max
	int min = 99999; // Cabang Minimax yang min 
	
	PossibleInput(pieces, moveflip, isPlayerTurn);

	Possible input_playerTrue;

	//Perulangan untuk mencoba semua move yang komputer bisa lakukan
	for (int row = 0; row < moveflip.size(); row++) {
		Possible input_player;
		input_player.i_awal = moveflip[row].i_awal;
		input_player.j_awal = moveflip[row].j_awal;
		
		int flipped = 0;
		int tempDisk[8][8];
		std::copy(&pieces[0][0], &pieces[0][0]+8*8, &tempDisk[0][0]);

		// TODO: Remove after validating
		// for (int x = 0; x < 8; x++) {
		// 	for (int y = 0; y < 8; y++) {
		// 		tempDisk[x][y] = pieces[x][y];
		// 	}
		// }
		
		board.FlipDisk(tempDisk, moveflip, input_player, isPlayerTurn, &flipped);
		tempDisk[input_player.i_awal][input_player.j_awal] = isPlayerTurn;
		
		std::vector<Possible> tempMoveflip;
		PossibleInput(tempDisk, tempMoveflip, 1);
		
		//Perulangan untuk melihat kemungkinan move jika Komputer mengambil gerakan ke-i 
		for (int col = 0; col < tempMoveflip.size(); col++) {
			Possible input_player2;
			input_player2.i_awal = tempMoveflip[col].i_awal;
			input_player2.j_awal = tempMoveflip[col].j_awal;

			int flipped2 = 0;
			int tempDisk2[8][8];

			for (int x = 0; x < 8; x++) {
				for (int y = 0; y < 8; y++) {
					tempDisk2[x][y] = tempDisk[x][y];
				}
			}
			
			board.FlipDisk(tempDisk2, tempMoveflip, input_player2, 1, &flipped2);
			//Pengecekan minimum dari perulangan yang didapatkan dari gerakan komputer ke-i
			if (flipped2 < min) {
				min = flipped2;
			}

		}

		//Pengecekan maximum dari setiap kemungkinan move yang dijalankan komputer
		if (flipped - min > max) {
			max = flipped;
			input_playerTrue.i_awal = moveflip[row].i_awal;
			input_playerTrue.j_awal = moveflip[row].j_awal;
		}

		min = 99999; // what??
	}

	int flipped3 = 0;
	board.FlipDisk(pieces, moveflip, input_playerTrue, isPlayerTurn, &flipped3);
	std::cout << flipped3 << std::endl;
	
	*black = *black + flipped3 + 1;
	*white -= flipped3;
	pieces[input_playerTrue.i_awal][input_playerTrue.j_awal] = isPlayerTurn;
	
	//bersihkan daftar valid move - nya (soalnya bisa berubah)
	moveflip.clear();
	return 1;
}

#pragma region Getter-Setter Functions

PieceType Bot::getPieceType() const
{
	return PieceType();
}

int Bot::getPieceCount() const
{
	return 0;
}

void Bot::setPieceCount(int count)
{
	pieceCount = count;
}

#pragma endregion