#include <iostream>
#include <stdio.h>


struct Player {
	std::string piece;
	bool is_turn;
	bool has_won = false;

	void switchTurn() {
		if (is_turn = false) {
			is_turn = true;
		}
		else if(is_turn = true) {
			is_turn = false;
		}
	}

	Player(std::string _piece) {
		piece = _piece;
	}
};

struct Grid {
	std::string value = " ";
	bool is_taken = false;

	void changeVal(Player _player) {

		if (is_taken == false) {
			value = _player.piece;
			is_taken = true;
		}
		else if (is_taken == true) {
			std::cout << "spot taken by " + value;
		}
	}

};

void displayGrid(const Grid board[3][3], Player _player_a, Player _player_b) {
	std::cout << "\n";
	std::cout << "--- 1 -- 2 --- 3 --\n";
	std::cout << " =================\n";
	std::cout << "1 | " << board[0][0].value + "  |  " + board[0][1].value + "  |  " + board[0][2].value << " |" << "\n";
	std::cout << "-----------------\n";
	std::cout << "2 | " << board[1][0].value + "  |  " + board[1][1].value + "  |  " + board[1][2].value << " |" << "\n";
	std::cout << "-----------------\n";
	std::cout << "3 | " << board[2][0].value + "  |  " + board[2][1].value + "  |  " + board[2][2].value << " |" << "\n";
	std::cout << " =================";
	std::cout << "\n";
}

bool checkWin(const Grid board[3][3], Player _player) {
	for (int i = 0; i < 3; i++) {
		if ((board[i][0].value == _player.piece && board[i][1].value == _player.piece && board[i][2].value == _player.piece) ||
			(board[0][i].value == _player.piece && board[1][i].value == _player.piece && board[2][i].value == _player.piece)) {
			_player.has_won = true;
			return true;
		}

	}
	if ((board[0][0].value == _player.piece && board[1][1].value == _player.piece && board[2][2].value == _player.piece) ||
		(board[0][2].value == _player.piece && board[1][1].value == _player.piece && board[2][0].value == _player.piece)) {
		_player.has_won = true;
		return true;
	}

	return false;
};

int main() {

	Grid grid_array[3][3];
	Player x("X");
	Player o("O");

	std::string turn;


	while (true) {

		std::cout << "whos turn should it be? (x/o) \n";
		std::cin >> turn;

		if (turn == "x") {
			x.is_turn = true;
			o.is_turn = false;

			break;
		}
		else if (turn == "o") {
			o.is_turn = true;
			x.is_turn = false;

			break;
		}
		else {
			std::cout << "not a valid answer! \n";
		}
	}

	int inp_a, inp_b;

	while ((!checkWin(grid_array, x)) || (!checkWin(grid_array, o))) {

		//grid_array[0][0].changeVal(x);
		displayGrid(grid_array, x, o);


		if (x.is_turn == true) {
			std::cout << "it is " + x.piece + " turn " + "pick a column 1-3\n";
			std::cin >> inp_a;
			std::cout << "now choose a row 1-3 \n";
			std::cin >> inp_b;

			if (grid_array[inp_a - 1][inp_b - 1].is_taken == true) {
				std::cout << "spot is taken! \n";
			}
			else {
				grid_array[inp_a - 1][inp_b - 1].changeVal(x);
				x.is_turn = false;
				o.is_turn = true;
			}
		}
		else if (o.is_turn == true) {
			std::cout << "it is " + o.piece + " turn " + "pick a column 1-3\n";
			std::cin >> inp_a;
			std::cout << "now choose a row 1-3 \n";
			std::cin >> inp_b;

			if (grid_array[inp_a-1][inp_b-1].is_taken == true) {
				std::cout << "spot is taken! \n";
			}
			else {
				grid_array[inp_a-1][inp_b-1].changeVal(o);
				x.is_turn = true;
				o.is_turn = false;
			}
		}

		if ((checkWin(grid_array, x)) || (checkWin(grid_array, o))) {
			displayGrid(grid_array, x, o);

			if (checkWin(grid_array, x) == true) {
				x.has_won = true;
			}
			else if (checkWin(grid_array, o) == true) {
				o.has_won = true;
			}

			break;
		}
		else {
			continue;
		}
	}

	if (x.has_won == true) {
		std::cout << "\n";
		std::cout << x.piece + " " + "has won! \n";
	}
	else if (o.has_won == true) {
		std::cout << "\n";
		std::cout << o.piece + " " + "has won! \n";
	}

	return -1;
}