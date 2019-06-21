/* ---------------------------------------
  Fabiana Ferreira Fonseca
  Universidade Federal do Rio de Janeiro
  DRE: 115037241
----------------------------------------*/

#include "SquareMatrix.h"

SquareMatrix::SquareMatrix(unsigned _lines, unsigned _columns, TypeMatrix _m) : Matrix(_lines, _columns, _m){};

SquareMatrix::SquareMatrix(const SquareMatrix &matrix) : Matrix(matrix.lines, matrix.columns, matrix.m){};

SquareMatrix &SquareMatrix::operator=(const SquareMatrix &matrix)
{
  lines = matrix.lines;
  columns = matrix.columns;
  m = matrix.m;
  return *this;
}

void SquareMatrix::print()
{
  std::cout << "Sou quadrada!!" << std::endl;
}

float SquareMatrix::calculateTrace()
{
  float result = 0;
  for (unsigned i = 0; i < lines; i++)
  {
    result += m.at(i).at(i);
  }

  return result;
}