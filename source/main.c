#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <conio.h>
#include <stdbool.h>

char input_c;

// Grid
int length, width;
char grid[20][20];

void print_title_screen() {
    char title_name[270] = " ******    ***   **     *****     **   **    *******\n**         ****  **    **   **    **  **     **     \n *****     ** ** **    *******    *****      *****  \n     **    **  ****    **   **    **  **     **     \n******     **   ***    **   **    **   **    *******\n";
    printf("%s", title_name);
}

/*
 * Input for gameplay
 */
void check_input() {
    if (kbhit()) {
        input_c = getch();
        //printf("%c is pressed", input_c);
    }
}

void title_loop() {
    for (;;) {
        print_title_screen();

        // Get menu selection input
        if (getch() == '\033') {
            switch (getch()) {
                case 'A': // Up

                    break;
                case 'B': // Down

                    break;
            }
        }
    }
}

int main(void) {
    
    bool is_quitted = false;
    while (!is_quitted) {

    }
    title_loop();

    // Game loop
    for (;;) {
        check_input();
    }

    return 0;
}