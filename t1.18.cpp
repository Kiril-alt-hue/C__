#include <stdio.h>

int main() {
    char board[9];

    printf("Enter 9 char (O, X or space): ");
    for(int i = 0; i < 9; i++) {
        scanf(" %c", &board[i]);
    }

    printf("\n %c | %c | %c \n", board[0], board[1], board[2]);
    printf("-----------\n");
    printf(" %c | %c | %c \n", board[3], board[4], board[5]);
    printf("-----------\n");
    printf(" %c | %c | %c \n", board[6], board[7], board[8]);

    return 0;
}