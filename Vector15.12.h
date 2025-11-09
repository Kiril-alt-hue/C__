#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector> // Використовуємо std::vector для тимчасового зберігання вводу з файлу

class Vector {
private:
    int N;          // Кількість елементів (розмірність вектора)
    double* elements; // Динамічний масив дійсних чисел

public:

    Vector();

    Vector(int size);

    Vector(const Vector& other);

    ~Vector();

    Vector& operator=(const Vector& other);

    void setElements(const double* data);

    void setElement(int index, double value);

    int getSize() const { return N; }

    double dotProduct(const Vector& other) const;

    Vector crossProduct(const Vector& other) const;

    bool readFromFile(const std::string& filename);

    bool writeToFile(const std::string& filename) const;
};