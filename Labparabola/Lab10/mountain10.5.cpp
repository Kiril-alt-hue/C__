#include "mountain10.5.h"
#include <stdlib.h>
#include <string.h>

void readLine(char *buf, size_t size) {
    if (fgets(buf, (int)size, stdin) == NULL) {
        // if EOF or error, make buffer empty
        if (size > 0) buf[0] = '\0';
        return;
    }
    // remove trailing newline
    size_t len = strlen(buf);
    if (len > 0 && buf[len - 1] == '\n') buf[len - 1] = '\0';
}

void inputMountain(Mountain *m) {
    printf("Enter mountain name: ");
    readLine(m->name, NAME_LEN);

    printf("Enter mountain height: ");
    if (scanf("%d", &m->height) != 1) {
        m->height = 0;
    }

    int c = getchar();
    (void)c;
}


void printMountain(const Mountain *m) {
    printf("Name: %s, Height: %d\n", m->name, m->height);
}


Mountain *inputMountainArray(int n) {
    if (n <= 0) return NULL;
    Mountain *arr = (Mountain *)malloc(n * sizeof(Mountain));
    if (!arr) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    for (int i = 0; i < n; ++i) {
        printf("\n--- Mountain %d ---\n", i + 1);
        inputMountain(&arr[i]);
    }
    return arr;
}


void printMountainArray(const Mountain *arr, int n) {
    if (!arr || n <= 0) {
        printf("(no mountains)\n");
        return;
    }
    for (int i = 0; i < n; ++i) {
        printf("%d) ", i + 1);
        printMountain(&arr[i]);
    }
}


int findHighestIndex(const Mountain *arr, int n) {
    if (!arr || n <= 0) return -1;
    int maxIdx = 0;
    for (int i = 1; i < n; ++i) {
        if (arr[i].height > arr[maxIdx].height) {
            maxIdx = i;
        }
    }
    return maxIdx;
}


int findHeightByName(const Mountain *arr, int n, const char *name, int *outHeight) {
    if (!arr || n <= 0 || !name || !outHeight) return 0;
    for (int i = 0; i < n; ++i) {
        if (strcmp(arr[i].name, name) == 0) {
            *outHeight = arr[i].height;
            return 1;
        }
    }
    return 0;
}
