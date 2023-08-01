#ifndef __TicTacToe__h
#define __TicTacToe__h

//draw tic tac board
void drawBoard(char* const inputArray);

//prints dash lines for the board
void printLine();

//creates input array for the board , 9 total positions in the board
char* createInputArray();

//initialize game
void gameInit();

//change the player
void changeTurn(bool& player1);

//puts o or x in inputArray at position(0-9)
void takeTurn(char* const inputArray, const int position, const bool player1);

//print which players turn it is
void printPlayerTurn(const bool player1);

//get User position(0-9) and must be empty
int getUserPosition(char* const inputArray);

//check if there is a winner
bool checkWinner(char* const inputArray, int position);

//if user wants to replay the game
bool replay();

#endif
