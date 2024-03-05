#include "tictactoe.hpp"

int main() {
    vector <char> board(9);
    int turn = PLAYER1;
    char move;

    cout << "Welcome to Tic Tac Toe!\n\n";
    cout << "Use numbers 1-9 to place your mark. Player 1 goes first.\n\n";
  
    initializeBoard(board);
    drawBoard(board);

    while (!gameWon(board) && !boardFull(board)) {
        move = getPlay(board, move);
        setPlay(board, move, turn);

        clearScreen();
        drawBoard(board);
      
        if (turn == PLAYER1) {
            cout << "Player 2's turn.\n\n";
            turn = PLAYER2;
        } else {
            cout << "Player 1's turn.\n\n";
            turn = PLAYER1;
        }
    }

    if (gameWon(board)) {
        getWinner(turn);
    } else {
        cout << "It's a draw!\n";
    }

    return 0;
}