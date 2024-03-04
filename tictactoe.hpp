#include <vector>
#include <iostream> 

using namespace std;

const int PLAYER1 = 0;
const int PLAYER2 = 1;

void clearScreen();
void drawBoard(vector <char> &board);
void initializeBoard(vector <char> &board);
int convertMove(char position);
bool validMove(char position);
bool validPlacement(vector <char> &board, int position);
int setPlay(vector <char> &board, char move, int turn);
char getPlay(vector <char> &board, char move);
void getWinner(int turn);
bool gameWon(vector <char> &board);
bool checkRow(vector <char> &board, char mark);
bool checkCol(vector <char> &board, char mark);
bool checkDiagonal(vector <char> &board, char mark);
bool boardFull(vector <char> &board);