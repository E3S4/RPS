/*  goal :
1. Create a Simple Rock Paper Scissors Game in C
2. Use a simple command line interface to interact with the game
3. Use random number generation to simulate the computer's choice
4. Keep track of the player's score and the computer's score
5. Allow the player to play multiple rounds until they choose to quit
6. Display the final scores and declare the winner at the end of the game */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// -----Function prototypes-----

// the function to get the player's choice
int get_player_choice() {
    int choice;
    printf("Enter your choice (1 for Rock, 2 for Paper, 3 for Scissors): ");
    scanf("%d", &choice);
    return choice;
}
// generate the computer's choice
int get_computer_choice() {
    return rand() % 3 + 1; // generates a number between 1 and 3
}



// main function
int main()
{
    srand(time(0)); // seed the random number generator
    return 0;
}