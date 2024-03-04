#include "tictactoe.hpp"

/**
 * @brief Clears the terminal screen.
 *
 * This function clears the terminal screen to improve readability
 * and provide a clean user interface. It uses ANSI escape sequences
 * for clearing the screen.
 */
void clearScreen() {
  //Output a newline for spacing
  cout << endl;
  //Use ANSI escape sequence to clear the screen
  cout << "\033c";
  cout << endl;
}

/**
* @brief Draws the tic-tac-toe board to the screen.
*
* This function draws the tic-tac-toe board to the screen, labelling cells
* with color-coded elements. Player 1 is blue, Player 2 is purple, empty
* spaces are green.
*
* @param the board is the tic-tac-toe board that should be drawn
*/
void drawBoard(vector <char> &board) {
  for (int i = 0; i < 9; i += 3) {
    if (board.at(i) == 'x') {
      cout << "\033[1;34m" << "  " << board.at(i) << "  " << "\033[0m" << "|";
    } else if (board.at(i) == 'o') {
      cout << "\033[1;35m" << "  " << board.at(i) << "  " << "\033[0m" << "|";
    } else {
      cout << "\033[1;32m" << "  " << board.at(i) << "  " << "\033[0m" << "|";
    }

    if (board.at(i + 1) == 'x') {
      cout << "\033[1;34m" << "  " << board.at(i + 1) << "  " << "\033[0m" << "|";
    } else if (board.at(i + 1) == 'o') {
      cout << "\033[1;35m" << "  " << board.at(i + 1) << "  " << "\033[0m" << "|";
    } else {
      cout << "\033[1;32m" << "  " << board.at(i + 1) << "  " << "\033[0m" << "|";
    }

    if (board.at(i + 2) == 'x') {
      cout << "\033[1;34m" << "  " << board.at(i + 2) << "  " << "\033[0m" << endl;
    } else if (board.at(i + 2) == 'o') {
      cout << "\033[1;35m" << "  " << board.at(i + 2) << "  " << "\033[0m" << endl;
    } else {
      cout << "\033[1;32m" << "  " << board.at(i + 2) << "  " << "\033[0m" << endl;
    }

    if (i < 6) {
      cout << "-----|-----|-----" << endl;
    }
  
  }

  cout << endl;
}


/**
* @brief Fills vector with characters starting at lower case a.
*
* @param matrix the vector to initialize
*/
void initializeBoard(vector<char> &board) {
  char val = 'a';

  for (int i = 0; i < board.size(); ++i) {
    board[i] = val++;
  }
}

/**
* @brief Converts a character representing a cell to a vector index
*
* @param the move to be converted to an index
* @return the integer index in the vector
*/
int convertMove(char move) {
  int index = move - 'a';

  return index;
}

/**
* @brief Determines if a spot in board is available.
*
* @param board the current tic-tac-toe board 
* @param move is an index into vector to check if available
* @return true if move's state is available (not marked) AND is in bounds
*/
bool validPlacement(vector <char> &board, int move) {
  if (board[move] == 'x' || board[move] == 'o') {
    return false;
  }

  return true;
}

/**
* @brief converts the user input and then determines if the converted input 
* is a valid play.
*
* @param board the current tic-tac-toe board 
* @return an integer index in board vector of a chosen available board spot
*/
int setPlay(vector <char> &board, char move, int turn) {
  int index = convertMove(move);
  if (validPlacement(board, index)) {
    if (turn == PLAYER1) {
      board.at(index) = 'x';
    } else {
      board.at(index) = 'o';
    }
  }

  return index;
}

/** 
* @brief Determines if there are three x's or o's in a row horizontally
* 
* @param board the current tic-tac-toe board 
* @return true if the game has been won, false otherwise
*/
bool checkRow(vector <char> &board, char mark) {
  for (int i = 0; i < board.size(); i+=3) {
    if (board[i] == mark && board[i + 1] == mark && board[i + 2] == mark) {
      return true;
    }
  }

  return false;
}

/** 
* @brief Determines if there are three x's or o's in a row vertically
* 
* @param board the current tic-tac-toe board 
* @return true if the game has been won, false otherwise
*/
bool checkCol(vector <char> &board, char mark) {
  for (int i = 0; i < 3; ++i) {
    if (board[i] == mark && board[i + 3] == mark && board[i + 6] == mark) {
      return true;
    }
  }

  return false;
}

/** 
* @brief Determines if there are three x's or o's in a row diagonally
* 
* @param board the current tic-tac-toe board 
* @return true if the game has been won, false otherwise
*/
bool checkDiagonal(vector <char> &board, char mark) {
  if (board[0] == mark && board[4] == mark && board[8] == mark ||
  board[2] == mark && board[4] == mark && board[6] == mark) {
    return true;
  }

  return false;
}

/**
* @brief Determines if the game has been won
*
* @param board the current tic-tac-toe board 
* @return true if the game has been won, false otherwise
*/
bool gameWon(vector <char> &board) {
  char marks[2] = {'x', 'o'};

  for (char mark : marks) {
    if (checkRow(board, mark) || checkCol(board, mark) || checkDiagonal(board, mark)) {
      return true;
    }
  }

  return false;
}


/** 
* @brief Determines if the board is full
*
* @param board the current tic-tac-toe board 
* @return true iff the board is full (no cell is available)
*/
bool boardFull(vector <char> &board) {
  for (int i = 0; i < board.size(); i++) {
    if (board.at(i) >= 'a' && board.at(i) <= 'i') {
      return false;
    }
  }

  return true;
}

/**
* @brief Checks the move of the player
*
* @param the move on the board the player wants to play
* @return true if move is valid, flase otherwise
*/
bool validMove(char move) {
  if (move < 'a' || move > 'i') {
    return false;
  }
  
  return true;
}

/** 
* @brief Gets the next move from the player
*
* @param board the current tic-tac-toe board
* @param the move the player wants to make on the board
* @return the valid move the player wants to make on the board
*/
char getPlay(vector <char> &board, char move) {
  cin >> move;
  int index = convertMove(move);
  
  while (!validMove(move) || !validPlacement(board, index)) {
    cout << "Invalid move. Please try again.\n";
    cin >> move;
    index = convertMove(move);
  }
  
  return move;
}

/**
* @brief Determines the winner
* 
* @param the player whose turn it is
*/
void getWinner(int turn) {
  if (turn == PLAYER1) {
    cout << "Player 2 (o) wins!\n";
  } else {
    cout << "Player 1 (x) wins!\n";
  }
}