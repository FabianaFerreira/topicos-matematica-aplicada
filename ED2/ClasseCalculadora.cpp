#include "ClasseCalculadora.h"
#include "functions.h"

Calculator::Calculator(){};

Matrix currentResult;

std::vector<unsigned> Calculator::getMatrixDimension(Matrix m)
{
  std::vector<unsigned> result;
  result.push_back(m.size());

  //Checking if it's possible to get first position of matrix
  if (m.size() != 0)
    result.push_back(m.at(0).size());
  else
    result.push_back(0);

  return result;
}

Matrix Calculator::sumOrSubMatrices(Matrix m1, Matrix m2, unsigned isSub)
{
  Matrix result(m1);
  for (unsigned i = 0; i < m1.size(); i++)
  {
    for (unsigned j = 0; j < m1.at(i).size(); j++)
    {
      result.at(i).at(j) = m1.at(i).at(j) + (m2.at(i).at(j)) * pow(-1, isSub);
    }
  }
  currentResult = result;
  return result;
};

Matrix Calculator::scaleMatrix(Matrix matrix, float multiplier)
{
  Matrix result(matrix);
  for (unsigned i = 0; i < matrix.size(); i++)
  {
    for (unsigned j = 0; j < matrix.at(i).size(); j++)
      result.at(i).at(j) = matrix.at(i).at(j) * multiplier;
  }
  currentResult = result;
  return result;
};

Matrix Calculator::multiplyMatrices(Matrix m1, Matrix m2, unsigned m1Lines, unsigned m2Columns)
{
  Matrix result;
  //Creating m1Lines x m2Columns matrix and inserting zeros
  for (unsigned i = 0; i < m1Lines; i++)
  {
    result.push_back(std::vector<float>(m2Columns, 0));
  }

  for (unsigned i = 0; i < m1Lines; i++)
  {
    for (unsigned j = 0; j < m2Columns; j++)
    {
      for (unsigned k = 0; k < m1.at(i).size(); k++)
      {
        result.at(i).at(j) += m1.at(i).at(k) * m2.at(k).at(j);
      }
    }
  }
  currentResult = result;
  return result;
};

Matrix Calculator::transposeMatrix(Matrix matrix, unsigned lines, unsigned columns)
{
  Matrix result;
  //Creating columns x linhes matrix and inserting zeros
  for (unsigned i = 0; i < columns; i++)
  {
    result.push_back(std::vector<float>(lines, 0));
  }

  for (unsigned i = 0; i < matrix.size(); i++)
  {
    for (unsigned j = 0; j < matrix.at(i).size(); j++)
    {
      result.at(j).at(i) = matrix.at(i).at(j);
    }
  }
  currentResult = result;
  return result;
};

Matrix Calculator::swapLinesOrColumns(Matrix matrix, unsigned isLine, unsigned p1, unsigned p2)
{
  Matrix result(matrix);
  if (isLine == 1)
  {
    for (unsigned i = 0; i < matrix.at(p1 - 1).size(); i++)
    {
      unsigned tmp = matrix.at(p1 - 1).at(i);
      result.at(p1 - 1).at(i) = matrix.at(p2 - 1).at(i);
      result.at(p2 - 1).at(i) = tmp;
    }
  }
  else
  {
    for (unsigned i = 0; i < matrix.size(); i++)
    {
      unsigned tmp = matrix.at(i).at(p1 - 1);
      result.at(i).at(p1 - 1) = matrix.at(i).at(p2 - 1);
      result.at(i).at(p2 - 1) = tmp;
    }
  }

  currentResult = result;
  return result;
};

Matrix Calculator::sumLinesOrColumns(Matrix matrix, unsigned isLine, unsigned p1, unsigned p2)
{
  Matrix result(matrix);
  if (isLine)
  {
    for (unsigned i = 0; i < matrix.at(p1 - 1).size(); i++)
      result.at(p1 - 1).at(i) = matrix.at(p1 - 1).at(i) + matrix.at(p2 - 1).at(i);
  }
  else
  {
    for (unsigned i = 0; i < matrix.size(); i++)
      result.at(i).at(p1 - 1) = matrix.at(i).at(p1 - 1) + matrix.at(i).at(p2 - 1);
  }

  currentResult = result;
  return result;
};

Matrix Calculator::multiplyLineOrColumn(Matrix matrix, unsigned isLine, unsigned pos, float multiplier)
{
  Matrix result(matrix);
  if (isLine)
  {
    for (unsigned i = 0; i < matrix.at(pos - 1).size(); i++)
      result.at(pos - 1).at(i) = matrix.at(pos - 1).at(i) * multiplier;
  }
  else
  {
    for (unsigned i = 0; i < matrix.size(); i++)
      result.at(i).at(pos - 1) = matrix.at(i).at(pos - 1) * multiplier;
  }

  currentResult = result;
  return result;
};

// Receives a reference to a n x 2n block matrix [A | I] and finds the reduced form of this block (transforms A into an upper triangular)
void Calculator::gaussElimination(Matrix &m)
{
  int n = m.size();

  for (int i = 0; i < n; i++)
  {
    // Search for maximum in this column
    double maxEl = abs(m[i][i]);
    int maxRow = i;
    for (int k = i + 1; k < n; k++)
    {
      if (abs(m[k][i]) > maxEl)
      {
        maxEl = m[k][i];
        maxRow = k;
      }
    }

    // Swap maximum row with current row (column by column)
    for (int k = i; k < 2 * n; k++)
    {
      double tmp = m[maxRow][k];
      m[maxRow][k] = m[i][k];
      m[i][k] = tmp;
    }

    // Make all rows below this one 0 in current column
    for (int k = i + 1; k < n; k++)
    {
      double c = -m[k][i] / m[i][i];
      for (int j = i; j < 2 * n; j++)
      {
        if (i == j)
        {
          m[k][j] = 0;
        }
        else
        {
          m[k][j] += c * m[i][j];
        }
      }
    }
  }
}

// Uses Gauss Elimination to find the reduced form of the n x 2n block and solves Ax = b for an upper triangular matrix
Matrix Calculator::generalInverter(Matrix matrix)
{
  int n = matrix.size();
  Matrix result;

  copyMatrix(matrix, result, n);

  //Transforms to an upper triangular matrix
  gaussElimination(result);

  // Solve equation Ax=b for an upper triangular matrix A
  for (int i = n - 1; i >= 0; i--)
  {
    for (int k = n; k < 2 * n; k++)
    {
      result[i][k] /= result[i][i];
    }
    // this is not necessary, but the output looks nicer:
    result[i][i] = 1;

    for (int rowModify = i - 1; rowModify >= 0; rowModify--)
    {
      for (int columModify = n; columModify < 2 * n; columModify++)
      {
        result[rowModify][columModify] -= result[i][columModify] * result[rowModify][i];
      }
      // this is not necessary, but the output looks nicer:
      result[rowModify][i] = 0;
    }
  }

  return result;
}

std::vector<float> Calculator::solveEquation(Matrix &m)
{
  //Transforms to an upper triangular matrix
  gaussElimination(m);

  int n = m.size();

  // Solve equation Ax=b for an upper triangular matrix A
  std::vector<float> x(n);
  for (int i = n - 1; i >= 0; i--)
  {
    x[i] = m[i][n] / m[i][i];
    for (int k = i - 1; k >= 0; k--)
    {
      m[k][n] -= m[k][i] * x[i];
    }
  }
  return x;
}