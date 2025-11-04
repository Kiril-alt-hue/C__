#include "Rectangle15.6.h"
#include <iostream>

void runRectangleTask() {
    std::cout << "=================================================" << std::endl;
    std::cout << "RECTANGLE CLASS TESTING" << std::endl;
    std::cout << "=================================================" << std::endl;

    Rectangle r1(0.0, 10.0, 5.0, 5.0);
    std::cout << "--- Rectangle R1 ---" << std::endl;
    r1.printInfo();
    std::cout << "Obtaining side lengths:" << std::endl;
    std::cout << "  Width: " << r1.getWidth() << std::endl;
    std::cout << "  Height: " << r1.getHeight() << std::endl;

    Rectangle r2(3.0, 7.0, 4.0, 4.0);
    std::cout << "\n--- Rectangle R2 ---" << std::endl;
    r2.printInfo();

    std::cout << "\n--- Intersection R1 and R2 ---" << std::endl;
    Rectangle intersection_r1_r2 = r1.intersect(r2);
    intersection_r1_r2.printInfo();

    Rectangle r3(100.0, 100.0, 10.0, 10.0);
    std::cout << "\n--- Intersection R1 and R3 (Should be Empty) ---" << std::endl;
    Rectangle intersection_r1_r3 = r1.intersect(r3);

    if (intersection_r1_r3.getWidth() <= 0 && intersection_r1_r3.getHeight() <= 0 &&
        intersection_r1_r3.getWidth() == 0.0 && intersection_r1_r3.getHeight() == 0.0) {
        std::cout << "Intersection is empty. Returned indicator Rectangle (-1.0, -1.0, 0.0, 0.0)." << std::endl;
    } else {
        intersection_r1_r3.printInfo();
    }
}

int main() {
    runRectangleTask();
    return 0;
}