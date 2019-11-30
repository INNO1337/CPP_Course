#include "Base.h"
#include "Matrix.h"
#include "Vector.h"
#include <cmath>

using namespace mat_vec;

Vector::Vector(size_t size, double value): size_(size) {
    allocation();
    for (int i = 0; i < size; i++){
        vec[i] = value;
    }
}

void Vector::allocation() {
    vec = new double [size_];
}

Vector::Vector(const Vector &src) {
    size_ = src.size_;
    allocation();
    for (int i = 0; i < src.size_; i++){
        vec[i] = src.vec[i];
    }
}

Vector &Vector::operator=(const Vector &rhs) {
    Vector v(rhs.size_, 0);
    for (int i = 0; i < size_; i++){
        v[i] = rhs.vec[i];
    }
    for (int i = 0; i < size_; i++){
        vec[i] = v[i];
    }
    return *this;
}

Vector::~Vector() {
    delete[] vec;
}

size_t Vector::size() const {
    return size_;
}

void Vector::normalize() {
    double len = 0;
    for (int i = 0; i < size_; i++){
        len += vec[i] * vec[i];
    }
    len = sqrt(len);
    double invLen = 1 / len;
    for (int i = 0; i < size_; i++){
        vec[i] = vec[i] * invLen;
    }
}

Vector Vector::normalized() const {
    Vector v(size_, 0);
    double len = 0;
    for (int i = 0; i < size_; i++){
        len += vec[i] * vec[i];
    }
    len = sqrt(len);
    double invLen = 1 / len;
    for (int i = 0; i < size_; i++){
        v.vec[i] = vec[i] * invLen;
    }
    return v;
}

double &Vector::operator[](size_t n) {
    return vec[n];
}

double Vector::operator[](size_t n) const {
    return vec[n];
}

Vector &Vector::operator+=(const Vector &rhs) {
    for (int i = 0; i < size_; i++){
        vec[i] += rhs.vec[i];
    }
    return *this;
}

Vector &Vector::operator-=(const Vector &rhs) {
    for (int i = 0; i < size_; i++){
        vec[i] -= rhs.vec[i];
    }
    return *this;
}

Vector &Vector::operator*=(double k) {
    for (int i = 0; i < size_; i++){
        vec[i] *= k;
    }
    return *this;
}

Vector &Vector::operator/=(double k) {
    for (int i = 0; i < size_; i++){
        vec[i] /= k;
    }
    return *this;
}

bool Vector::operator==(const Vector &rhs) const {
    for (int i = 0; i < size_; i++){
        if (std::abs(vec[i] - rhs.vec[i]) > eps){
            return false;
        }
    }
    return true;
}

bool Vector::operator!=(const Vector &rhs) const {
    for (int i = 0; i < size_; i++){
        if (std::abs(vec[i] - rhs.vec[i]) < eps){
            return false;
        }
    }
    return true;
}

Vector Vector::operator+(const Vector &rhs) const {
    Vector v(size_, 0);
    for (int i = 0; i < size_; i++){
        v.vec[i] = vec[i] + rhs.vec[i];
    }
    return v;
}

Vector Vector::operator-(const Vector &rhs) const {
    Vector v(size_, 0);
    for (int i = 0; i < size_; i++){
        v.vec[i] = vec[i] - rhs.vec[i];
    }
    return v;
}

Vector Vector::operator*(double k) const {
    Vector v(size_, 0);
    for (int i = 0; i < size_; i++){
        v.vec[i] = vec[i] * k;
    }
    return v;
}

Vector Vector::operator/(double k) const {
    Vector v(size_, 0);
    for (int i = 0; i < size_; i++){
        v.vec[i] = vec[i] / k;
    }
    return v;
}

Vector &Vector::operator^=(const Vector &rhs) {
    for (int i = 0; i < size_; i++){
        vec[i] *= rhs.vec[i];
    }
    return *this;
}

Vector Vector::operator^(const Vector &rhs) const {
    Vector v(size_, 0);
    for (int i = 0; i < size_; i++){
        v.vec[i] = vec[i] * rhs.vec[i];
    }
    return v;
}

double Vector::operator*(const Vector &rhs) const {
    double dot = 0;
    for (int i = 0; i < size_; i++){
        dot += vec[i] * rhs.vec[i];
    }
    return dot;
}

double Vector::norm() const {
    double sum = 0;
    for (int i = 0; i < size_; i++) {
        sum += vec[i] * vec[i];
    }
    return (std::sqrt(sum));
}

Vector &Vector::operator*=(const Matrix &mat) {
    Vector v(size_, 0);
    for (int i = 0; i < size_; i++){
        for (int j = 0; j < size_; j++){
            v[i] += mat.get(i, 1) * vec[j];
        }
    }
    for (int i = 0; i < size_; i++){
        vec[i] = v.vec[i];
    }
    return *this;
}

Vector Vector::operator*(const Matrix &mat) const {
    Vector v(size_, 0);
    for (int i = 0; i < size_; i++){
        for (int j = 0; j < size_; j++){
            v[i] += mat.get(i, 1) * vec[j];
        }
    }
    return v;
}
