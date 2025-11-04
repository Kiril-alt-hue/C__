#include "Vector15.12.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath> // Для std::isnan

const std::string FILE_VEC_A = "vector_a.txt";
const std::string FILE_VEC_B = "vector_b.txt";

void printVector(const Vector& vec, const std::string& name) {
    std::cout << name << " (Dim " << vec.getSize() << "): [";
    for (int i = 0; i < vec.getSize(); ++i) {
    }
    std::cout << "]" << std::endl;
}

void runVectorTask() {
    std::cout << "=================================================" << std::endl;
    std::cout << "TESTING THE VECTOR CLASS (Dynamic Arrays)" << std::endl;
    std::cout << "=================================================" << std::endl;

    Vector v1(4);
    double data1[] = {1.0, 2.0, 3.0, 4.0};
    v1.setElements(data1);

    Vector v2 = v1;
    Vector v3(2);
    double data3[] = {10.0, 20.0};
    v3.setElements(data3);
    v3 = v1;


    std::ofstream ofs_a(FILE_VEC_A);
    ofs_a << "1.5 2.5 3.5 4.5";
    ofs_a.close();

    std::ofstream ofs_b(FILE_VEC_B);
    ofs_b << "1.0 2.0 3.0";
    ofs_b.close();

    Vector v_file_a;
    Vector v_file_b;

    std::cout << "\n--- 3. File I/O Test ---" << std::endl;
    if (v_file_a.readFromFile(FILE_VEC_A)) {
        std::cout << "Success: v_file_a read from " << FILE_VEC_A << ". New dimension: " << v_file_a.getSize() << std::endl;
        v_file_a.writeToFile("output_a.txt");
    }
    if (v_file_b.readFromFile(FILE_VEC_B)) {
        std::cout << "Success: v_file_b read from " << FILE_VEC_B << ". New dimension: " << v_file_b.getSize() << std::endl;
    }


    std::cout << "\n--- 4. Dot Product Test ---" << std::endl;

    double dot_ok = v1.dotProduct(v3);
    if (!std::isnan(dot_ok)) {
        std::cout << "Dot Product (v1 . v3, Dim 4): " << dot_ok << std::endl; // Очікується 1*1 + 2*2 + 3*3 + 4*4 = 30
    }

    double dot_fail = v1.dotProduct(v_file_b);
    if (std::isnan(dot_fail)) {
        std::cout << "Dot Product (v1 . v_file_b, Dim 4 x 3): Operation Failed (as expected)." << std::endl;
    }

    std::cout << "\n--- 5. Cross Product Test ---" << std::endl;

    Vector v_3a(3); v_3a.setElement(0, 1); v_3a.setElement(1, 0); v_3a.setElement(2, 0); // (1, 0, 0)
    Vector v_3b(3); v_3b.setElement(0, 0); v_3b.setElement(1, 1); v_3b.setElement(2, 0); // (0, 1, 0)

    Vector cross_ok = v_3a.crossProduct(v_3b); // Очікується (0, 0, 1)
    if (cross_ok.getSize() == 3) {
        std::cout << "Cross Product (v_3a x v_3b, Dim 3): Success (Result Dim 3)." << std::endl;
    }

    Vector cross_fail = v1.crossProduct(v_file_b);
    if (cross_fail.getSize() == 0) {
        std::cout << "Cross Product (v1 x v_file_b, Dim 4 x 3): Operation Failed (as expected, Result Dim 0)." << std::endl;
    }

}

int main() {
    runVectorTask();
    return 0;
}