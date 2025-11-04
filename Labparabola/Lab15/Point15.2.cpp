#include "Point15.2.h"
#include <cmath>


int Point::count = 0;

Point::Point() : x(0.0), y(0.0) {
    count++; // Збільшуємо лічильник при створенні
}

Point::Point(double x_coord, double y_coord) : x(x_coord), y(y_coord) {
    count++; // Збільшуємо лічильник при створенні
}

Point::~Point() {
    count--; // Зменшуємо лічильник при знищенні
}

int Point::counter() {
    return count;
}

double Point::getX() const {
    return x;
}

double Point::getY() const {
    return y;
}

double Point::distanceTo(const Point& other) const {
    double dx = x - other.x;
    double dy = y - other.y;
    return std::sqrt(dx * dx + dy * dy);
}