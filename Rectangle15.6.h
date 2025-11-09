#pragma once

#include <iostream>
#include <algorithm> // Для std::max, std::min

class Rectangle {
private:
    double x_top_left;    // Координата X лівого верхнього кута
    double y_top_left;    // Координата Y лівого верхнього кута
    double width;         // Довжина сторони по осі X (ширина)
    double height;        // Довжина сторони по осі Y (висота)

public:
    Rectangle(double x, double y, double w, double h);

    double getWidth() const;

    double getHeight() const;

    double getArea() const;

    double getPerimeter() const;

    Rectangle intersect(const Rectangle& other) const;

    void printInfo() const;
};