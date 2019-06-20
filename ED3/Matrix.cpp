/* ---------------------------------------
  Fabiana Ferreira Fonseca
  Universidade Federal do Rio de Janeiro
  DRE: 115037241
----------------------------------------*/

#include "Matrix.h"
#include "functions.h"

Matrix::Matrix() {}

Matrix::Matrix(unsigned _lines, unsigned _columns, TypeMatrix _m) : lines(_lines), columns(_columns), m(_m)
{
  std::cout << "Construtor Geral" << std::endl;
}

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

unsigned Matrix::getLines()
{
  return lines;
}

unsigned Matrix::getColumns()
{
  return columns;
}

TypeMatrix Matrix::getMatrix()
{
  return m;
}

void Matrix::setMatrix(TypeMatrix newMatrix)
{
  //posso fazer isso?
  m = newMatrix;
}

// void print()
// {
//   std::cout << "Sou Geral" << std::endl;
// }

// std::vector<unsigned> Matrix::getMatrixDimension(TypeMatrix m)
// {
//   std::vector<unsigned> result;
//   result.push_back(m.size());

//   //Checking if it's possible to get first position of matrix
//   if (m.size() != 0)
//     result.push_back(m.at(0).size());
//   else
//     result.push_back(0);

//   return result;
// }

// bool Matrix::checkIfDimensionsAreEqual(MatrixList list, std::vector<std::string> identifiers)
// {
//   char firstIdentifier = identifiers.at(0).c_str()[0];
//   std::vector<unsigned> firstDimension(getMatrixDimension(list.get(firstIdentifier)));

//   for (unsigned i = 1; i < identifiers.size(); i++)
//   {
//     char ident = identifiers.at(i).c_str()[0];
//     TypeMatrix current(list.get(ident));
//     std::vector<unsigned> currentDimension(getMatrixDimension(list.get(i)));
//     if (firstDimension != currentDimension)
//       return false;
//   }
//   return true;
// }

// OVERLOADED OPERATOR *
// Matrix Matrix::operator+(Matrix matrix)
// {
//   TypeMatrix result(m);
//   TypeMatrix m2 = matrix.getMatrix();
//   for (unsigned i = 0; i < lines; i++)
//   {
//     for (unsigned j = 0; j < columns; j++)
//     {
//       result.at(i).at(j) = m.at(i).at(j) + (m2.at(i).at(j));
//     }
//   }

//   return Matrix(lines, matrix.getColumns(), result);
// }

// //OVERLOADED OPERATOR *
// Matrix Matrix::operator-(Matrix matrix)
// {
//   TypeMatrix result(m);
//   TypeMatrix m2 = matrix.getMatrix();
//   for (unsigned i = 0; i < lines; i++)
//   {
//     for (unsigned j = 0; j < columns; j++)
//     {
//       result.at(i).at(j) = m.at(i).at(j) - (m2.at(i).at(j));
//     }
//   }

//   return Matrix(lines, matrix.getColumns(), result);
// }

// //OVERLOADED OPERATOR *
// Matrix Matrix::operator*(Matrix matrix)
// {
//   TypeMatrix result;
//   //Creating m1Lines x m2Columns matrix and inserting zeros
//   for (unsigned i = 0; i < lines; i++)
//   {
//     result.push_back(std::vector<float>(matrix.getColumns(), 0));
//   }

//   for (unsigned i = 0; i < lines; i++)
//   {
//     for (unsigned j = 0; j < matrix.getColumns(); j++)
//     {
//       for (unsigned k = 0; k < m.at(i).size(); k++)
//       {
//         result.at(i).at(j) += m.at(i).at(k) * matrix.getMatrix().at(k).at(j);
//       }
//     }
//   }
//   return Matrix(lines, matrix.getColumns(), result);
// }

// Matrix Matrix::operator*(unsigned scalar)
// {
//   TypeMatrix result(m);
//   for (unsigned i = 0; i < lines; i++)
//   {
//     for (unsigned j = 0; j < columns; j++)
//       result.at(i).at(j) = m.at(i).at(j) * scalar;
//   }
//   return Matrix(lines, columns, result);
// }

Matrix Matrix::transposeMatrix()
{
  TypeMatrix result;
  //Creating columns x linhes matrix and inserting zeros
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
  return Matrix(lines, columns, result);
}