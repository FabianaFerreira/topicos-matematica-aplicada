#include "ClasseCalculadora.h"


Calculator::Calculator(unsigned n) {
  setVectorDimension(n);
};

unsigned Calculator::getVectorDimension () {
  return vectorDimension;
}

bool Calculator::setVectorDimension (unsigned n) {
  if (n > 0) {
    vectorDimension = n;
    return true;
  }
  return false;
}

std::vector<int> Calculator::getMemory () {
  return memory;
}

bool Calculator::setMemory (std::vector<int> vector) {
  if (vector.size() > 0) {
    memory = vector;
    return true;
  }
  return false;
}

std::vector<int> Calculator::sumVectors (std::vector<int> v1, std::vector<int> v2) {
  unsigned counter = 0;
  std::vector<int> result;
  while (counter < v1.size()) {
    result.push_back(v1.at(counter) + v2.at(counter));
  }
  currentResult = result;
  return result;
};

std::vector<int> Calculator::scaleVector (std::vector<int> vector, int multiplier) {
  unsigned counter = 0;
  while (counter < vector.size()) {
    vector.at(counter) *= multiplier;
  }
  currentResult = vector;
  return vector;
};

std::vector<int> Calculator::calculateLinearCombination (std::vector<int>, std::vector<int>) {

};

int Calculator::calculateInnerProduct (std::vector<int> v1, std::vector<int> v2) {
  unsigned counter = 0;
  int result = 0;
  while (counter < v1.size()) {
    result += v1.at(counter)*v2.at(counter);
  }
  return result;
};

float Calculator::calculateVectorNorm (std::vector<int> vector) {
  unsigned counter = 0;
  float norm = 0;
  while (counter < vector.size()) {
    norm += pow(vector.at(counter), 2);
  }
  return sqrt(norm);
};

float Calculator::calculateDistance (std::vector<int> v1, std::vector<int> v2) {
  unsigned counter = 0;
  float distance = 0;
  while (counter < v1.size()) {
    distance += pow((v1.at(counter) - v2.at(counter)), 2);
  }
  return sqrt(distance);
};

float Calculator::calculateAngle (std::vector<int>, std::vector<int>) {

};
