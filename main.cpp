#include "tictactoe.hpp"

int main() {
    vector <char> board(9);
    int turn = PLAYER1;
    char move;

    cout << "Welcome to Tic Tac Toe!\n\n";
    cout << "Use lowercase letters a-i to place your mark.\n\n";
  
    initializeBoard(board);
    drawBoard(board);

    while (!gameWon(board) && !boardFull(board)) {
        move = getPlay(board, move);
        setPlay(board, move, turn);

        if (turn == PLAYER1) {
            turn = PLAYER2;
        } else {
            turn = PLAYER1;
        }

        clearScreen();
        drawBoard(board);
    }

    if (gameWon(board)) {
        getWinner(turn);
    } else {
        cout << "It's a draw!\n";
    }

    return 0;
}