#include<iostream>
#include <string.h>
#include <vector>
#include <sstream>

#include "ClasseEquacaoSegundoGrau.h"

using namespace std;


std::vector<float> getNumbersFromInput (std::string str, char delimiter) {
  std::vector<float> tokenVector;
  std::stringstream ss (str);
  std::string token;
  cout << str << endl;
  while (std::getline (ss, token, delimiter)) {
      tokenVector.push_back (stof(token));
  }

  return tokenVector;
}

int main () {
  string input;
  bool exit = false;

  cout << "Digite os coeficientes da equacao" << endl;
  std::getline (std::cin,input);

  if (input.compare("exit") == 0)
    exit = true;
  else {
    std::vector<float> arg = getNumbersFromInput(input, ' ');
    Equation* eq = new Equation(arg[0], arg[1], arg[2]);
    eq->solveEquation();
  }

  return 0;
}
