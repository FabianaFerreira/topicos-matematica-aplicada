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

class Calculator
{

public:
  Calculator();

  std::vector<std::vector<float>> currentResult;

  static std::vector<unsigned> getMatrixDimension(std::vector<std::vector<float>>);

  std::vector<std::vector<float>> sumOrSubVectors(std::vector<std::vector<float>>, std::vector<std::vector<float>>, unsigned);

  std::vector<std::vector<float>> scaleMatrix(std::vector<std::vector<float>>, float);

  std::vector<std::vector<float>> multiplyMatrices(std::vector<std::vector<float>>, std::vector<std::vector<float>>);
  
  std::vector<std::vector<float>> transposeMatrix(std::vector<std::vector<float>>);

  std::vector<std::vector<float>> calculateLinearCombination(std::vector<std::vector<float>>, std::vector<std::vector<float>>, float, float);

};
