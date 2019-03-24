#include <math.h>

#include "ClasseEquacaoSegundoGrau.h"

Equation::Equation (float a, float b, float c)
{
  _a = a;
  _b = b;
  _c = c;
}

void Equation::solveEquation()
{
	float delta = this->calculateDelta(_a, _b, _c);
    if (delta > 0)
      printf("delta maior que zero\n");
}

float Equation::calculateDelta(float coefA, float coefB, float coefC) {
  return pow(coefB, 2) - 4*coefA*coefC;
}
