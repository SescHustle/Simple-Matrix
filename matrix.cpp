#include "matrix.h"

//constructors and destructor
matrix::matrix(const int size) : size(size){
    this->create();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            this->elem[i][j] = rand() % 10;
        }
    }
}

matrix::matrix(const matrix &copy) : size(copy.size){
    this->create();
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            this->elem[i][j] = copy.elem[i][j];
        }
    }
}

matrix::matrix(const int size, std::ifstream &fin) : size(size){
    this->create();
    this->read(fin);
}

matrix::matrix(const int size, const int k) : size(size){
    this->create();
    this->set_zero();
    for (int i = 0, j = 0; i < size; i++, j++) {
        this->elem[i][j] = k;
    }
}

matrix::~matrix() {
    this->erase();
}

//class methods
void matrix::create() {
    this->elem = new int* [size];
    for (int i = 0; i < this->size; i++) {
        this->elem[i] = new int[size];
    }
}

void matrix::set_zero() {
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            this->elem[i][j] = 0;
        }
    }
}

void matrix::erase() {
    for (int i = 0; i < this->size; i++) {
        delete[] this->elem[i];
    }
    delete[] this->elem;
}

void matrix::read(std::ifstream &fin) {
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            fin >> this->elem[i][j];
        }
    }
}

void matrix::print(std::ofstream &fout) {
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            fout << this->elem[i][j] << " ";
        }
        fout << "\n";
    }
}

matrix matrix::transpose() {
    matrix tmp(*this);
    this->set_zero();
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            this->elem[i][j] = tmp.elem[j][i];
        }
    }
    return *this;
}

//operators overloads
matrix matrix::operator+(const matrix & A) {
    if (this->size != A.size) {
        cout << "error";
        return 0;
    }
    matrix result(this->size, 0);
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            result.elem[i][j] = this->elem[i][j] + A.elem[i][j];
        }
    }
    return result;
}

matrix matrix::operator()(int n, int k) {
    matrix result(this->size-1, 0);
    int t = 0;
    for (int i = 0; i < this->size; i++) {
        if (i == n) {
            t = 1;
            continue;
        }
        for (int j = 0; j < this->size; j++) {
            if (j == k) continue;
            if (j > k ) result.elem[i][j] = this->elem[i-t][j-1];
            result.elem[i][j] = this->elem[i-t][j];
        }
    }
    return result;
}

bool matrix::operator==(const matrix& A) {
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            if (this->elem[i][j] != A.elem[i][j]) return false;
        }
    }
    return true;
}

matrix matrix::operator*(const matrix & A){
    matrix result(this->size, 0);
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            for (int k = 0; k < this->size; k++) {
                result.elem[i][j] += this->elem[i][k] * A.elem[k][j];
            }
        }
    }
    return result;
}

matrix & matrix::operator=(const matrix & A) {
    this->erase();
    this->size = A.size;
    this->create();
    for (int i = 0; i < this->size; i++) {
        for (int j = 0; j < this->size; j++) {
            this->elem[i][j] = A.elem[i][j];
        }
    }
    return *this;
}



