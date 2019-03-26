/* ---------------------------------------
  Fabiana Ferreira Fonseca
  Universidade Federal do Rio de Janeiro
  DRE: 115037241
----------------------------------------*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "ClasseEquacaoSegundoGrau.h"
#include "functions.h"

using namespace std;


/*--------------------------------------------- MAIN -------------------------------------------------------*/
int main () {
  string input;
  //setando o seed
  srand(time(NULL));

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
      else if (input == "2") {
        cout << "Digite os numeros x e y e a quantidade de multiplos a ser calculado (x, y, n): ";
        getline(cin, input);
        calculateMultiples(input);      
      }
      else if (input == "3") {
        cout << "Digite a dimensao dos vetores (n): ";
        getline(cin, input);

        vector<int> v1 = generateRandomVector(stoi(input));
        vector<int> v2 = generateRandomVector(stoi(input));

        sumTwoVectors(v1, v2);
      }
      else if (input == "4") {
        cout << "Digite a sua posicao e o raio em km (x, y e r): ";
        getline(cin, input);

        listPointsInRange(input);
      }
      else if (input.compare("exit") != 0){
        cout << "Digite uma opcao valida" << endl;
      }

      cout << endl;
  }

  cout << "Obrigada por testar!" << endl;

  return 0;
}
