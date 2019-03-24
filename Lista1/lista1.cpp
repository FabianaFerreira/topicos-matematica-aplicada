#include<iostream>
#include <string.h>
#include <vector>
#include <sstream>

#include "ClasseEquacaoSegundoGrau.h"

using namespace std;


vector<float> getNumbersFromInput (string str, char delimiter) {
  vector<float> tokenVector;
  stringstream ss (str);
  string token;
  while (getline (ss, token, delimiter)) {
      tokenVector.push_back (stof(token));
  }

  return tokenVector;
}

void callEquationSolver (string input) {
  vector<float> arg = getNumbersFromInput(input, ' ');

  if (arg.size() != 3 && arg.size() != 2)
    cout << "Quantidade invalida de argumentos"<< endl;
  else {
    Equation* eq = new Equation(arg[0], arg[1], arg[2]);
    eq->solveEquation();
    cout << endl;
  }
}

int main () {
  string input;

  cout << "Digite 1 para equacao do segundo grau"<< endl;
  cout << "Digite 2 para N primeiros multiplos entre dois numeros"<< endl;
  cout << "Digite 3 para soma de vetores de N coordenadas"<< endl;
  cout << "Digite 3 para soma de vetores de N coordenadas"<< endl;
  cout << "Digite 4 para a questao dos postos em um raio de X km" << endl;
  cout << "Digite 'exit' para sair do programa" << endl;

  cout << endl;

  while (input.compare("exit") != 0) {
      cout << "Digite uma opcao: ";
      getline (cin,input);
      if (input == "1") {
        cout << "Digite os coeficientes da equacao (a, b e c): ";
        getline(cin,input);
        callEquationSolver(input);
        continue;
      }
      if (input == "2") {
        cout << "2" << endl;
      }
      if (input == "3") {
        cout << "3" << endl;
      }
      if (input == "4") {
        cout << "4" << endl;
      }

      cout << endl;
  }

  cout << "Obrigada por testar!" << endl;

  return 0;
}
