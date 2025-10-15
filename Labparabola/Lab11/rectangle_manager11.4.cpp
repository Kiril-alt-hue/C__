#include "rectangle_manager11.4.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void findMaxAreaRectangle(const char* filename) {
    FILE* file = fopen(filename, "rb"); // "rb" for reading binary
    if (!file) {
        perror("Could not open file for reading");
        return;
    }

    Rectangle rect;
    double maxArea = -1.0;
    int maxId = -1;
    int found = 0;

    while (fread(&rect, sizeof(Rectangle), 1, file) == 1) {
        found = 1;
        double width = fabs(rect.x2 - rect.x1);
        double height = fabs(rect.y2 - rect.y1);
        double currentArea = width * height;

        if (currentArea > maxArea) {
            maxArea = currentArea;
            maxId = rect.id;
        }
    }

    if (found) {
        printf("Rectangle with the largest area has ID %d with an area of %.2f\n", maxId, maxArea);
    } else {
        printf("The file is empty or could not be read.\n");
    }

    fclose(file);
}

void deleteRectangleById(const char* filename, int id) {
    FILE* sourceFile = fopen(filename, "rb");
    if (!sourceFile) {
        perror("Could not open source file for deletion process");
        return;
    }

    const char* tempFilename = "temp_rect.dat";
    FILE* tempFile = fopen(tempFilename, "wb");
    if (!tempFile) {
        perror("Could not create temporary file");
        fclose(sourceFile);
        return;
    }

    Rectangle rect;
    int deleted = 0;
    while (fread(&rect, sizeof(Rectangle), 1, sourceFile) == 1) {
        if (rect.id != id) {
            fwrite(&rect, sizeof(Rectangle), 1, tempFile);
        } else {
            deleted = 1;
        }
    }

    fclose(sourceFile);
    fclose(tempFile);

    remove(filename);
    rename(tempFilename, filename);

    if (deleted) {
        printf("Rectangle with ID %d has been deleted.\n", id);
    } else {
        printf("Rectangle with ID %d was not found.\n", id);
    }
}

void replaceRectangleByIndex(const char* filename, int index, Rectangle newRect) {
    FILE* file = fopen(filename, "rb+");
    if (!file) {
        perror("Could not open file for replacement");
        return;
    }

    long offset = (long)(index - 1) * sizeof(Rectangle);

    if (fseek(file, offset, SEEK_SET) != 0) {
        fprintf(stderr, "Error: Could not seek to position %d. The index might be out of bounds.\n", index);
        fclose(file);
        return;
    }

    if (fwrite(&newRect, sizeof(Rectangle), 1, file) != 1) {
        fprintf(stderr, "Error: Failed to write new data at index %d.\n", index);
    } else {
        printf("Successfully replaced rectangle at index %d.\n", index);
    }

    fclose(file);
}



void addRectangleToFile(const char* filename, Rectangle rect) {
    FILE* file = fopen(filename, "ab"); // "ab" for appending binary
    if (!file) {
        perror("Could not open file to add rectangle");
        return;
    }
    fwrite(&rect, sizeof(Rectangle), 1, file);
    fclose(file);
}

void printAllRectangles(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("Could not open file to print contents");
        return;
    }

    printf("\n--- Current Rectangles in '%s' ---\n", filename);
    Rectangle rect;
    int index = 1;
    while (fread(&rect, sizeof(Rectangle), 1, file) == 1) {
        printf("Index: %-3d | ID: %-3d | Top-Left: (%5.1f, %5.1f) | Bottom-Right: (%5.1f, %5.1f)\n",
               index++, rect.id, rect.x1, rect.y1, rect.x2, rect.y2);
    }
    printf("----------------------------------------\n");
    fclose(file);
}