#include "Game.h"

void Game::Start()
{
	Board board;
	Player player;
	Bot bot;
	
	std::vector<Possible> moveflip;

	std::string input;
	Possible input_player{};
	int stopper = 0;
	int exit = 0;

	initialState(&board, &player, &bot);

	while (exit != -1) {
		system("cls");

		displayHeader();

		auto pieces = board.pieces;
		int white = player.getPieceCount();
		int black = bot.getPieceCount();

		bool isPlayerTurn = true;
		bot.PossibleInput(pieces, moveflip, isPlayerTurn);
		if (moveflip.size() == 0) {
			stopper++;
		}

		board.Display(pieces);
		std::cout << "Black = " << black << ", White = " << white << std::endl;

		displayInputInfo();
		std::cin.ignore();
		std::cin >> input;

		if (input == "-1") {
			exit = -1;
			system("pause");
		}
		else {
			bool isInputValid = false;
			for (int size = 0; size < moveflip.size(); size++) {
				int rowIndexFromAscii = int(input[0] - 49);
				bool isRowPossible = rowIndexFromAscii == moveflip[size].i_awal;

				int colIndexFromAscii = int(input[1] - 65);
				bool isColPossible = colIndexFromAscii == moveflip[size].j_awal;

				if (isRowPossible && isColPossible) {
					isInputValid = true;
					break;
				}
			}
			
			if (!isInputValid) {
				std::cout << "Input salah! Try Again!" << std::endl;
				system("pause");
				continue;
			}

			player.PlayerTurn(pieces, moveflip, isPlayerTurn, input_player, input, &black, &white);

			isPlayerTurn = false;

			displayHeader();

			board.Display(pieces);

			std::cout << "Black = " << black << ", White = " << white << std::endl;

			int result = bot.BotTurn(pieces, moveflip, isPlayerTurn, &black, &white);
			if (result == 0) {
				stopper++;
			}

			if (stopper == 2) {
				break;
				std::cout << "Kedua player tidak ada yang dapat bergerak" << std::endl;
			}
			else {
				stopper = 0;
			}
		}

		board.Display(pieces);

		std::cout << "Black = " << black << ", White = " << white << std::endl;
		system("pause");

		std::cout << "Kondisi akhir : " << std::endl;
		std::cout << "Black = " << black << ", White = " << white << std::endl;
		if (black < white) {
			std::cout << "Player Menang" << std::endl;
		}
		else if (white < black) {
			std::cout << "Komputer Menang" << std::endl;
		}
		else {
			std::cout << "Pertandingan Seri" << std::endl;
		}
		if (black + white >= 64) {
			break;
		}
	}
}

void Game::initialState(Board* board, Player* player, Bot* bot) 
{	
	board->setPiece(3, 3, (int)PieceType::Black);
	board->setPiece(3, 4, (int)PieceType::White);
	board->setPiece(4, 3, (int)PieceType::White);
	board->setPiece(4, 4, (int)PieceType::Black);
	
	int currentPlayerPieces = 2 + player->getPieceCount();
	int currentBotPieces = 2 + bot->getPieceCount();
	
	player->setPieceCount(currentPlayerPieces);
	bot->setPieceCount(currentBotPieces);
}

#pragma region Display Functions

void Game::displayHeader()
{
	std::cout << "============================" << std::endl;
	std::cout << " Terminal Othello (\\'   ')/" << std::endl;
	std::cout << "============================" << std::endl << std::endl;
}

void Game::displayInputInfo()
{
	std::cout << std::endl << "Input format: <row><column>. Example: 1A" << std::endl;
	std::cout << "*Type 'exit' to close the game" << std::endl;
	std::cout << "------------------------------" << std::endl;
	std::cout << "Your input here: ";
}

#pragma endregion