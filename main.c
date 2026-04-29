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
void battle_animation();
void draw_ui(const char *title, const char *line1, const char *line2);
void clear_screen();
void track_player_choice(int player_choice);
int predict_player_move();

// ----- memory for prediction -----
int history[50];
int history_index = 0;

// ----- clear screen -----
void clear_screen() {
    printf("\033[H\033[J");
}

// ----- player input -----
int get_player_choice() {
    int choice;

    while (1) {
        printf("\nEnter your choice:\n");
        printf("1. Rock\n2. Paper\n3. Scissors\n> ");

        if (scanf("%d", &choice) != 1) {
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

// ----- computer fallback random -----
int get_computer_choice() {
    return rand() % 3 + 1;
}

// ----- print choice -----
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
        printf("💀 Computer wins!\n");
    else
        printf("🤝 It's a tie!\n");
}

// ----- store history -----
void track_player_choice(int player_choice) {
    history[history_index % 50] = player_choice;
    history_index++;
}

// ----- prediction system -----
int predict_player_move() {
    int rock = 0, paper = 0, scissors = 0;

    for (int i = 0; i < history_index && i < 50; i++) {
        if (history[i] == 1) rock++;
        else if (history[i] == 2) paper++;
        else if (history[i] == 3) scissors++;
    }

    if (rock >= paper && rock >= scissors) return 1;
    if (paper >= rock && paper >= scissors) return 2;
    return 3;
}

// ----- battle animation -----
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

// ----- UI -----
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

        clear_screen();

        printf("\n===== ROUND %d =====\n", round++);

        battle_animation();

        int player = get_player_choice();

        // store FIRST, then predict
        track_player_choice(player);
        int predicted = predict_player_move();

        int computer;

        // counter predicted player move
        if (predicted == 1) computer = 2;
        else if (predicted == 2) computer = 3;
        else computer = 1;

        printf("\nYou Summon: ");
        print_choice(player);

        printf("\nEnemy Summons: ");
        print_choice(computer);

        printf("\n");

        int result = determine_winner(player, computer);

        if (result == 1) {
            printf("🔥 You win this round!\n");
            player_score++;
        }
        else if (result == -1) {
            printf("💀 Computer wins!\n");
            computer_score++;
        }
        else {
            printf("🤝 Tie!\n");
        }

        draw_ui(
            "ROUND STATUS",
            player_score > computer_score ? "You leading" :
            player_score < computer_score ? "Enemy leading" : "Even fight",
            "Keep going..."
        );

        while (1) {
            printf("\nPlay again? (y/n): ");
            scanf(" %c", &play_again);

            if (play_again == 'y' || play_again == 'Y' ||
                play_again == 'n' || play_again == 'N') {
                break;
            }

            printf("Only y or n 😭\n");
        }
    }

    clear_screen();
    display_final_results(player_score, computer_score);

    return 0;
}