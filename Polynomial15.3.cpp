#include "Polynomial15.3.h"
#include <fstream>
#include <iomanip>
#include <algorithm> // Для std::copy


Polynomial::Polynomial() : size(1) {
    coeffs = new double[size];
    coeffs[0] = 0.0;
}


Polynomial::Polynomial(int N) : size(N) {
    if (N <= 0) {
        size = 1;
    }

    coeffs = new double[size];
    for (int i = 0; i < size; ++i) {
        coeffs[i] = 0.0;
    }
}

Polynomial::Polynomial(const Polynomial& other) : size(other.size) {
    coeffs = new double[size];

    std::copy(other.coeffs, other.coeffs + size, coeffs);
}


Polynomial::~Polynomial() {
    delete[] coeffs;
    coeffs = nullptr; // Встановлюємо в nullptr, щоб уникнути "висячих" покажчиків
}


Polynomial& Polynomial::operator=(const Polynomial& other) {
    if (this == &other) {
        return *this;
    }

    delete[] coeffs;

    size = other.size;

    coeffs = new double[size];

    std::copy(other.coeffs, other.coeffs + size, coeffs);

    return *this;
}

void Polynomial::setCoefficients(const double* new_coeffs) {
    if (new_coeffs != nullptr) {
        std::copy(new_coeffs, new_coeffs + size, coeffs);
    }
}

void Polynomial::setCoefficient(int index, double value) {
    if (index >= 0 && index < size) {
        coeffs[index] = value;
    } else {
        std::cerr << "Error: Coefficient index " << index << " out of bounds [0, " << size - 1 << "]." << std::endl;
    }
}

void Polynomial::print() const {
    std::cout << *this << std::endl;
}


std::ostream& operator<<(std::ostream& os, const Polynomial& poly) {
    bool first_term = true;

    for (int i = poly.size - 1; i >= 0; --i) {
        double coeff = poly.coeffs[i];

        if (std::abs(coeff) < 1e-9 && i > 0 && poly.size > 1) {
            continue;
        }

        if (!first_term) {
            os << (coeff > 0 ? " + " : " - ");
        } else if (coeff < 0) {
            os << "-";
        }

        double abs_coeff = std::abs(coeff);
        os << std::fixed << std::setprecision(2);

        if (i == 0) {
            os << abs_coeff;
        } else {
            if (std::abs(abs_coeff - 1.0) > 1e-9) {
                os << abs_coeff; // Виводимо коефіцієнт, якщо він не 1
            } else if (first_term && std::abs(abs_coeff - 1.0) < 1e-9 && coeff > 0) {
                // Якщо перший коефіцієнт = 1, не виводимо 1, але не додаємо "+"
            } else if (!first_term && std::abs(abs_coeff - 1.0) < 1e-9) {
                // Якщо не перший коефіцієнт = 1
            }

            os << "x";
            if (i > 1) {
                os << "^" << i;
            }
        }

        first_term = false;
    }
    return os;
}

std::istream& operator>>(std::istream& is, Polynomial& poly) {
    std::cout << "Enter " << poly.size << " coefficients (from x^0 to x^" << poly.size - 1 << "):" << std::endl;
    for (int i = 0; i < poly.size; ++i) {
        std::cout << "Coefficient for x^" << i << ": ";
        // Введення коефіцієнта безпосередньо в масив
        if (!(is >> poly.coeffs[i])) {
            std::cerr << "Error reading coefficient. Input aborted." << std::endl;
            // Скидаємо прапор помилки і очищаємо буфер
            is.clear();
            is.ignore(10000, '\n');
            break;
        }
    }
    return is;
}


std::ofstream& writeToBinaryFile(std::ofstream& ofs, const Polynomial& poly) {
    ofs.write(reinterpret_cast<const char*>(&poly.size), sizeof(int));
    ofs.write(reinterpret_cast<const char*>(poly.coeffs), poly.size * sizeof(double));

    return ofs;
}