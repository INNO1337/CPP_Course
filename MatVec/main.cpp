#include "Matrix.h"
#include "Vector.h"
#include <iostream>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

using namespace mat_vec;

TEST_CASE("Оператор =") {
    Matrix m1(2, 2.0);
    Matrix m2(2, 3.0);
    Matrix m3(2, 3.0);
    m1 = m2;
    REQUIRE(m1 == m3);
}

TEST_CASE("== false") {
    Matrix m1(4, 4.0);
    Matrix m2(4, 5.0);
    REQUIRE(!(m1 == m2));
}

TEST_CASE("!= false") {
    Matrix m1(4, 4.0);
    Matrix m2(4, 4.0);
    REQUIRE(!(m1 != m2));
}

TEST_CASE("Оператор = vector") {
    Vector v1(2, 2.0);
    Vector v2(2, 3.0);
    Vector v3(2, 3.0);
    v1 = v2;
    REQUIRE(v1 == v3);
}

TEST_CASE("Get") {
    Matrix m1(3, 5.0);
    REQUIRE(m1.get(2, 2) == 5);
}

TEST_CASE("Оператор +=") {
    Matrix m1(3, 2.0);
    Matrix m2(3, 3.0);
    Matrix m3(3, 5.0);
    m1 += m2;
    REQUIRE(m1 == m3);
}

TEST_CASE("Оператор += vector") {
    Vector v1(3, 2.0);
    Vector v2(3, 3.0);
    Vector v3(3, 5.0);
    v1 += v2;
    REQUIRE(v1 == v3);
}

TEST_CASE("РћРїРµСЂР°С‚РѕСЂ -=") {
    Matrix m1(3, 2.0);
    Matrix m2(3, 3.0);
    Matrix m3(3, 5.0);
    m3 -= m2;
    REQUIRE(m1 == m3);
}

TEST_CASE("Оператор -= vector") {
    Vector v1(3, 2.0);
    Vector v2(3, 3.0);
    Vector v3(3, 5.0);
    v3 -= v2;
    REQUIRE(v1 == v3);
}

TEST_CASE("Оператор *=") {
    Matrix m1(3, 2.0);
    Matrix m2(m1);
    Matrix m3(3, 6.0);
    m2 *= 3;
    REQUIRE(m2 == m3);
}

TEST_CASE("Оператор *= vector") {
    Vector v1(3, 2.0);
    Vector v3(3, 6.0);
    v1 *= 3;
    REQUIRE(v1 == v3);
}

TEST_CASE("Оператор == vector") {
    Vector v1(4, 4.0);
    Vector v2(4, 5.0);
    REQUIRE(!(v1 == v2));
}

TEST_CASE("Оператор != vector") {
    Vector v1(4, 4.0);
    Vector v2(4, 4.0);
    REQUIRE(!(v1 != v2));
}

TEST_CASE("[]") {
    Vector v1(4, 4.0);
    REQUIRE(v1[2] == 4.0);
}

TEST_CASE("Умножение посимвольно") {
    Vector v1(4, 4.0);
    Vector v2(4, 16.0);
    v1 ^= v1;
    REQUIRE(v1 == v2);
}

TEST_CASE("norm - vector") {
    Vector v1(4, -4.0);
    double res = v1.norm();
    REQUIRE(res == 8);
}

TEST_CASE("pair") {
    Matrix m1(4, 14.0);
    std::pair<size_t, size_t> test123 = {4, 4};
    REQUIRE(test123 == m1.shape());
}

TEST_CASE("pair vector") {
    Vector v1(4, 14.0);
    size_t size = 4;
    REQUIRE(size == v1.size());
}

TEST_CASE("Оператор /=") {
    Matrix m1(3, 15.0);
    Matrix m3(3, 5.0);
    m1 /= 3;
    REQUIRE(m1 == m3);
}

TEST_CASE("Оператор /= vector") {
    Vector v1(3, 15.0);
    Vector v3(3, 5.0);
    v1 /= 3;
    REQUIRE(v1 == v3);
}

TEST_CASE("Оператор !=") {
    Matrix m1(3, 15.0);
    Matrix m2(3, 4.0);
    m1 /= 3;
    REQUIRE(m1 != m2);
}

// TEST_CASE("Оператор != vector") {
//    Vector v1(3, 15.0);
//    Vector v2(3, 4.0);
//    v1 /= 3;
//    REQUIRE(v1 != v2);
//}

TEST_CASE("Оператор +") {
    Matrix m1(3, 15.0);
    Matrix m2(3, 4.0);
    Matrix m3(3, 19.0);
    REQUIRE(m3 == m1 + m2);
}

TEST_CASE("Оператор + vector") {
    Vector v1(3, 15.0);
    Vector v2(3, 4.0);
    Vector v3(3, 19.0);
    REQUIRE(v3 == v1 + v2);
}

TEST_CASE("Оператор -") {
    Matrix m1(3, 15.0);
    Matrix m2(3, 4.0);
    Matrix m3(3, 11.0);
    REQUIRE(m3 == m1 - m2);
}

TEST_CASE("Оператор - vector") {
    Vector v1(3, 15.0);
    Vector v2(3, 4.0);
    Vector v3(3, 11.0);
    REQUIRE(v3 == v1 - v2);
}

TEST_CASE("Оператор *") {
    Matrix m1(3, 15.0);
    Matrix m3(3, 60.0);
    REQUIRE(m3 == m1 * 4);
}

TEST_CASE("Оператор * vector") {
    Vector v1(3, 15.0);
    Vector v3(3, 60.0);
    REQUIRE(v3 == v1 * 4);
}

TEST_CASE("Оператор /") {
    Matrix m1(3, 20.0);
    Matrix m2(3, 4.0);
    REQUIRE(m2 == m1 / 5);
}

TEST_CASE("Оператор / vector") {
    Vector v1(3, 20.0);
    Vector v2(3, 4.0);
    Vector v3(v2);
    REQUIRE(v3 == v1 / 5);
}

TEST_CASE("Умножение матриц") {
    Matrix m1(3, 1.0);
    Matrix m2(3, 2.0);
    Matrix m3(3, 6.0);
    REQUIRE(m2 * m1 == m3);
}

TEST_CASE("Умножение матриц *=") {
    Matrix m1(3, 1.0);
    Matrix m2(3, 2.0);
    Matrix m3(3, 6.0);
    m2 *= m1;
    REQUIRE(m2.get(1, 1) == m3.get(1, 1));
}

TEST_CASE("Умножение матрицы на вектор") {
    Matrix m(3, 1.0);
    Vector v(3, 3.0);
    Vector res(3, 9.0);
    REQUIRE(res == m * v);
}

TEST_CASE("Транспонирование матрицы") {
    Matrix m1(3, 4, 20.0);
    Matrix m2(4, 3, 20.0);
    m1.transpose();
    REQUIRE(m2 == m1);
}

TEST_CASE("Оператор reshape") {
    Matrix m1(4, 5, 20.0);
    Matrix m2(10, 2, 20.0);
    m1.reshape(10, 2);
    REQUIRE(m2 == m1);
}

TEST_CASE("Оператор transposed") {
    Matrix m1(3, 4, 20.0);
    Matrix m2(4, 3, 20.0);
    Matrix m3(4, 3, 0.0);
    m3 = m1.transposed();
    REQUIRE(m2 == m3);
}

TEST_CASE("Оператор eye") {
    Matrix m1(4, 20.0);
    m1 = m1.eye(4);
    bool res = true;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if ((i == j) && (m1.get(i, j) != 1)) {
                res = false;
            }
            if ((i != j) && (m1.get(i, j) != 0)) {
                res = false;
            }
        }
    }
    REQUIRE(res == true);
}

TEST_CASE("Оператор det") {
    Matrix m1(4, 20.0);
    double res = m1.det();
    REQUIRE(res == 0);
}

TEST_CASE("Vector normalize") {
    Vector v1(4, 5.0);
    Vector v2(4, 0.5);
    v1.normalize();
    REQUIRE(v1 == v2);
}

TEST_CASE("Vector normalized") {
    Vector v1(4, 5.0);
    Vector v2(4, 0.5);
    Vector v3(4, 0.0);
    v3 = v1.normalized();
    REQUIRE(v3 == v2);
}

TEST_CASE("Vector sqrt") {
    Vector v1(4, 3.0);
    Vector v2(4, 18.0);
    Vector v3(4, 6.0);
    REQUIRE(v2 == (v1 ^ v3));
}

TEST_CASE("Скалярное произведение") {
    Vector v1(3, 3.0);
    Vector v2(3, 4.0);
    REQUIRE(36 == v1 * v2);
}

TEST_CASE("L2 norm") {
    Vector v1(4, 4.0);
    REQUIRE(v1.norm() == 8);
}

TEST_CASE("Vector * matrix") {
    Vector v1(4, 2.0);
    Matrix m1(4, 3, 3.0);
    Vector v2(3, 24.0);
    REQUIRE(v2 == v1 * m1);
}

TEST_CASE("&Vector * matrix") {
    Vector v1(4, 2.0);
    Matrix m1(4, 3, 3.0);
    Vector v2(3, 24.0);
    Vector v3(3, 0.0);
    v1 *= m1;
    REQUIRE(v2 == v1);
}

TEST_CASE("Det") {
    Matrix m1(4, 15.0);
    double res = m1.det();
    REQUIRE(res == 0);
}

TEST_CASE("Inv") {
    Matrix m1(2, 0.0);
    m1.get(0, 0) = 1;
    m1.get(0, 1) = 2;
    m1.get(1, 0) = 3;
    m1.get(1, 1) = 4;
    Matrix m2(2, 0.0);
    m2.get(0, 0) = -2;
    m2.get(0, 1) = 1;
    m2.get(1, 0) = 1.5;
    m2.get(1, 1) = -0.5;
    REQUIRE(m1.inv() == m2);
}