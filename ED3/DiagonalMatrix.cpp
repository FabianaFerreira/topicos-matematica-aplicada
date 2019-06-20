/* ---------------------------------------
  Fabiana Ferreira Fonseca
  Universidade Federal do Rio de Janeiro
  DRE: 115037241
----------------------------------------*/

#include "DiagonalMatrix.h"

DiagonalMatrix::DiagonalMatrix(unsigned _lines, unsigned _columns, TypeMatrix _m) : Matrix(_lines, _columns, _m){};

DiagonalMatrix::DiagonalMatrix(const DiagonalMatrix &matrix) : Matrix(matrix.lines, matrix.columns, matrix.m) {}

DiagonalMatrix &DiagonalMatrix::operator=(const DiagonalMatrix &matrix)
{
    lines = matrix.lines;
    columns = matrix.columns;
    m = matrix.m;
    return *this;
}

void DiagonalMatrix::print()
{
    std::cout << "Sou diagonal!!" << std::endl;
}