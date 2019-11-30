#include "Base.h"
#include "Matrix.h"
#include "Vector.h"
#include <cmath>

using namespace mat_vec;

Matrix::Matrix(size_t size, double value):rows_(size), columns(size) {
    allocation();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            nums[i][j] = value;
        }
    }
}

Matrix::Matrix(size_t rows, size_t cols, double value) {
    rows_ = rows;
    columns = cols;
    allocation();
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            nums[i][j] = value;
        }
    }
}

Matrix::Matrix(const Matrix &src) {
    rows_ = src.rows_;
    columns = src.columns;
    allocation();
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < columns; j++) {
            nums[i][j] = src.nums[i][j];
        }
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < rows_; i++) {
        delete[] nums[i];
    }
    columns = 0;
    rows_ = 0;
    delete[] nums;
}

Matrix &Matrix::operator=(const Matrix &rhs) {
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < columns; j++) {
            nums[i][j] = rhs.nums[i][j];
        }
    }
    return *this;
}

Matrix Matrix::eye(size_t size) {
    Matrix m(size, 0);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j) {
                m.nums[i][j] = 1;
            } else {
                m.nums[i][j] = 0;
            }
        }
    }
    return m;
}

void Matrix::allocation() {
    nums = new double *[rows_];
    for (int i = 0; i < rows_; i++) {
        nums[i] = new double[columns];
    }
}

std::pair<size_t, size_t> Matrix::shape() const { return {rows_, columns}; }

double Matrix::get(size_t row, size_t col) const { return nums[row][col]; }

Matrix &Matrix::operator+=(const Matrix &rhs) {
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < columns; j++) {
            nums[i][j] += rhs.nums[i][j];
        }
    }
    return *this;
}

Matrix &Matrix::operator-=(const Matrix &rhs) {
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < columns; j++) {
            nums[i][j] -= rhs.nums[i][j];
        }
    }
    return *this;
}

Matrix &Matrix::operator*=(double k) {
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < columns; j++) {
            nums[i][j] *= k;
        }
    }
    return *this;
}

Matrix &Matrix::operator/=(double k) {
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < columns; j++) {
            nums[i][j] /= k;
        }
    }
    return *this;
}

bool Matrix::operator==(const Matrix &rhs) const {
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < columns; j++) {
            if (std::abs(nums[i][j] - rhs.nums[i][j]) > eps) {
                return false;
            }
        }
    }
    return true;
}

bool Matrix::operator!=(const Matrix &rhs) const {
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < columns; j++) {
            if (std::abs(nums[i][j] - rhs.nums[i][j]) > eps) {
                return true;
            }
        }
    }
    return false;
}

Matrix Matrix::operator+(const Matrix &rhs) const {
    Matrix m(rows_, columns, 0);
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < columns; j++) {
            m.nums[i][j] = nums[i][j] + rhs.nums[i][j];
        }
    }
    return m;
}

Matrix Matrix::operator-(const Matrix &rhs) const {
    Matrix m(rows_, columns, 0);
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < columns; j++) {
            m.nums[i][j] = nums[i][j] - rhs.nums[i][j];
        }
    }
    return m;
}

Matrix Matrix::operator*(double k) const {
    Matrix m(rows_, columns, 0);
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < columns; j++) {
            m.nums[i][j] = nums[i][j] * k;
        }
    }
    return m;
}

Matrix Matrix::operator/(double k) const {
    Matrix m(rows_, columns, 0);
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < columns; j++) {
            m.nums[i][j] = nums[i][j] / k;
        }
    }
    return m;
}

Matrix Matrix::transposed() const {
    Matrix m(columns, rows_, 0);
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows_; j++) {
            m.nums[i][j] = nums[j][i];
        }
    }
    return m;
}

double &Matrix::get(size_t row, size_t col) { return nums[row][col]; }

void Matrix::reshape(size_t rows, size_t cols) {
    Matrix m(1, rows_ * columns, 0);
    int elem = -1;
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < columns; j++) {
            elem++;
            m.nums[0][elem] = nums[i][j];
        }
    }

    for (int i = 0; i < rows_; i++) {
        delete[] nums[i];
    }
    delete[] nums;

    rows_ = rows;
    columns = cols;
    allocation();

    elem = -1;
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < columns; j++) {
            elem++;
            nums[i][j] = m.nums[0][elem];
        }
    }
}

void Matrix::transpose() {
    Matrix m(columns, rows_, 0);
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows_; j++) {
            m.nums[i][j] = nums[j][i];
        }
    }

    for (int i = 0; i < rows_; i++) {
        delete[] nums[i];
    }
    delete[] nums;

    size_t a = rows_;
    rows_ = columns;
    columns = a;
    allocation();
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < columns; j++) {
            nums[i][j] = m.nums[i][j];
        }
    }
}

Matrix &Matrix::operator*=(const Matrix &rhs) {
    Matrix m(rows_, rhs.columns, 0);
    for (int i = 0; i < rows_; i++) {
        for (int k = 0; k < columns; k++) {
            for (int j = 0; j < rhs.columns; j++) {
                m.nums[i][k] += nums[i][k] * rhs.nums[j][k];
            }
        }
    }
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < columns; j++) {
            nums[i][j] = m.nums[i][j];
        }
    }
    return *this;
}

Matrix Matrix::operator*(const Matrix &rhs) const {
    Matrix m(rows_, rhs.columns, 0);
    for (int i = 0; i < rows_; i++) {
        for (int k = 0; k < columns; k++) {
            for (int j = 0; j < rhs.columns; j++) {
                m.nums[i][k] += nums[i][k] * rhs.nums[j][k];
            }
        }
    }
    return m;
}

Vector Matrix::operator*(const Vector &vec) const {
    Vector v(columns, 0);
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < columns; j++) {
            v[(i)] += nums[i][j] * vec[(j)];
        }
    }
    return v;
}

double Matrix::det() const { return getDet(nums, rows_); }

double Matrix::getDet(double **a, size_t size) const {
    double d = 0;
    if (size == 1) return a[0][0];
    double sign = 1;
    double **temp;
    temp = new double *[size];
    for (int i = 0; i < size; ++i) {
        temp[i] = new double[size];
    }
    for (int y = 0; y < size; y++) {
        getMinor(size, a, temp, 0, y);
        d += sign * a[0][y] * getDet(temp, size - 1);
        sign = -sign;
    }
    for (int i = 0; i < size; ++i) {
        delete[] temp[i];
    }
    delete[] temp;
    return d;
}

void Matrix::getMinor(size_t size, double **c, double **minor_, int this_row,
                      int this_col) const {
    int i = 0, j = 0;
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            if (row != this_row && col != this_col) {
                minor_[i][j++] = c[row][col];
                if (j == size - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

Matrix Matrix::inv() const {
    Matrix inverse(rows_, 0);
    double det_ = getDet(nums, rows_);
    if (rows_ == 1) {
        inverse.nums[0][0] = 1 / det_;
        return inverse;
    }
    int sign = 1;
    double **minor__;
    minor__ = new double *[rows_];
    for (int i = 0; i < rows_; ++i) {
        minor__[i] = new double[rows_];
    }
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < rows_; j++) {
            getMinor(rows_, nums, minor__, i, j);
            sign = ((i + j) % 2 == 0) ? 1 : -1;
            inverse.nums[j][i] = sign * (getDet(minor__, rows_ - 1)) / det_;
        }
    }
    for (int i = 0; i < rows_; ++i) {
        delete[] minor__[i];
    }
    delete[] minor__;
    return inverse;
}
