#include "Rectangle15.6.h"
#include <algorithm>
#include <iostream>


Rectangle::Rectangle(double x, double y, double w, double h)
    : x_top_left(x), y_top_left(y) {
    // Гарантуємо, що ширина і висота додатні
    width = (w > 0) ? w : 0;
    height = (h > 0) ? h : 0;
}

double Rectangle::getWidth() const {
    return width;
}

double Rectangle::getHeight() const {
    return height;
}

double Rectangle::getArea() const {
    return width * height;
}

double Rectangle::getPerimeter() const {
    return 2.0 * (width + height);
}

void Rectangle::printInfo() const {
    if (width <= 0 || height <= 0) {
        std::cout << "Empty Rectangle (Indicator: -1, -1, -1, -1)." << std::endl;
        return;
    }
    std::cout << "Rectangle Info:" << std::endl;
    std::cout << "  Top-Left Corner (x, y): (" << x_top_left << ", " << y_top_left << ")" << std::endl;
    std::cout << "  Width (w): " << width << std::endl;
    std::cout << "  Height (h): " << height << std::endl;
    std::cout << "  Area: " << getArea() << std::endl;
    std::cout << "  Perimeter: " << getPerimeter() << std::endl;
}


Rectangle Rectangle::intersect(const Rectangle& other) const {
    double x1_right = x_top_left + width;
    double x2_right = other.x_top_left + other.width;

    double y1_bottom = y_top_left - height;
    double y2_bottom = other.y_top_left - other.height;


    // X-координата лівого верхнього кута перетину
    double intersect_x_top_left = std::max(x_top_left, other.x_top_left);

    // Y-координата лівого верхнього кута перетину (найвища Y)
    double intersect_y_top_left = std::min(y_top_left, other.y_top_left); // Min Y, оскільки Y_top_left - найвища координата

    // X-координата правого нижнього кута перетину (найменша X_right)
    double intersect_x_right = std::min(x1_right, x2_right);

    // Y-координата правого нижнього кута перетину (найнижча Y_bottom)
    double intersect_y_bottom = std::max(y1_bottom, y2_bottom);

    // 4. Обчислюємо розміри перетину
    double intersect_width = intersect_x_right - intersect_x_top_left;
    double intersect_height = intersect_y_top_left - intersect_y_bottom; // Висота = Y_top - Y_bottom

    // 5. Перевірка на порожній перетин
    if (intersect_width <= 0 || intersect_height <= 0) {
        return Rectangle(-1.0, -1.0, 0.0, 0.0); // width=0, height=0 для коректної внутрішньої роботи, але виводиться як індикатор
    }

    return Rectangle(intersect_x_top_left, intersect_y_top_left, intersect_width, intersect_height);
}