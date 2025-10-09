#include <stdio.h>
#include <stdlib.h>
#include "mountain10.5.h"

int main(void) {
    int n;
    printf("Enter number of mountains (N): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid N.\n");
        return 1;
    }
    // consume newline before reading lines
    int ch = getchar();
    (void)ch;

    Mountain *arr = inputMountainArray(n);
    if (!arr) return 1;

    printf("\n--- List of mountains ---\n");
    printMountainArray(arr, n);

    int maxIdx = findHighestIndex(arr, n);
    if (maxIdx >= 0) {
        printf("\nHighest mountain: %s (height %d)\n",
               arr[maxIdx].name, arr[maxIdx].height);
    } else {
        printf("\nCould not determine highest mountain.\n");
    }

    // Search by name
    char query[NAME_LEN];
    printf("\nEnter name to search for height: ");
    // use readLine from module (we can't call it directly here because it's in mountain.c and declared extern)
    // but readLine is declared in mountain.h and defined in mountain.c, so we can call it:
    readLine(query, NAME_LEN);

    int foundHeight;
    if (findHeightByName(arr, n, query, &foundHeight)) {
        printf("Mountain \"%s\" has height %d.\n", query, foundHeight);
    } else {
        printf("Mountain \"%s\" not found in the array.\n", query);
    }

    free(arr);
    return 0;
}
