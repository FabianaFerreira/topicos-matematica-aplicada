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
    Calculator (unsigned n = 3);

    std::vector<float> currentResult;

    unsigned getVectorDimension ();

    bool setVectorDimension (unsigned);

    std::vector<float> getMemory ();

    bool setMemory (std::vector<float>);

    std::vector<float> sumVectors (std::vector<float>, std::vector<float>);

    std::vector<float> scaleVector (std::vector<float>, int);

    std::vector<float> calculateLinearCombination (std::vector<float>, std::vector<float>, int, int);

    float calculateInnerProduct (std::vector<float>, std::vector<float>);

    float calculateVectorNorm (std::vector<float>);

    float calculateDistance (std::vector<float>, std::vector<float>);

    float calculateAngle (std::vector<float>, std::vector<float>);

  private:
    unsigned vectorDimension;

    std::vector<float> memory;
};
