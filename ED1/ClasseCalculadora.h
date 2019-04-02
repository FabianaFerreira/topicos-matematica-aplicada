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
    Calculator (unsigned);

    std::vector<int> currentResult;

    unsigned getVectorDimension ();

    bool setVectorDimension (unsigned);

    std::vector<int> getMemory ();

    bool setMemory (std::vector<int>);

    std::vector<int> sumVectors (std::vector<int>, std::vector<int>);

    std::vector<int> scaleVector (std::vector<int>, int);

    std::vector<int> calculateLinearCombination (std::vector<int>, std::vector<int>);

    int calculateInnerProduct (std::vector<int>, std::vector<int>);

    float calculateVectorNorm (std::vector<int>);

    float calculateDistance (std::vector<int>, std::vector<int>);

    float calculateAngle (std::vector<int>, std::vector<int>);

  private:
    unsigned vectorDimension;

    std::vector<int> memory;
};
