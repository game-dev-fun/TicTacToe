#include<iostream>
#include<cctype>
#include"TicTacToe.h"


int main()
{
	do
	{
		gameInit();
	} while (replay());

	return 0;
}
