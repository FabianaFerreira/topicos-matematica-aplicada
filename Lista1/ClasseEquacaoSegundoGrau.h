#include <sstream>
#include <vector>
#include <iostream>
#include <string.h>
#include <math.h>

class Equation
{
  float _a;
  float _b;
  float _c;
  public:
    Equation (float, float, float);

    void solveEquation ();

  private:
    float calculateDelta (float, float, float);

};
