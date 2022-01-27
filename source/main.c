#include <stdio.h>
#include <unistd.h>
#include <conio.h>

int main(void) {

    char c;
    while (1) {
        if (kbhit()) {
            c = getch();

            if ((int)c == 27)
                break;
            
            printf("%c is pressed", c);
        }
    }

    return 0;
}