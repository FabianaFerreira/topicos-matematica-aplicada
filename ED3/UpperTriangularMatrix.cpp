/* ---------------------------------------
  Fabiana Ferreira Fonseca
  Universidade Federal do Rio de Janeiro
  DRE: 115037241
----------------------------------------*/

#include "UpperTriangularMatrix.h"

UpperTriangularMatrix::UpperTriangularMatrix(unsigned _lines, unsigned _columns, TypeMatrix _m) : SquareMatrix(_lines, _columns, _m)
{
    std::cout << "Construtor Triangular Superior" << std::endl;
}

UpperTriangularMatrix::UpperTriangularMatrix(const UpperTriangularMatrix &matrix) : SquareMatrix(matrix.lines, matrix.columns, matrix.m) {}

UpperTriangularMatrix &UpperTriangularMatrix::operator=(const UpperTriangularMatrix &matrix)
{
    lines = matrix.lines;
    columns = matrix.columns;
    m = matrix.m;
    return *this;
}

void UpperTriangularMatrix::print()
{
    std::cout << "Sou triangular superior!!" << std::endl;
}