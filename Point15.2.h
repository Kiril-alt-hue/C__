#pragma once

#include <cmath>


class Point {
private:
    double x; // Координата X
    double y; // Координата Y

    // Статичний член-лічильник екземплярів класу Point
    static int count;

public:
    Point();

    Point(double x_coord, double y_coord);

    ~Point();

    static int counter();

    double getX() const;

    double getY() const;

    double distanceTo(const Point& other) const;
};