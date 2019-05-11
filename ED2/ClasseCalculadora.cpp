#include "ClasseCalculadora.h"

// Calculator::Calculator(unsigned n)
// {
//   setVectorDimension(n);
// };

std::vector<std::vector<float>> currentResult;

std::vector<unsigned> getMatrixDimension(std::vector<std::vector<float>> m)
{
  std::vector<unsigned> result;
  result.at(0) = m.size();

  //Checking if it's possible to get first position of matrix
  if (m.size() != 0)
    result.at(1) = m.at(0).size(); 
  else
    result.at(1) = 0;

  return result;
}

std::vector<std::vector<float>> Calculator::sumOrSubVectors(std::vector<std::vector<float>> m1, std::vector<std::vector<float>> m2, unsigned isSub)
{

  std::vector<std::vector<float>> result;
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

std::vector<std::vector<float>> Calculator::scaleMatrix(std::vector<std::vector<float>> matrix, float multiplier)
{
  std::vector<std::vector<float>> result;
  for (unsigned i = 0; i < matrix.size(); i++)
  {
    for (unsigned j = 0; j < matrix.at(i).size(); j++)
    {
      result.at(i).at(j) = matrix.at(i).at(j) * multiplier;
    }
  }
  currentResult = result;
  return result;
};

std::vector<std::vector<float>> Calculator::multiplyMatrices(std::vector<std::vector<float>> m1, std::vector<std::vector<float>> m2)
{
  std::vector<std::vector<float>> result;
  for (unsigned i = 0; i < m1.size(); i++)
  {
    for (unsigned j = 0; j < m2.at(i).size(); j++)
    {
      for (unsigned k = 0; j < m1.at(i).size(); j++)
      {
        result.at(i).at(j) += m1.at(i).at(k) * m2.at(k).at(j);
      }
    }
  }
  currentResult = result;
  return result;
};

std::vector<std::vector<float>> Calculator::transposeMatrix(std::vector<std::vector<float>> matrix)
{
  std::vector<std::vector<float>> result;
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
