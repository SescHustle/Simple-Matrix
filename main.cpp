#include <fstream>
#include "matrix.h"

int main() {
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    int n = 0;
    int k = 0;
    fin >> n;
    fin >> k;
    matrix A(n, fin);
    matrix B(n, fin);
    matrix C(n, fin);
    matrix D(n, fin);
    matrix K(n, k);
    matrix R = (A + (B*C.transpose()) + K) * D.transpose();
    R.print(fout);
    fout.close();
    return 0;
}
