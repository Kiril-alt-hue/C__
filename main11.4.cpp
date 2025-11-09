#include <stdio.h>
#include "rectangle_manager11.4.h"

void setupInitialFile(const char* filename) {
    FILE* file = fopen(filename, "wb");
    if(!file) return;
    fclose(file);

    // Add some sample rectangles
    addRectangleToFile(filename, (Rectangle){101, 0.0, 10.0, 10.0, 0.0});    // Area = 100
    addRectangleToFile(filename, (Rectangle){102, -5.0, 5.0, 0.0, 0.0});     // Area = 25
    addRectangleToFile(filename, (Rectangle){103, 20.0, 30.0, 40.0, 20.0});  // Area = 200
    addRectangleToFile(filename, (Rectangle){104, 1.0, 2.0, 3.0, 1.0});      // Area = 2
}

void printMenu() {
    printf("\n--- RECTANGLE FILE MANAGER ---\n");
    printf("1. Find rectangle with the largest area\n");
    printf("2. Delete a rectangle by its ID\n");
    printf("3. Replace a rectangle by its index (position)\n");
    printf("4. Display all rectangles\n");
    printf("0. Exit\n");
    printf("Your choice: ");
}

int main() {
    const char* FILENAME = "rectangles.dat";
    setupInitialFile(FILENAME);

    int choice;
    do {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                findMaxAreaRectangle(FILENAME);
                break;
            case 2: {
                int idToDelete;
                printf("Enter the ID of the rectangle to delete: ");
                scanf("%d", &idToDelete);
                deleteRectangleById(FILENAME, idToDelete);
                break;
            }
            case 3: {
                int index;
                Rectangle newRect;
                printf("Enter the index (position, starting from 1) to replace: ");
                scanf("%d", &index);
                printf("Enter new data (ID X1 Y1 X2 Y2): ");
                scanf("%d %lf %lf %lf %lf", &newRect.id, &newRect.x1, &newRect.y1, &newRect.x2, &newRect.y2);
                replaceRectangleByIndex(FILENAME, index, newRect);
                break;
            }
            case 4:
                printAllRectangles(FILENAME);
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}