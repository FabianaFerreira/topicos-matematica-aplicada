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
      unsigned begin, end, pages;
      int result;
      vector<float> parameters;

      //Pegando o primeiro argumento
      cout << "Digite o inicio da faixa de codigos a serem impressos: ";
      getline(cin, input);

      if (input.length() == 0)
        begin = 32;
      else
        begin = getNumbersFromInput(input, ' ').at(0);

      parameters.push_back(begin);

      //Pegando o segundo argumento
      cout << "Digite o fim da faixa de codigos a serem impressos: ";
      getline(cin, input);

      if (input.length() == 0)
        end = 127;
      else
        end = getNumbersFromInput(input, ' ').at(0);

      parameters.push_back(end);

      //Pegando o terceiro argumento
      cout << "Digite o numero de linhas a serem impressos por pagina: ";
      getline(cin, input);

      if (input.length() == 0)
        pages = 25;
      else
        pages = getNumbersFromInput(input, ' ').at(0);

      parameters.push_back(pages);

      for (auto element : parameters)
      {
        /*Testa se eh inteiro*/
        if (fmod(element, 1) != 0)
        {
          cout << "Valor do argumento nao inteiro" << endl;
          break;
        }
      }
      result = printAsciiTable(parameters.at(0), parameters.at(1), parameters.at(2));
      if (result < 0)
        cout << "Erro ao imprimir tabela. Parametro 'inicio' maior do que 'fim'" << endl;
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
