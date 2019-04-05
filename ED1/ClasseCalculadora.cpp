#include "ClasseCalculadora.h"

Calculator::Calculator(unsigned n)
{
  setVectorDimension(n);
};

std::vector<float> currentResult;

unsigned Calculator::getVectorDimension()
{
  return vectorDimension;
}

bool Calculator::setVectorDimension(unsigned n)
{
  if (n > 0)
  {
    /*Nao altero se for igual, pois eh redundancia*/
    if (vectorDimension != n) {
      /*Valor do resultado atual eh resetado, pois a dimensao foi alterada*/
      currentResult = {};
      vectorDimension = n;
    }
    return true;
  }
  return false;
}

std::vector<float> Calculator::getMemory()
{
  return memory;
}

bool Calculator::setMemory(std::vector<float> vector)
{
  if (vector.size() > 0)
  {
    memory = vector;
    return true;
  }
  return false;
}

std::vector<float> Calculator::sumVectors(std::vector<float> v1, std::vector<float> v2)
{

  unsigned counter = 0;
  std::vector<float> result;
  while (counter < v1.size())
  {
    result.push_back(v1.at(counter) + v2.at(counter));
    counter++;
  }
  currentResult = result;
  return result;
};

std::vector<float> Calculator::scaleVector(std::vector<float> vector, float multiplier)
{
  unsigned counter = 0;
  while (counter < vector.size())
  {
    vector.at(counter) *= multiplier;
    counter++;
  }
  currentResult = vector;
  return vector;
};

std::vector<float> Calculator::calculateLinearCombination(std::vector<float> v1, std::vector<float> v2, float alpha, float beta)
{
  unsigned counter = 0;
  std::vector<float> result;
  while (counter < v1.size())
  {
    result.push_back(v1.at(counter) * alpha + v2.at(counter) * beta);
    counter++;
  }
  currentResult = result;
  return result;
};

float Calculator::calculateInnerProduct(std::vector<float> v1, std::vector<float> v2)
{
  unsigned counter = 0;
  int result = 0;
  while (counter < v1.size())
  {
    result += v1.at(counter) * v2.at(counter);
    counter++;
  }
  return result;
};

float Calculator::calculateVectorNorm(std::vector<float> vector)
{
  unsigned counter = 0;
  float norm = 0;
  while (counter < vector.size())
  {
    norm += pow(vector.at(counter), 2);
    counter++;
  }
  return sqrt(norm);
};

float Calculator::calculateDistance(std::vector<float> v1, std::vector<float> v2)
{
  unsigned counter = 0;
  float distance = 0;
  while (counter < v1.size())
  {
    distance += pow((v1.at(counter) - v2.at(counter)), 2);
    counter++;
  }
  return sqrt(distance);
};

float Calculator::calculateAngle(std::vector<float> v1, std::vector<float> v2)
{
  int innerProduct = calculateInnerProduct(v1, v2);
  float v1Norm = calculateVectorNorm(v1);
  float v2Norm = calculateVectorNorm(v2);

  return acos(innerProduct / (v1Norm * v2Norm));
};
