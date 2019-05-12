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

typedef std::vector<std::vector<float>> Matrix;

class Calculator
{

public:
  Calculator();

  Matrix currentResult;

  static std::vector<unsigned> getMatrixDimension(Matrix);

  Matrix sumOrSubVectors(Matrix, Matrix, unsigned);

  Matrix scaleMatrix(Matrix, float);

  Matrix multiplyMatrices(Matrix, Matrix);

  Matrix transposeMatrix(Matrix);

  Matrix swapLinesOrColumns(Matrix, bool, unsigned, unsigned);

  Matrix sumLinesOrColumns(Matrix, bool, unsigned, unsigned);

  Matrix multiplyLineOrColumn(Matrix, bool, unsigned, float);

  Matrix twoDimensionInverse(Matrix);

  void gaussElimination(Matrix &);

  void generalInverter(Matrix &);

  std::vector<float> solveEquation(Matrix &);

  Matrix calculateLinearCombination(Matrix, Matrix, float, float);
};
