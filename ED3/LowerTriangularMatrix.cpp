#include "LowerTriangularMatrix.h"

LowerTriangularMatrix::LowerTriangularMatrix(unsigned _lines, unsigned _columns, TypeMatrix _m) : SquareMatrix(_lines, _columns, _m){};

LowerTriangularMatrix::LowerTriangularMatrix(const LowerTriangularMatrix &matrix) : SquareMatrix(matrix.lines, matrix.columns, matrix.m){};

LowerTriangularMatrix &LowerTriangularMatrix::operator=(const LowerTriangularMatrix &matrix)
{
    lines = matrix.lines;
    columns = matrix.columns;
    m = matrix.m;
    return *this;
}

void LowerTriangularMatrix::print()
{
    std::cout << "Sou triangular inferior!!" << std::endl;
}