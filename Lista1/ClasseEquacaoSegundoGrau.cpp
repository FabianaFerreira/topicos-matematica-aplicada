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
    if (delta > 0) {
      std::cout << "Delta maior do que zero: raizes reais e diferentes" << std::endl;
      std::cout << "Raizes: " << ((-_b + sqrt(delta))/2*_a) << " e " << ((-_b - sqrt(delta))/2*_a) << std::endl;
    }
    else if (delta == 0) {
      std::cout << "Delta igual a zero: raizes reais e iguais" << std::endl;
      std::cout << "Raiz: " << (-_b/2*_a) << std::endl;
    }
    else {
      std::cout << "Delta menor do que zero: raizes complexas e conjugadas" << std::endl;
      float imaginaryPart = sqrt(abs(delta))/(2*_a);
      std::cout << "Raizes: " << (-_b/2*_a) << " +/- " << imaginaryPart << "j" << std::endl;
    }
}

float Equation::calculateDelta(float coefA, float coefB, float coefC) {
  return pow(coefB, 2) - 4*coefA*coefC;
}
