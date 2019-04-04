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
#include "functions.h"
#include "ClasseCalculadora.h"

using namespace std;

/*--------------------------------------------- MAIN -------------------------------------------------------*/
int main () {
  string input;
  string values;

  printMenu();

  cout << endl;

  Calculator *calculator = new Calculator();

  while (input.compare("exit") != 0) {
    cout << "Digite uma opcao: ";
    getline (cin,input);

    switch (atoi(input.c_str()))
    {
      case 1:
        cout << input << endl;
        {
          std::vector<float> v1, v2;

          /*Se quer usar o ultimo resultado armazenado*/
          if (calculator->currentResult.size() != 0) {
            cout << "Voce deseja utilizar o ultimo resultado? (y/n) ";
            getline (cin,values);
            int option = getUserOption(values);
            if (option < 0) {
              cout << "Opcao invalida. Tente novamente" << endl;
              break;
            }
            /*Se quer usar, atribuo o valor do ultimo resultado ao v1*/
            if (option == 1) {
              v1 = calculator->currentResult;
            }
            /*Se nao, peco para entrar com o v1*/
            else {
              cout << "Digite as coordenadas do primeiro vetor separados por espaço: ";
              getline (cin,values);
               v1 = getNumbersFromInput(values, ' ');
            }

            cout << "Digite as coordenadas do segundo vetor separados por espaço: ";
            getline (cin,values);
            v2 = getNumbersFromInput(values, ' ');
          }
          /*Se nao quer usar o ultimo resultado armazenado*/
          else {
            cout << "Digite as coordenadas do primeiro vetor separados por espaço: ";
            getline (cin,values);
             v1 = getNumbersFromInput(values, ' ');

            cout << "Digite as coordenadas do segundo vetor separados por espaço: ";
            getline (cin,values);
            v2 = getNumbersFromInput(values, ' ');
          }


          if (v1.size() != v2.size())
            cout << "Vetores com tamanhos diferentes" << endl;
          else {
            std::vector<float> result = calculator->sumVectors(v1, v2);
            for (unsigned i = 0; i < result.size(); i++) {
              cout << calculator->currentResult.at(i) << " ";

            }
            cout << endl;
          }
        }
        break;

      case 2:
        {
          cout << input << endl;
        }

       break;

      case 3:
       cout << input << endl;
       break;

      case 4:
       cout << input << endl;
       break;

      case 5:
       cout << input << endl;
       break;

      case 6:
       cout << input << endl;
       break;

      case 7:
       cout << input << endl;
       break;

      case 8:
       cout << input << endl;
       break;

      case 9:
       cout << input << endl;
       break;

      case 10:
       cout << input << endl;
       break;

      default:
        cout << "Opcao invalida. Por favor, tente novamente." << endl;
        break;
    }
  }
  cout << "Obrigada por testar!" << endl;

  return 0;
}
