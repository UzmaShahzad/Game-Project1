#include<iostream>
#include<string>
#include<windows.h>
using namespace std;

struct player     //structure for player
{
	char symbol;
};

char board[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };  //2D array of board

player p1 = { 'X' };  //created 2 objects for player structure
player p2 = { 'O' };

char currentPlayer = 'X';    //current player

void displayBoard()   //displayboard function
{
	system("cls");   //clear screen

	cout << "\033[31m\n\n======= TIC TAC TOE =========\n\n";

	// to display board in colors
	for (int i = 0; i < 3; i++)
	{
		cout << "\t";

		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == 'X')
				cout << "\033[32m";
			else if (board[i][j] == 'O')
				cout << "\033[33m";
			else
				cout << "\033[34m";

			cout << " " << board[i][j];

			if (j < 2)    //to add '|' symbol b/w columns
				cout << " | ";
		}

		cout << endl;

		if (i < 2)      //to add '------------' b/w rows
			cout << "\t---------------\n";
	}

	cout << "\033[35m";    //color code
}

void playerMove() //function for player move
{
	int choice;
	cout << "\nPlayer " << currentPlayer << " turn: ";
	cin >> choice;

	// convert integer to character 
	char ch = choice + '0';
	bool found = false;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] == ch)
			{
				board[i][j] = currentPlayer;
				found = true;
			}
		}
	}

	if (found == false)
	{
		cout << "\nInvalid move!";
		Beep(500, 300);
		Sleep(1000);
		playerMove();
	}
}

bool checkWinner()
{
	// rows
	for (int i = 0; i < 3; i++)
	{
		if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
			return true;
	}
	// columns
	for (int j = 0; j < 3; j++)
	{
		if (board[0][j] == currentPlayer && board[1][j] == currentPlayer && board[2][j] == currentPlayer)
			return true;
	}
	// diagonals
	if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
		return true;

	if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
		return true;

	return false;
}

bool checkDraw()  //function to check if game is draw
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] != 'X' && board[i][j] != 'O')   //to check if still any number exist in board
				return false;
		}
	}

	return true;
}
int main()
{
	while (true)
	{
		displayBoard();   //function call to display board
		playerMove();     //function call for player move

		if (checkWinner())   //check winner
		{
			displayBoard();
			cout << "\nPlayer " << currentPlayer << " wins!\n";
			Beep(1000, 500);  //beep sound for winner
			break;
		}

		if (checkDraw())  //check if game is draw
		{
			displayBoard();
			cout << "\nGame Draw!\n";
			Beep(700, 500);  //beep sound for draw game
			break;
		}

		// change player
		if (currentPlayer == p1.symbol)
			currentPlayer = p2.symbol;
		else
			currentPlayer = p1.symbol;
	}
	system("pause");
	return 0;
}