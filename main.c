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
 * Student Name  :
 * Student ID    :
 * Class/Section :
 * Date          :
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

}


/* Display the game board on the screen
   You are required to follow exactly the output format stated in the project specification
 */
void printGameBoard(int gameBoard[SIZE][SIZE]) {


}


/* Ask the human player to place the mark.
   In Part 1, you can assume that the user input must be valid (i.e, an empty space between 1 and 16). */
void placeMarkByHumanPlayer(int gameBoard[SIZE][SIZE], int mark) {


}


/* Return 1 if there is a winner in the game, otherwise return 0 */
/* Note: the winner is the current player indicated in main() */
int hasWinner(int gameBoard[SIZE][SIZE]) {

  return 0;
}

/* Determine the next move of the computer player.
   You are required to implement the following strategy:
   place the mark in the first empty space scanning from 1 to 16. */
void placeMarkByComputerPlayer(int gameBoard[SIZE][SIZE], int mark) {


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

    return 0;
}