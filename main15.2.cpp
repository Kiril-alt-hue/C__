#include "Point15.2.h"
#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // Для setprecision

void runPolygonTask() {
    std::cout << "=================================================" << std::endl;
    std::cout << "POLYGON CONSTRUCTION AND PERIMETER (Point Class)" << std::endl;
    std::cout << "=================================================" << std::endl;

    std::vector<Point> polygon_vertices;
    std::string user_response;

    std::cout << "Starting polygon input..." << std::endl;

    do {
        double x_coord, y_coord;

        std::cout << "\nDo you want to enter a vertex? (Yes/No): ";
        std::cin >> user_response;

        if (user_response == "No" || user_response == "no" || user_response == "n") {
            break;
        }

        std::cout << "Enter X coordinate: ";
        if (!(std::cin >> x_coord)) {
            std::cout << "Invalid input. Please restart the input process." << std::endl;
            break;
        }

        std::cout << "Enter Y coordinate: ";
        if (!(std::cin >> y_coord)) {
            std::cout << "Invalid input. Please restart the input process." << std::endl;
            break;
        }

        polygon_vertices.emplace_back(x_coord, y_coord);
        std::cout << "Vertex added: (" << x_coord << ", " << y_coord << ")." << std::endl;

    } while (true);


    std::cout << "\n--- Calculation Results ---" << std::endl;

    // Використовуємо статичний метод counter() для виведення кількості вершин
    int num_vertices = Point::counter();
    std::cout << "Number of vertices in the polygon (using Point::counter()): " << num_vertices << std::endl;

    if (num_vertices < 3) {
        std::cout << "A polygon must have at least 3 vertices. Perimeter cannot be calculated." << std::endl;
        return;
    }

    double perimeter = 0.0;

    for (size_t i = 0; i < polygon_vertices.size(); ++i) {
        const Point& current = polygon_vertices[i];

        // Наступна вершина. Оператор % polygon_vertices.size() забезпечує замикання (остання з першою)
        const Point& next = polygon_vertices[(i + 1) % polygon_vertices.size()];

        perimeter += current.distanceTo(next);
    }

    std::cout << std::fixed << std::setprecision(4); // Встановлюємо точність виведення
    std::cout << "Polygon Perimeter: " << perimeter << std::endl;
}


int main() {

    runPolygonTask();

    return 0;
}