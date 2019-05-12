/* ---------------------------------------
  Fabiana Ferreira Fonseca
  Universidade Federal do Rio de Janeiro
  DRE: 115037241
----------------------------------------*/

#include <sstream>
#include <vector>
#include <iostream>
#include <string.h>
#include <math.h>

#ifndef types_h
  typedef std::vector<std::vector<float>> Matrix;
#endif

class Calculator
{

public:
  Calculator();

  Matrix currentResult;

  static std::vector<unsigned> getMatrixDimension(Matrix);

  Matrix sumOrSubMatrices(Matrix, Matrix, unsigned);

  Matrix scaleMatrix(Matrix, float);

  Matrix multiplyMatrices(Matrix, Matrix, unsigned, unsigned);

  Matrix transposeMatrix(Matrix, unsigned, unsigned);

  Matrix swapLinesOrColumns(Matrix, unsigned, unsigned, unsigned);

  Matrix sumLinesOrColumns(Matrix, unsigned, unsigned, unsigned);

  Matrix multiplyLineOrColumn(Matrix, unsigned, unsigned, float);

  Matrix twoDimensionInverse(Matrix);

  void gaussElimination(Matrix &);

  Matrix generalInverter(Matrix);

  std::vector<float> solveEquation(Matrix &);

  Matrix calculateLinearCombination(Matrix, Matrix, float, float);
};
