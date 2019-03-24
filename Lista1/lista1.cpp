#include<iostream>
#include <string>
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

  if (arg.size() != 3)
    cout << "Quantidade invalida de argumentos"<< endl;
  else if (arg[0] == 0)
    cout << "Coeficiente a = 0. Equacao de primeira ordem." << endl;
  else {
    Equation* eq = new Equation(arg[0], arg[1], arg[2]);
    eq->solveEquation();
    cout << endl;
  }
}

void calculateMultiples (string input) {
  vector<float> arg = getNumbersFromInput(input, ' ');

  if (arg.size() != 3)
    cout << "Quantidade invalida de argumentos" << endl;

  int x = arg[0];
  int y = arg[1];
  unsigned n = arg[2];
  unsigned contador = 0;
  string multiplesX = "";
  string multiplesY = "";

  while (contador < n) {
    multiplesX += " " + to_string(contador*x);
    multiplesY += " " + to_string(contador*y);
    contador ++;
  }

  cout << "Multiplos de x: " << multiplesX << endl << "Multiplos de y: " << multiplesY << endl;
}


void printMenu () {
  cout << "Digite 1 para equacao do segundo grau" << endl;
  cout << "Digite 2 para N primeiros multiplos entre dois numeros" << endl;
  cout << "Digite 3 para soma de vetores de N coordenadas" << endl;
  cout << "Digite 3 para soma de vetores de N coordenadas" << endl;
  cout << "Digite 4 para a questao dos postos em um raio de X km" << endl;
  cout << "Digite 'exit' para sair do programa" << endl;
}

int main () {
  string input;

  printMenu();  

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
        cout << "Digite os numeros x e y e a quantidade de multiplos a ser calculado (x, y, n): ";
        getline(cin, input);
        calculateMultiples(input);
        continue;
      }
      if (input == "3") {
        cout << "3" << endl;
      }
      if (input == "4") {
        cout << "4" << endl;
      }
      else {
        cout << "Digite uma opcao valida" << endl;
      }

      cout << endl;
  }

  cout << "Obrigada por testar!" << endl;

  return 0;
}
