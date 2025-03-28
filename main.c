/**
 * ENGG1110 Problem Solving by Programming
 *
 * Course Project - Teeko
 *
 * I declare that the project here submitted is original
 * except for source material explicitly acknowledged,
 * and that the same or closely related material has not been
 * previously submitted for another course.
 * I also acknowledge that I am aware of University policy and
 * regulations on honesty in academic work, and of the disciplinary
 * guidelines and procedures applicable to breaches of such
 * policy and regulations, as contained in the website.
 *
 * University Guideline on Academic Honesty:
 *   https://www.cuhk.edu.hk/policy/academichonesty/
 *
 * Student Name  : SHAO Youwen
 * Student ID    : 1155228814
 * Class/Section : E
 * Date          : 25/03/2025
 */

#include <stdio.h>
/* NO other header files are allowed */

/* NO global variables are allowed */

/* Macros used to represent the state of each square */
#define SIZE 4
#define EMPTY 0
#define CIRCLE 1
#define CROSS 2


/* Initialize the game board by setting all 4x4=16 squares to EMPTY */
void initGameBoard(int gameBoard[SIZE][SIZE]) {
   for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++) {
         gameBoard[i][j] = EMPTY;
      }
   }
}


/* Display the game board on the screen
   You are required to follow exactly the output format stated in the project specification
 */
void printGameBoard(int gameBoard[SIZE][SIZE]) {
   int index;
   printf("================\n");
      for (int i = 0; i < SIZE; i++) {
         for (int j = 0; j < SIZE; j++) {
            index = (3 - i) * SIZE + (j + 1);
            if (gameBoard[i][j] == EMPTY) {
               printf("|%2d|", index);
            } else if (gameBoard[i][j] == CIRCLE) {
               printf("| O|");
            } else {
               printf("| X|");
            }
         }
         printf("\n");
      }
   printf("================\n");
}


/* Ask the human player to place the mark.
   In Part 1, you can assume that the user input must be valid (i.e, an empty space between 1 and 16). */
void placeMarkByHumanPlayer(int gameBoard[SIZE][SIZE], int mark) {
   int index;
   printf("Player %d, please place your mark [1-16]:\n", mark);
   scanf("%d", &index);

   int i = 3 - (index - 1) / 4; // row
   int j = (index - 1) % 4; // col
   gameBoard[i][j] = mark;
}


/* Return 1 if there is a winner in the game, otherwise return 0 */
/* Note: the winner is the current player indicated in main() */
int hasWinner(int gameBoard[SIZE][SIZE]) {
   // Check rows
   for (int i = 0; i < 4; i++) {
      int winner = gameBoard[i][0];
      if (winner == EMPTY) continue;
      if (gameBoard[i][1] == winner && gameBoard[i][2] == winner && gameBoard[i][3] == winner) {
         return winner;
      }
   }
   // Check columns
   for (int j = 0; j < 4; j++) {
      int winner = gameBoard[0][j];
      if (winner == EMPTY) continue;
      if (gameBoard[1][j] == winner && gameBoard[2][j] == winner && gameBoard[3][j] == winner) {
         return winner;
      }
   }
   // Check main diagonal
   int winner = gameBoard[0][0];
   if (winner != EMPTY) {
      if (gameBoard[1][1] == winner && gameBoard[2][2] == winner && gameBoard[3][3] == winner) {
         return winner;
      }
   }
   // Check anti-diagonal
   winner = gameBoard[0][3];
   if (winner != EMPTY) {
      if (gameBoard[1][2] == winner && gameBoard[2][1] == winner && gameBoard[3][0] == winner) {
         return winner;
      }
   }
   // Check 2x2 squares
   for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
         winner = gameBoard[i][j];
         if (winner == EMPTY) continue;
         if (gameBoard[i][j+1] == winner && gameBoard[i+1][j] == winner && gameBoard[i+1][j+1] == winner) {
            return winner;
         }
      }
   }
   return 0;
}

/* Determine the next move of the computer player.
   You are required to implement the following strategy:
   place the mark in the first empty space scanning from 1 to 16. */
void placeMarkByComputerPlayer(int gameBoard[SIZE][SIZE], int mark) {
   int index;
   for (index = 1; index < SIZE * SIZE; index++) {
      int i = 3 - (index - 1) / 4;
      int j = (index - 1) % 4;
      if (gameBoard[i][j] == EMPTY) {
         gameBoard[i][j] = mark;
         break;
      }
   }
   printf("Computer places the mark: %d\n", index);
}

/* Uncomment the following function for Part 2 implementation
   Initialize the game board from a file */
//void initGameBoardFromFile(int gameBoard[SIZE][SIZE]) {
//
//}

/* Uncomment the following function for Part 2 implementation
   Ask the human player to place the mark.
   In Part 2, the user input might be invalid
   You have to perform error checking in Part 2. */
//void moveMarkByHumanPlayer(int gameBoard[SIZE][SIZE], int mark) {
//
//}


/* Uncomment the following function for Part 2 implementation
   Determine the next move of the computer player.
   You are required to implement the following strategy:
   1. choose the first placed mark in the draw board scanning from 16 to 1,
   2. move the mark the first valid direction scanning from 8 to 1;
      if all directions of the selected mark are invalid,
      go back to step 1 and choose the next placed mark.
 */
//void moveMarkByComputerPlayer(int gameBoard[SIZE][SIZE], int mark) {
//
//}


/* The main function */
int main()
{
    /* Local variables */
    int gameBoard[SIZE][SIZE];    // Each element stores 0 (EMPTY), 1 (CIRCLE), or 2 (CROSS)
    int currentPlayer;      // 1: Player 1 (Human)   2: Player 2 (Human) or Computer Player
    int gameEnds;           // 0: The game continues   1: The game ends
    int numOfHumanPlayers;  // 1 or 2
    int round = 0;          // number of rounds completed

    /* Initialize the local variables by invoking a function, using assignment statements, and reading the user input */
    initGameBoard(gameBoard);
    currentPlayer = 1;
    gameEnds = 0;
    printf("How many human players [1-2]?\n");
    scanf("%d", &numOfHumanPlayers);    // In Part 1, you can assume that the user input must be valid

    /* Uncomment the following statements to test whether the printGameBoard() and the placeMarkByHumanPlayer() functions
       are implemented correctly
       You can add more if you wish
       After testing, you can delete them or move them elsewhere */
    //printGameBoard(gameBoard);
    //printf("Player 1, please place your mark [1-16]:\n");
    //placeMarkByHumanPlayer(gameBoard, CIRCLE);
    //printf("Player 2, please place your mark [1-16]:\n");
    //placeMarkByHumanPlayer(gameBoard, CROSS);

   printGameBoard(gameBoard);
   currentPlayer = 1;
   while(1) {
      if (currentPlayer == 1 || (currentPlayer == 2 && numOfHumanPlayers == 2)) {
         placeMarkByHumanPlayer(gameBoard, currentPlayer == 1 ? CIRCLE : CROSS);
      } else {
         placeMarkByComputerPlayer(gameBoard, CROSS);
      }
      round++;
      printGameBoard(gameBoard);

      if (hasWinner(gameBoard)) {
         if (currentPlayer == 1) {
            printf("Player 1 wins! Congratulations!");
         } else {
            if (numOfHumanPlayers == 2) {
               printf("Player 2 wins! Congratulations!");
            } else {
               printf("Computer wins!");
            }
         }
         break;
      }

      if (round == 8) {
         printf("Draw game!");
         break;
      }

      currentPlayer = currentPlayer == 1 ? 2 : 1;
   }


   /*printGameBoard(gameBoard);
   if (numOfHumanPlayers == 1) {
      while (1) {
         placeMarkByHumanPlayer(gameBoard, CIRCLE);
         printGameBoard(gameBoard);
         placeMarkByComputerPlayer(gameBoard, CROSS);
         printGameBoard(gameBoard);
      }
   } else if (numOfHumanPlayers == 2) {
      while (!gameEnds) {
         placeMarkByHumanPlayer(gameBoard, CIRCLE);
         printGameBoard(gameBoard);
         placeMarkByHumanPlayer(gameBoard, CROSS);
         printGameBoard(gameBoard);
      }
   }*/
    return 0;
}