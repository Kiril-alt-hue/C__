#include "chess10.2.h"
#include <stdlib.h>

void inputSquare(ChessSquare *s) {
    printf("Enter square (e.g., a5): ");
    scanf(" %c%d", &s->column, &s->row);
}

void printSquare(ChessSquare s) {
    printf("%c%d", s.column, s.row);
}

int canQueenMove(ChessSquare from, ChessSquare to) {
    int colFrom = from.column - 'a' + 1;
    int colTo = to.column - 'a' + 1;

    if (from.row == to.row || colFrom == colTo)
        return 1;

    if (abs(from.row - to.row) == abs(colFrom - colTo))
        return 1;

    return 0;
}
