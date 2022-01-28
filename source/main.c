#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <conio.h>
#include <stdbool.h>

typedef struct {
    int x, y;
} Body;

char input_c;

// Grid
int length = 15, width = 10;
char grid[20][20];

// Menu
int selection_index = 0;
bool is_quitted = false;

// Define functions
void print_board(void);

/*
 * Print the title "SNAKE"
 */
void print_title_screen(void) {
    char title_name[270] = " ******    ***   **     *****     **   **    *******\n**         ****  **    **   **    **  **     **     \n *****     ** ** **    *******    *****      *****  \n     **    **  ****    **   **    **  **     **     \n******     **   ***    **   **    **   **    *******\n";
    printf("%s", title_name);
}

/*
 * Input for gameplay
 */
void check_input(void) {
    if (kbhit()) {
        input_c = getch();
        printf("%c is pressed", input_c);
    }
}

/*
 * The title loop for menu selecting
 */
void title_loop(void) {
    char selections[3][10] = { "Start", "Option", "Quit" };
    bool title_exitted = false;

    for (;;) {

        print_title_screen();

        // Print selections
        for (int i = 0; i < 3; i++) {
            char c = ' ';
            if (selection_index == i)
                c = '>';
            printf("%c %s\n", c, selections[i]);
        }

        // Get menu selection input
        switch (getch()) {
            case 224: // Arrow
                switch (getch()) {
                    case 72: // Up
                        selection_index--;
                        if (selection_index < 0)
                            selection_index = 2;
                        break;

                    case 80: // Down
                        selection_index++;
                        if (selection_index > 2)
                            selection_index = 0;
                        break;
                }
                break;

            case 13: // Enter
                // Main menu selection
                switch (selection_index) {
                    case 0: // Start
                        title_exitted = true;
                        break;

                    case 1: // Option
                        system("cls");
                        break;

                    case 2: // Quit
                        title_exitted = true;
                        is_quitted = true;
                        break;
                }
                break;
        }

        if (title_exitted) break;

        system("cls");
    }
}

/*
 * The option selecting loop
 * TODO: Finish with file I/O
 */
void option_selecting(void) {

}

/*
 * Game loop
 */
void game_loop(void) {
    for (;;) {
        print_board();

        //check_input();

        sleep(1);

        system("cls");
    }
}

/*
 * Print board
 */
void print_board(void) {
    char board_str[length * (width + 1)];
    int str_index = 0;
    for (register int i = 0; i < width; i++) {
        for (register int j = 0; j < length; j++) {
            board_str[str_index] = grid[i][j];
            str_index++;
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
    //printf(board_str);
}

int main(void) {
    
    // Initialize board
    for (register int i = 0; i < width; i++) {
        for (register int j = 0; j < length; j++) {
            grid[i][j] = 'O';
        }
    }

    for (;;) {
        // Title loop
        title_loop();
        if (is_quitted) return 0;

        // Game loop
        game_loop();
    }
    
    return 0;
}