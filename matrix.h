#ifndef INC_1_1_MATRIX_MATRIX_H
#define INC_1_1_MATRIX_MATRIX_H
#include<iostream>
#include<fstream>
using namespace std;

class matrix {
    int size;
    int **elem;
    void create();
    void set_zero();
    void erase();
    void read(std::ifstream &fin);
public:
    matrix(const int size, std::ifstream &fin);
    matrix(const int size);
    matrix(const int size, const int k);
    matrix(const matrix &copy);
    ~matrix();
    matrix transpose();
    void print(std::ofstream &fout);
    matrix operator+(const matrix & A);
    matrix operator()(int n, int k);
    bool operator==(const matrix& A);
    matrix operator*(const matrix & A);
    matrix & operator=(const matrix & A);
};


#endif //INC_1_1_MATRIX_MATRIX_H
