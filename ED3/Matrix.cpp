/* ---------------------------------------
  Fabiana Ferreira Fonseca
  Universidade Federal do Rio de Janeiro
  DRE: 115037241
----------------------------------------*/

#include "Matrix.h"
#include "functions.h"

Matrix::Matrix() {}

Matrix::Matrix(unsigned _lines, unsigned _columns, TypeMatrix _m) : lines(_lines), columns(_columns), m(_m) {}

Matrix::Matrix(const Matrix &matrix)
{
  lines = matrix.lines;
  columns = matrix.columns;
  m = matrix.m;
}

Matrix::~Matrix() {}

// Matrix &Matrix::operator=(const Matrix &matrix)
// {
//   lines = matrix.lines;
//   columns = matrix.columns;
//   m = matrix.m;
//   return *this;
// }

unsigned Matrix::getLines() const
{
  return lines;
}

unsigned Matrix::getColumns() const
{
  return columns;
}

TypeMatrix Matrix::getMatrix() const
{
  return m;
}

void Matrix::setMatrix(TypeMatrix newMatrix)
{
  //posso fazer isso?
  m = newMatrix;
}

void Matrix::transpose()
{
  TypeMatrix result;
  for (unsigned i = 0; i < columns; i++)
  {
    result.push_back(std::vector<float>(lines, 0));
  }

  for (unsigned i = 0; i < lines; i++)
  {
    for (unsigned j = 0; j < m.at(i).size(); j++)
    {
      result.at(j).at(i) = m.at(i).at(j);
    }
  }
  setMatrix(result);
}