#include "structures10.1.h"
#include <stdlib.h>

int main() {
    Date d;
    ChessSquare sq;
    Rectangle rect;
    Polynomial pol;

    printf("\n--- (a) Date ---\n");
    inputDate(&d);
    printDate(d);

    printf("\n--- (b) Chess square ---\n");
    inputSquare(&sq);
    printSquare(sq);

    printf("\n--- (c) Rectangle ---\n");
    inputRectangle(&rect);
    printRectangle(rect);

    printf("\n--- (d) Polynomial ---\n");
    inputPolynomial(&pol);
    printPolynomial(pol);

    free(pol.coeff); // free memory for polynomial

    return 0;
}
