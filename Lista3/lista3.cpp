/* ---------------------------------------
  Fabiana Ferreira Fonseca
  Universidade Federal do Rio de Janeiro
  DRE: 115037241
----------------------------------------*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stdio.h>
#include "functions.h"

using namespace std;

/*--------------------------------------------- MAIN -------------------------------------------------------*/
int main()
{
  string input;

  printMenu();

  cout << endl;

  while (input.compare("exit") != 0)
  {
    cout << "Digite uma opcao: ";
    getline(cin, input);
    if (input == "1")
    {
      cout << "Digite o inicio e o fim da faixa de codigos a serem impressos,"
           << "alem do numero de linhas por pagina (separados por espaço): ";

      //Pegando os argumentos
      getline(cin, input);
      vector<float> arg = getNumbersFromInput(input, ' ');

      for (auto element : arg)
      {
        /*Testa se eh inteiro*/
        if (fmod(element, 1) != 0)
        {
          cout << "Valor do argumento nao inteiro" << endl;
        }
        else
        {
          printAsciiTable((short int)arg.at(0), (unsigned)arg.at(2));
        }
      }
    }
    else if (input == "2")
    {
      cout << "2" << endl;
      getline(cin, input);
    }
    else if (input == "3")
    {
      cout << "3" << endl;
    }
    else if (input == "4")
    {
      cout << "4" << endl;
      getline(cin, input);
    }
    else if (input.compare("exit") != 0)
    {
      cout << "Digite uma opcao valida" << endl;
    }

    cout << endl;
  }

  cout << "Obrigada por testar!" << endl;

  return 0;
}
