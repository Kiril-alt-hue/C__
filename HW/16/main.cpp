#include "Figure.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Polygon.h"
#include "Pentagon.h"

#include <iostream>
#include <vector>
#include <limits>

int main() {
    std::vector<Figure*> figures;

    figures.push_back(new Rectangle({0, 5}, {10, 0}));

    figures.push_back(new Triangle({0, 0}, {3, 4}, {3, 0}));

    figures.push_back(new Pentagon({0, 0}, {2, 0}, {3, 2}, {1, 3}, {-1, 2})); // P > 12

    std::vector<Point> nonConvexPoints = {{0, 0}, {4, 0}, {2, 2}, {4, 4}, {0, 4}};
    figures.push_back(new Polygon(nonConvexPoints));

    std::cout << "--- Finding all convex polygons ---" << std::endl;
    for (Figure* fig : figures) {

        Polygon* poly = dynamic_cast<Polygon*>(fig);

        if (poly != nullptr) {
            if (poly->isConvex()) {
                std::cout << "Found a convex polygon: ";
                poly->print();
                std::cout << std::endl;
            }
        }
    }

    std::cout << "\n--- Finding figure with smallest perimeter ---" << std::endl;

    double minPerimeter = std::numeric_limits<double>::max();
    Figure* minFigure = nullptr;

    for (Figure* fig : figures) {
        double currentPerimeter = fig->getPerimeter();

        std::cout << "Checking figure: ";
        fig->print();
        std::cout << "  | Perimeter: " << currentPerimeter << std::endl;

        if (currentPerimeter < minPerimeter) {
            minPerimeter = currentPerimeter;
            minFigure = fig;
        }
    }

    if (minFigure != nullptr) {
        std::cout << "\nFigure with the smallest perimeter (" << minPerimeter << ") is: ";
        minFigure->print();
        std::cout << std::endl;
    } else {
        std::cout << "No figures in the array." << std::endl;
    }

    std::cout << "\nCleaning up memory..." << std::endl;
    for (Figure* fig : figures) {
        delete fig;
    }
    figures.clear();

    return 0;
}