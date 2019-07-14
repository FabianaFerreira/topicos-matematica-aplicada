/* ---------------------------------------
  Fabiana Ferreira Fonseca
  Universidade Federal do Rio de Janeiro
  DRE: 115037241
----------------------------------------*/

#include "DiagonalMatrix.h"

DiagonalMatrix::DiagonalMatrix(unsigned _lines, unsigned _columns, TypeMatrix _m) : SquareMatrix(_lines, _columns, _m){};

DiagonalMatrix::DiagonalMatrix(const DiagonalMatrix &matrix) : SquareMatrix(matrix.lines, matrix.columns, matrix.m) {}

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

Matrix *DiagonalMatrix::operator+(const Matrix &matrix) const
{
  TypeMatrix result;

  const DiagonalMatrix *pointer = dynamic_cast<const DiagonalMatrix *>(&matrix);

  if (!pointer)
  {
    return Matrix::operator+(matrix);
  }

  DiagonalMatrix matrix2 = *pointer;

  TypeMatrix m2 = matrix2.getMatrix();

  for (unsigned i = 0; i < lines; i++)
  {
    result.push_back(std::vector<float>(columns, 0));
  }

  for (unsigned i = 0; i < lines; i++)
  {
    result.at(i).at(i) = m.at(i).at(i) + m2.at(i).at(i);
  }
  return new DiagonalMatrix(lines, columns, result);
}

Matrix *DiagonalMatrix::operator-(const Matrix &matrix) const
{
  TypeMatrix result;

  const DiagonalMatrix *pointer = dynamic_cast<const DiagonalMatrix *>(&matrix);

  if (!pointer)
  {
    return Matrix::operator-(matrix);
  }

  DiagonalMatrix matrix2 = *pointer;

  TypeMatrix m2 = matrix2.getMatrix();

  for (unsigned i = 0; i < lines; i++)
  {
    result.push_back(std::vector<float>(columns, 0));
  }

  for (unsigned i = 0; i < lines; i++)
  {
    result.at(i).at(i) = m.at(i).at(i) - matrix.getMatrix().at(i).at(i);
  }
  return new DiagonalMatrix(lines, columns, result);
}

//OVERLOADED OPERATOR *
Matrix *DiagonalMatrix::operator*(const Matrix &matrix) const
{
  TypeMatrix result;

  const DiagonalMatrix *pointer = dynamic_cast<const DiagonalMatrix *>(&matrix);

  if (!pointer)
  {
    return Matrix::operator-(matrix);
  }

  DiagonalMatrix matrix2 = *pointer;

  TypeMatrix m2 = matrix2.getMatrix();

  for (unsigned i = 0; i < lines; i++)
  {
    result.push_back(std::vector<float>(columns, 0));
  }

  for (unsigned i = 0; i < lines; i++)
  {
    result.at(i).at(i) = m.at(i).at(i) * m2.at(i).at(i);
  }
  return new DiagonalMatrix(lines, columns, result);
}

//OVERLOADED OPERATOR *
Matrix *DiagonalMatrix::operator*(float scalar) const
{
  TypeMatrix result;

  for (unsigned i = 0; i < lines; i++)
  {
    result.push_back(std::vector<float>(columns, 0));
  }

  for (unsigned i = 0; i < lines; i++)
  {
    result.at(i).at(i) = m.at(i).at(i) * scalar;
  }
  return new DiagonalMatrix(lines, columns, result);
}