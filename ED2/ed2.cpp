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
    /*Soma ou subtração*/
    case 1:
    {
      Matrix m1{{1, 2, 3},
                {4, 5, 6},
                {7, 8, 9}};

      Matrix m2{{1, 2, 3},
                {4, 5, 6}};

      vector<unsigned> size1 = Calculator::getMatrixDimension(m1);
      vector<unsigned> size2 = Calculator::getMatrixDimension(m2);

      cout << "Tamanho 1: " << size1.at(0) << " " << size1.at(1) << endl;
      cout << "Tamanho 2: " << size2.at(0) << " " << size2.at(1) << endl;

      if (size1.at(0) == size2.at(0) && size1.at(1) == size2.at(1))
      {
        Matrix result = calculator->sumOrSubMatrices(m1, m2, 1);

        //Debug
        for (unsigned i = 0; i < result.size(); i++)
        {
          for (unsigned j = 0; j < result.at(i).size(); j++)
          {
            cout << " " << result.at(i).at(j) << " " << endl;
          }
        }
      }
      else
      {
        cout << "Matrizes com dimensoes diferentes. Nao eh possivel efetuar o calculo" << endl;
      }
    }
    break;

    /*Multiplicação por escalar*/
    case 2:
    {
      Matrix m1{{1, 2, 3},
                {4, 5, 6},
                {7, 8, 9}};

      Matrix result = calculator->scaleMatrix(m1, 2);

      //Debug
      for (unsigned i = 0; i < result.size(); i++)
      {
        for (unsigned j = 0; j < result.at(i).size(); j++)
        {
          cout << " " << result.at(i).at(j) << " " << endl;
        }
      }
    }

    break;

    /*Multiplicação matricial*/
    case 3:
    {
    }
    break;

    /*Transposição*/
    case 4:
    {
    }
    break;

    /*Permutação de linhas ou colunas*/
    case 5:
    {
    }
    break;

    /*Soma de duas linhas ou colunas*/
    case 6:
    {
    }
    break;

    /*Multiplicação de uma linha ou uma coluna por escalar*/
    case 7:
    {
    }
    break;

    /*Inversão de matrix*/
    case 8:
    {
    }
    break;

    /*Combinação linear*/
    case 9:
    {
    }
    break;

    /*Escalonamento*/
    case 10:
    {
    }
    break;

    /*Resolução de sistema linear*/
    case 11:
    {
    }
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
