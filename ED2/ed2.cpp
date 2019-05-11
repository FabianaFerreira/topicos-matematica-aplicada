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
#include <stdio.h>
#include "functions.h"
#include "ClasseCalculadora.h"

using namespace std;

/*--------------------------------------------- MAIN -------------------------------------------------------*/
int main()
{
  string input;
  string values;

  printMenu();

  cout << endl;

  Calculator *calculator = new Calculator();

  while (input.compare("exit") != 0)
  {
    cout << "Digite uma opcao: ";
    getline(cin, input);

    switch (atoi(input.c_str()))
    {
    case 1:
    {
    }
    break;

    case 2:
    {
    }

    break;

    case 3:
    {
    }
    break;

    case 4:
    {
    }
    break;

    case 5:
    {
    }
    break;

    case 6:
    {
    }
    break;

    case 7:
    {
    }
    break;

    case 8:
    {
    }
    break;

    case 9:
    {
    }
    break;

    case 10:

      break;

    default:
    {
      if (!input.compare("exit") == 0)
        cout << "Opcao invalida. Por favor, tente novamente." << endl;
    }
    break;
    }
  }
  cout << "Obrigada por testar!" << endl;

  return 0;
}
