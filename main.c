/* goal:
        1. create a simple rock-paper-scissors game in C
        2. allow the player to play against the computer
        3. keep track of scores and display final results at the end
        4. use a simple command line interface for interaction  

*/
#define _POSIX_C_SOURCE 199309L

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// ----- prototypes -----
int get_player_choice();
int get_computer_choice();
int determine_winner(int player, int computer);
void display_final_results(int player_score, int computer_score);
void print_choice(int choice);

// ----- player input -----
int get_player_choice() {
    int choice;

    while (1) {
        printf("\nEnter your choice:\n");
        printf("1. Rock\n2. Paper\n3. Scissors\n> ");

        if (scanf("%d", &choice) != 1) {
            // clear bad input
            while (getchar() != '\n');
            printf("Invalid input. Try again.\n");
            continue;
        }

        if (choice >= 1 && choice <= 3) {
            return choice;
        }

        printf("Pick only 1, 2, or 3.\n");
    }
}

// ----- computer choice -----
int get_computer_choice() {
    return rand() % 3 + 1;
}

// ----- show choice -----
void print_choice(int choice) {
    switch (choice) {
        case 1: printf("Rock"); break;
        case 2: printf("Paper"); break;
        case 3: printf("Scissors"); break;
    }
}

// ----- winner logic -----
int determine_winner(int player, int computer) {
    if (player == computer) return 0;

    if ((player == 1 && computer == 3) ||
        (player == 2 && computer == 1) ||
        (player == 3 && computer == 2)) {
        return 1;
    }

    return -1;
}

// ----- final result -----
void display_final_results(int player_score, int computer_score) {
    printf("\n===== FINAL SCORE =====\n");
    printf("Player: %d | Computer: %d\n", player_score, computer_score);

    if (player_score > computer_score)
        printf("🔥 You won the game!\n");
    else if (computer_score > player_score)
        printf("💀 Computer won. Skill issue (jk)\n");
    else
        printf("🤝 It's a tie!\n");
}

// battle animation
void battle_animation() {
    printf("\nPreparing battle");
    fflush(stdout);

    for (int i = 0; i < 3; i++) {
        sleep(1);
        printf(".");
        fflush(stdout);
    }

    printf("\n");

    char *frames[] = {
        "[ Rock... ]",
        "[ Paper... ]",
        "[ Scissors... ]",
        "   FIGHT! 💥"
    };

    for (int i = 0; i < 4; i++) {
        printf("\r%s", frames[i]);
        fflush(stdout);
        sleep(1);
    }

    printf("\n\n");
}
// box ui
void draw_ui(const char *title, const char *line1, const char *line2) {
    printf("____________________\n");
    printf("| %-18s |\n", title);
    printf("|--------------------|\n");
    printf("| %-18s |\n", line1);
    printf("| %-18s |\n", line2);
    printf("|____________________|\n");
}


// ----- main -----
int main() {
    srand(time(0));

    int player_score = 0, computer_score = 0;
    char play_again = 'y';
    int round = 1;

    while (play_again == 'y' || play_again == 'Y') {

        printf("\n===== ROUND %d =====\n", round++);
       draw_ui();
        battle_animation();

        int player = get_player_choice();
        int computer = get_computer_choice();

        printf("You Summon !!: ");
        print_choice(player);

        printf("\nChaos Monster SUmmons!!: ");
        print_choice(computer);
        printf("\n");

        int result = determine_winner(player, computer);

        if (result == 1) {
            printf("🔥 You win this round!\n");
            player_score++;
        } else if (result == -1) {
            printf("💀 Computer wins this round!\n");
            computer_score++;
        } else {
            printf("🤝 Round is a tie!\n");
        }

        printf("\nPlay again? (y/n): ");
        scanf(" %c", &play_again);
    }

    display_final_results(player_score, computer_score);

    return 0;
}