/* ---------------------------------------
  Fabiana Ferreira Fonseca
  Universidade Federal do Rio de Janeiro
  DRE: 115037241
----------------------------------------*/

#include "DiagonalMatrix.h"

DiagonalMatrix::DiagonalMatrix(unsigned _lines, unsigned _columns, TypeMatrix _m) : Matrix(_lines, _columns, _m)
{
  std::cout << "Construtor diagonal" << std::endl;
};

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

// Matrix *DiagonalMatrix::operator+(DiagonalMatrix matrix)
// {
//   TypeMatrix result;
//   TypeMatrix m2 = matrix.getMatrix();

//   std::cout << "SOMA DIAGONAL" << std::endl;
//   //Creating m1Lines x m2Columns matrix and inserting zeros
//   for (unsigned i = 0; i < lines; i++)
//   {
//     result.push_back(std::vector<float>(columns, 0));
//   }

//   for (unsigned i = 0; i < lines; i++)
//   {
//     result.at(i).at(i) = m.at(i).at(i) + m2.at(i).at(i);
//   }
//   return new DiagonalMatrix(lines, columns, result);
// }

DiagonalMatrix DiagonalMatrix::operator-(DiagonalMatrix matrix)
{
  TypeMatrix result;
  std::cout << "SUBTRACAO DIAGONAL" << std::endl;
  //Creating m1Lines x m2Columns matrix and inserting zeros
  for (unsigned i = 0; i < lines; i++)
  {
    result.push_back(std::vector<float>(columns, 0));
  }

  for (unsigned i = 0; i < lines; i++)
  {
    result.at(i).at(i) = m.at(i).at(i) - matrix.getMatrix().at(i).at(i);
  }
  return DiagonalMatrix(lines, columns, result);
}

//OVERLOADED OPERATOR *
DiagonalMatrix DiagonalMatrix::operator*(DiagonalMatrix matrix)
{
  TypeMatrix result;
  std::cout << "MULTIPLICACAO DIAGONAL" << std::endl;
  //Creating m1Lines x m2Columns matrix and inserting zeros
  for (unsigned i = 0; i < lines; i++)
  {
    result.push_back(std::vector<float>(matrix.getColumns(), 0));
  }

  for (unsigned i = 0; i < lines; i++)
  {
    result.at(i).at(i) = m.at(i).at(i) * matrix.getMatrix().at(i).at(i);
  }
  return DiagonalMatrix(lines, matrix.getColumns(), result);
}

//OVERLOADED OPERATOR *
Matrix DiagonalMatrix::operator*(float scalar)
{
  TypeMatrix result;
  std::cout << "MULTIPLICACAO ESCALAR DIAGONAL" << std::endl;
  //Creating m1Lines x m2Columns matrix and inserting zeros
  for (unsigned i = 0; i < lines; i++)
  {
    result.push_back(std::vector<float>(columns, 0));
  }

  for (unsigned i = 0; i < lines; i++)
  {
    result.at(i).at(i) = m.at(i).at(i) * scalar;
  }
  return DiagonalMatrix(lines, columns, result);
}