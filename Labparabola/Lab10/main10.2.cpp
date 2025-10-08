#include "chess10.2.h"

int main() {
    ChessSquare from, to;

    printf("Enter starting square:\n");
    inputSquare(&from);

    printf("Enter target square:\n");
    inputSquare(&to);

    printf("\nFrom ");
    printSquare(from);
    printf(" to ");
    printSquare(to);
    printf(": ");

    if (canQueenMove(from, to))
        printf("The queen CAN move in one move.\n");
    else
        printf("The queen CANNOT move in one move.\n");

    return 0;
}
