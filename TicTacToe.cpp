#include"TicTacToe.h"
#include<iostream>

bool replay()
{
	bool cinFail{ false };
	bool yOrN{ true };
	char userInput{};
	constexpr int MAX_CHARS{ 256 };
	do
	{
		yOrN = true;
		std::cout << "Do you want to replay the game (y or n): ";
		std::cin >> userInput;
		cinFail = std::cin.fail();
		if (cinFail)
		{
			std::cin.clear();
			std::cin.ignore(MAX_CHARS, '\n');
			std::cout << "Please enter a y or n.\n";
		}
		else
		{
			userInput = std::tolower(userInput);
			if (userInput == 'y' || userInput == 'n')
			{
				yOrN = true;
			}
			else
			{
				yOrN = false;
				std::cout << "Please enter y or n.\n";
			}
		}

	} while (cinFail || !yOrN);
	return userInput == 'y';
}

bool checkWinner(char* const inputArray, int position)
{
	//check if pos is in first row (0, 1, 2) then check winning conditions
	if (position <= 2)
	{
		//if row elements are equal
		if (inputArray[0] == inputArray[1] && inputArray[2])
			return true;
		//if  columns elements are equal
		if (inputArray[position] == inputArray[position + 3] && inputArray[position + 3] == inputArray[position + 6])
			return true;
		//if diagonal elements are equal
		if (position == 0 && inputArray[0] == inputArray[4] && inputArray[4] == inputArray[8])
			return true;
		//if diagnoal elements are equal
		if (position == 2 && inputArray[2] == inputArray[4] && inputArray[4] == inputArray[6])
			return true;
	}
	//check if pos is in second row(3, 4, 5)
	else if (position <= 5)
	{
		if (inputArray[3] == inputArray[4] && inputArray[4] == inputArray[5])
			return true;
		if (inputArray[position] == inputArray[position + 3] && inputArray[position + 3] == inputArray[position - 3])
			return true;
		if (position == 4 && inputArray[0] == inputArray[4] && inputArray[4] == inputArray[8])
			return true;
		if (position == 4 && inputArray[2] == inputArray[4] && inputArray[4] == inputArray[6])
			return true;
	}
	//if pos is not in first or second row, it will be third row (6, 7, 8)
	else
	{
		if (inputArray[6] == inputArray[7] && inputArray[7] == inputArray[8])
			return true;
		if (inputArray[position] == inputArray[position - 3] && inputArray[position - 3] == inputArray[position - 6])
			return true;
		if (position == 6 && inputArray[2] == inputArray[4] && inputArray[4] == inputArray[6])
			return true;
		if (position == 8 && inputArray[0] == inputArray[4] && inputArray[4] == inputArray[8])
			return true;
	}
	return false;
}

void printPlayerTurn(const bool player1)
{
	if (player1)
	{
		std::cout << "Player 1('O') turn.\n";
	}
	else
	{
		std::cout << "Player 2('X') turn.\n";
	}
}

int getUserPosition(char* const inputArray)
{
	bool cinFail{ false };
	bool insideRange{ true };
	bool emptyPosition{ true };
	int userInput{};
	constexpr int MAX_CHARS{ 256 };
	do
	{
		cinFail = false;
		insideRange = true;
		emptyPosition = true;
		std::cout << "Please enter a position (0-8) and must be empty: ";
		std::cin >> userInput;
		cinFail = std::cin.fail();
		if (cinFail)
		{
			std::cin.clear();
			std::cin.ignore(MAX_CHARS, '\n');
			std::cout << "Please enter integers only.\n";
		}
		else
		{
			//if user doesn't enter between 0 and 8
			if (!(userInput >= 0 && userInput <= 8))
			{
				std::cout << "Please enter integer from 0 to 8 only.\n";
				insideRange = false;
			}
			else
			{
				//if the position is already filled
				if (inputArray[userInput] == 'O' || inputArray[userInput] == 'X')
				{
					std::cout << "Position already taken. Please choose an empty position.\n";
					emptyPosition = false;
				}
			}
		}

	} while (cinFail || !insideRange || !emptyPosition);
	return userInput;
}
void changeTurn(bool& player1)
{
	player1 = !player1;
}

void takeTurn(char* const inputArray, const int position, const bool player1)
{
	const char c{ (player1) ? 'O' : 'X' };
	inputArray[position] = c;
}

void gameInit()
{
	char* inputArray{ createInputArray() };
	bool player1{ false };
	int position{};
	int turn{ 0 };
	bool winner{ false };
	drawBoard(inputArray);

	do
	{
		changeTurn(player1);
		printPlayerTurn(player1);
		position = getUserPosition(inputArray);
		takeTurn(inputArray, position, player1);
		++turn;
		drawBoard(inputArray);
		if (turn > 4)
		{
			winner = checkWinner(inputArray, position);
		}
	} while (turn != 9 && !winner);
	if (winner)
	{
		std::cout << "Player" << ((player1) ? "1('O') " : "2('X') ") << "has won the game.\n";
	}
	else
	{
		std::cout << "Tied game.\n";
	}
	delete[] inputArray;
	inputArray = nullptr;

}

char* createInputArray()
{
	char* inputArray{ new char[9] };
	for (int i{ 0 }; i < 9; ++i)
	{
		inputArray[i] = ' ';
	}
	return inputArray;
}
void printLine()
{
	std::cout << "+---+---+---+";
}

void drawBoard(char* const inputArray)
{
	std::cout << std::endl;
	std::cout << "Position Ref: \tYour board:\n";
	printLine();
	std::cout << '\t';
	printLine();
	std::cout << '\n';

	for (int j{ 0 }; j < 3; ++j)
	{
		for (int i{ 0 }; i < 3; ++i)
		{
			std::cout << ((i == 0) ? "|" : "") << ' ' << i + 3 * j << " |";
		}
		std::cout << '\t';
		for (int i{ 0 }; i < 3; ++i)
		{
			std::cout << ((i == 0) ? "|" : "") << ' ' << inputArray[i + 3 * j] << " |";
		}
		std::cout << '\n';
		printLine();
		std::cout << '\t';
		printLine();
		std::cout << '\n';

	}
	std::cout << std::endl;
}
