#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
typedef void(*func)(int **arr, int size);

class matrix{
    int **array;
    func FillMatrix;
    int size;
    matrix(const matrix&);
public:
    matrix(int size,func funFill);
    matrix(int size);
    void print();
    int getSize();
    ~matrix();
    double getDet();
    matrix operator*(const int val);
    matrix operator=(const matrix& matr);
    matrix operator +(const matrix& matr);
    matrix operator -(const matrix& matr);
    void operator +=(const matrix& matr);
    void operator -=(const matrix& matr);
    matrix operator*(const matrix& matr);
    void operator*=(const matrix& matr);
    void operator*=(const int val); 
    static matrix getIdentity(int size);
    static void IdentityFunc(int **arr, int size);
    friend  std::ostream& operator<<(std::ostream& ostr, matrix& matr);
};
#endif
