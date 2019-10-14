#include <iostream>
#include <cstring>

#ifndef _WIN32
#define CLEAR "clear"
#endif
#ifndef __linux__
#define CLEAR "cls"
#endif



using namespace std;

int main()
{
	string player1_nickname, player2_nickname;
	string elems[3][3];
	size_t moves_counter = 0;
	for (size_t i = 0; i < 3; i++)
		for (size_t j = 0; j < 3; j++)
			elems[i][j] = " ";
	string map = "    A   B   C\n1   " + elems[0][0] + " | " + elems[0][1] + " | " + elems[0][2] + " \n  ----+---+---\n2   " 
	+ elems[1][0] + " | " + elems[1][1] + " | " + elems[1][2] + " \n  ----+---+---\n3   " + elems[2][0] + " | " + elems[2][1] + " | " + elems[2][2] + "\n";
	bool game_running = true;
	bool player_turn = 0; // 0 - player 1; 1- player 2;
	bool player_wins = false;
	bool true_type;
	char input[10],ch;
	int input_row, input_col, game_status[3][3];
	for (size_t i = 0; i < 3; i++)
		for (size_t j = 0; j < 3; j++)
			game_status[i][j] = 0;

	system(CLEAR);
	cout << "--------------------------------\n";
	cout << "|          TIC TAC TOE         |\n";
	cout << "--------------------------------\n\n";
	cout << "      ----------------\n";
	cout << "      | INSTRUCTIONS |\n";
	cout << "      |    ------    |\n";
	cout << "      | ENTER PLAYERS|\n";
	cout << "      |   NICKNAMES  |\n";
	cout << "      |    ------    |\n";
	cout << "      |ENTER POSITION|\n";
	cout << "      |  (A1,b3,C2)  |\n";
	cout << "      |    ------    |\n";
	cout << "      | WIN THE GAME |\n";
	cout << "      ----------------\n";

	cout << "[X - PLAYER NICKNAME]->";
	cin >> player1_nickname;
	cout << "[O - PLAYER NICKNAME]->";
	cin >> player2_nickname;

	system(CLEAR);

	while (game_running == true && moves_counter != 9) //9 - MAX MOVES COUNTER 3X3
	{
cout << "--------------------------------\n";
	cout << "|          TIC TAC TOE         |\n";
	cout << "--------------------------------\n\n";
	cout << "      ----------------\n";
	cout << "      | INSTRUCTIONS |\n";
	cout << "      |    ------    |\n";
	cout << "      | ENTER PLAYERS|\n";
	cout << "      |   NICKNAMES  |\n";
	cout << "      |    ------    |\n";
	cout << "      |ENTER POSITION|\n";
	cout << "      |  (A1,b3,C2)  |\n";
	cout << "      |    ------    |\n";
	cout << "      | WIN THE GAME |\n";
	cout << "      ----------------\n\n\n";

		cout << map;
		true_type = true;
		if (player_turn == 0)
			cout << "[" << player1_nickname << " ";
		if (player_turn == 1)
			cout << "[" << player2_nickname << " ";
		cout << "INPUT YOUR MOVE]->";
		cin >> input;
		if (input[0] == 'A' || input[0] == 'a')
			input_row = 1;
		else if (input[0] == 'B' || input[0] == 'b')
			input_row = 2;
		else if (input[0] == 'C' || input[0] == 'c')
			input_row = 3;
		else
			true_type = false;

		input_col = input[1] - '0';

		if (input_col > 3 || input_col < 0)
			true_type = false;
		
		if(game_status[input_col - 1][input_row - 1] != 0)
			true_type = false;

		if (true_type == false)
		{
			system(CLEAR);
			continue;
		}

		if (game_status[input_col - 1][input_row - 1] == 0)
		{
			if (player_turn == 0)
			{
				game_status[input_col - 1][input_row - 1] = 1;
				elems[input_col - 1][input_row - 1] = "X";
				player_turn = 1;
			}
			else
			{
				game_status[input_col - 1][input_row - 1] = 2;
				elems[input_col - 1][input_row - 1] = "O";
				player_turn = 0;
			}
				map = "    A   B   C\n1   " + elems[0][0] + " | " + elems[0][1] + " | " + elems[0][2] + " \n  ----+---+---\n2   "
				+ elems[1][0] + " | " + elems[1][1] + " | " + elems[1][2] + " \n  ----+---+---\n3   " + elems[2][0] + " | " + elems[2][1] + " | " + elems[2][2] + "\n";
		}

//------------------------CHECK WIN COMBINATIONS------------------
		for (size_t i = 0; i < 3; i++)
		{
			if (game_status[i][0] != 0 && game_status[i][1] != 0 && game_status[i][2] != 0 && game_status[i][0] == game_status[i][1] && game_status[i][0] == game_status[i][2])
				{
					game_running = false;
					player_wins = true;
				}
			else if (game_status[0][i] != 0 && game_status[1][i] != 0 && game_status[2][i] != 0 && game_status[0][i] == game_status[1][i] && game_status[0][i] == game_status[2][i])
				{
					game_running = false;
					player_wins = true;
				}
		}
		if (game_status[0][0] != 0 && game_status[1][1] != 0 && game_status[2][2] != 0 && game_status[0][0] == game_status[1][1] && game_status[0][0] == game_status[2][2])
			{
				game_running = false;
				player_wins = true;
			}
		if (game_status[0][2] != 0 && game_status[1][1] != 0 && game_status[2][0] != 0 && game_status[0][2] == game_status[1][1] && game_status[0][2] == game_status[2][0])
			{
				game_running = false;
				player_wins = true;
			}

		system(CLEAR);
		moves_counter++;
	}
//------------------OUTPUT RESULTS-----------------------
	cout << map;
	if (moves_counter == 9 && player_wins == false)
		cout << "\n\n[DRAW]\n";
	else if (player_turn == 0)
		cout << "[" << player2_nickname << " WINS]";
	else if (player_turn == 1)
		cout << "[" << player1_nickname << " WINS]";

	return 0;
}