#include "Vector15.12.h"
#include <algorithm> // Для std::copy
#include <limits>    // Для std::numeric_limits


Vector::Vector() : N(0), elements(nullptr) {}

Vector::Vector(int size) : N(size) {
    if (N <= 0) {
        N = 0;
        elements = nullptr;
    } else {
        elements = new double[N];
        for (int i = 0; i < N; ++i) {
            elements[i] = 0.0;
        }
    }
}


Vector::Vector(const Vector& other) : N(other.N) {
    if (N > 0) {
        elements = new double[N];
        std::copy(other.elements, other.elements + N, elements);
    } else {
        elements = nullptr;
    }
}


Vector::~Vector() {
    delete[] elements;
    elements = nullptr;
    N = 0;
}

Vector& Vector::operator=(const Vector& other) {
    if (this == &other) {
        return *this;
    }

    delete[] elements;

    N = other.N;

    if (N > 0) {
        elements = new double[N];
        std::copy(other.elements, other.elements + N, elements);
    } else {
        elements = nullptr;
    }

    return *this;
}

void Vector::setElements(const double* data) {
    if (data != nullptr && N > 0) {
        std::copy(data, data + N, elements);
    }
}

void Vector::setElement(int index, double value) {
    if (index >= 0 && index < N) {
        elements[index] = value;
    } else {
        std::cerr << "Помилка: Індекс " << index << " поза межами [0, " << N - 1 << "]." << std::endl;
    }
}

double Vector::dotProduct(const Vector& other) const {
    if (N != other.N) {
        std::cerr << "Message: Dot product is impossible. Dimensions do not match ("
                  << N << " != " << other.N << ")." << std::endl;
        return std::numeric_limits<double>::quiet_NaN();
    }

    double result = 0.0;
    for (int i = 0; i < N; ++i) {
        result += elements[i] * other.elements[i];
    }
    return result;
}

Vector Vector::crossProduct(const Vector& other) const {
    if (N != 3 || other.N != 3) {
        std::cerr << "Message: Cross product is only possible for 3D vectors. Dimensions: ("
                  << N << ", " << other.N << ")." << std::endl;
        return Vector();
    }

    Vector result(3);

    result.elements[0] = elements[1] * other.elements[2] - elements[2] * other.elements[1];
    result.elements[1] = elements[2] * other.elements[0] - elements[0] * other.elements[2];
    result.elements[2] = elements[0] * other.elements[1] - elements[1] * other.elements[0];

    return result;
}


bool Vector::readFromFile(const std::string& filename) {
    std::ifstream ifs(filename);
    if (!ifs.is_open()) {
        std::cerr << "Помилка: Не вдалося відкрити файл " << filename << " для читання." << std::endl;
        return false;
    }

    std::vector<double> temp_data;
    double value;
    while (ifs >> value) {
        temp_data.push_back(value);
    }
    ifs.close();

    int new_N = temp_data.size();

    if (new_N == 0) {
        std::cerr << "Помилка: Файл " << filename << " порожній або містить недійсні дані." << std::endl;
        return false;
    }

    if (N != new_N) {
        Vector temp_vector(new_N);
        *this = temp_vector;
    }

    std::copy(temp_data.begin(), temp_data.end(), elements);

    return true;
}


bool Vector::writeToFile(const std::string& filename) const {
    std::ofstream ofs(filename);
    if (!ofs.is_open()) {
        std::cerr << "Error: Could not open file " << filename << " for writing." << std::endl;
        return false;
    }


    ofs << "Dimension: " << N << std::endl;
    ofs << "Elements: ";
    for (int i = 0; i < N; ++i) {
        ofs << elements[i] << (i == N - 1 ? "" : " ");
    }
    ofs << std::endl;

    ofs.close();
    return true;
}