#ifndef RECTANGLE_MANAGER11_4_H
#define RECTANGLE_MANAGER11_4_H

typedef struct {
    int id;      // A unique identifier for the rectangle
    double x1;   // Top-left corner x-coordinate
    double y1;   // Top-left corner y-coordinate
    double x2;   // Bottom-right corner x-coordinate
    double y2;   // Bottom-right corner y-coordinate
} Rectangle;

void findMaxAreaRectangle(const char* filename);

void deleteRectangleById(const char* filename, int id);

void replaceRectangleByIndex(const char* filename, int index, Rectangle newRect);

void addRectangleToFile(const char* filename, Rectangle rect);

void printAllRectangles(const char* filename);

#endif //RECTANGLE_MANAGER11_4_H
