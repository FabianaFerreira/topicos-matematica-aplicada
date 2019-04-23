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
      cout << "Digite o fim da faixa de codigos a serem impressos (de apenas enter para usar o valor padrao): ";
      getline(cin, input);

      if (input.length() == 0)
        end = 127;
      else
        end = getNumbersFromInput(input, ' ').at(0);

      parameters.push_back(end);

      //Pegando o terceiro argumento
      cout << "Digite o numero de linhas a serem impressos por pagina (de apenas enter para usar o valor padrao): ";
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
      unsigned begin, end, pages;
      int result;
      string languageOption = "";
      vector<float> parameters;

      //Pegando o primeiro argumento
      cout << "Digite 1 para Russo, 2 para Grego e 3 para Braille: ";
      getline(cin, languageOption);

      if (languageOption.compare("1") != 0 && languageOption.compare("2") != 0 && languageOption.compare("3") != 0)
      {
        cout << "Opcao invalida. Assumindo que eh 2 (Grego)" << endl;
        languageOption = "2";
      }

      //Pegando o primeiro argumento
      cout << "Digite o inicio da faixa de codigos a serem impressos"
           << "(de apenas enter para usar o valor padrao): ";
      getline(cin, input);

      if (input.length() == 0)
      {
        if (languageOption.compare("1") == 0)
        {
          begin = 1040;
        }

        else if (languageOption.compare("2") == 0)
        {
          begin = 913;
        }
        else
        {
          begin = 10240;
        }
      }
      else
        begin = getNumbersFromInput(input, ' ').at(0);

      parameters.push_back(begin);

      //Pegando o segundo argumento
      cout << "Digite o fim da faixa de codigos a serem impressos"
           << "(de apenas enter para usar o valor padrao): ";
      getline(cin, input);

      if (input.length() == 0)
      {
        if (languageOption.compare("1") == 0)
          end = 1103;
        else if (languageOption.compare("2") == 0)
          end = 969;
        else
          end = 10495;
      }
      else
        end = getNumbersFromInput(input, ' ').at(0);

      parameters.push_back(end);

      //Pegando o terceiro argumento
      cout << "Digite o numero de linhas a serem impressos por pagina"
           << "(de apenas enter para usar o valor padrao): ";
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
      result = printUnicodeTable(parameters.at(0), parameters.at(1), parameters.at(2));
      if (result < 0)
        cout << "Erro ao imprimir tabela. Parametro 'inicio' maior do que 'fim'" << endl;
    }
    else if (input == "3")
    {
      vector<string> files;
      getFilesList("/home/fabiana/Desktop/testeArq", files, false);

      generateWordsFile(files);
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
