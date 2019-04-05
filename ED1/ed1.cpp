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
    unsigned dimension = calculator->getVectorDimension();

    switch (atoi(input.c_str()))
    {
    case 1:
    {
      std::vector<float> v1, v2;

      /*Se quer usar o ultimo resultado armazenado*/
      if (calculator->currentResult.size() != 0)
      {
        cout << "Voce deseja utilizar o ultimo resultado? (y/n) ";
        getline(cin, values);
        int option = getUserOption(values);
        if (option < 0)
          cout << "Opcao invalida. Tente novamente" << endl;
        /*Se quer usar, atribuo o valor do ultimo resultado ao v1. Se nao, peco para entrar com o v1*/
        if (option == 1)
          v1 = calculator->currentResult;
        else
          v1 = getVectorFromUser(true);

        v2 = getVectorFromUser(false);
      }
      /*Se nao quer usar o ultimo resultado armazenado*/
      else
      {
        v1 = getVectorFromUser(true);
        v2 = getVectorFromUser(false);
      }

      if (v1.size() != v2.size())
        cout << "Vetores com tamanhos diferentes" << endl;
      else if (v1.size() != dimension || v2.size() != dimension)
        cout << "Vetores nao condizem com a dimensao definida na calculadora. Dimensao: " << dimension << endl;
      else
      {
        std::vector<float> result = calculator->sumVectors(v1, v2);
        /*Printando resultado*/
        cout << "Resultado: [";
        for (unsigned i = 0; i < result.size(); i++)
        {
          cout << " " << calculator->currentResult.at(i) << " ";
        }
        cout << "]" << endl;
      }
    }
    break;

    case 2:
    {
      std::vector<float> v1;
      float scalar;

      /*Se quer usar o ultimo resultado armazenado*/
      if (calculator->currentResult.size() != 0)
      {
        cout << "Voce deseja utilizar o ultimo resultado? (y/n) ";
        getline(cin, values);
        int option = getUserOption(values);
        if (option < 0)
          cout << "Opcao invalida. Tente novamente" << endl;

        /*Se quer usar, atribuo o valor do ultimo resultado ao v1. Se nao, peco para entrar com o v1*/
        if (option == 1)
          v1 = calculator->currentResult;
        else
          v1 = getVectorFromUser(true);
      }
      /*Se nao quer usar o ultimo resultado armazenado*/
      else
        v1 = getVectorFromUser(true);

      cout << "Digite o valor que você deseja multiplicar o seu vetor: ";
      getline(cin, values);
      scalar = getNumbersFromInput(values, ' ').at(0);

      if (v1.size() != dimension)
        cout << "Vetor nao condiz com a dimensao definida na calculadora. Dimensao: " << dimension << endl;
      else
      {
        std::vector<float> result = calculator->scaleVector(v1, scalar);
        /*Printando resultado*/
        cout << "Resultado: [";
        for (unsigned i = 0; i < result.size(); i++)
        {
          cout << " " << calculator->currentResult.at(i) << " ";
        }
        cout << "]" << endl;
      }
    }

    break;

    case 3:
    {
      std::vector<float> v1, v2;
      float alpha, beta;

      /*Se quer usar o ultimo resultado armazenado*/
      if (calculator->currentResult.size() != 0)
      {
        cout << "Voce deseja utilizar o ultimo resultado? (y/n) ";
        getline(cin, values);
        int option = getUserOption(values);
        if (option < 0)
          cout << "Opcao invalida. Tente novamente" << endl;
        /*Se quer usar, atribuo o valor do ultimo resultado ao v1. Se nao, peco para entrar com o v1*/
        if (option == 1)
          v1 = calculator->currentResult;
        else
          v1 = getVectorFromUser(true);

        v2 = getVectorFromUser(false);
      }
      /*Se nao quer usar o ultimo resultado armazenado*/
      else
      {
        v1 = getVectorFromUser(true);
        v2 = getVectorFromUser(false);
      }

      if (v1.size() != v2.size())
        cout << "Vetores com tamanhos diferentes" << endl;
      else if (v1.size() != dimension || v2.size() != dimension)
        cout << "Vetores nao condizem com a dimensao definida na calculadora. Dimensao: " << dimension << endl;
      else
      {
        cout << "Digite os escalares alfa e beta para multiplicar separados por espaço: ";
        getline(cin, values);
        std::vector<float> arg = getNumbersFromInput(values, ' ');

        if (arg.size() != 2)
        {
          cout << "Quantidade invalida de argumentos" << endl;
        }
        else
        {
          alpha = arg.at(0);
          beta = arg.at(1);
          std::vector<float> result = calculator->calculateLinearCombination(v1, v2, alpha, beta);
          /*Printando resultado*/
          cout << "Resultado: [";
          for (unsigned i = 0; i < result.size(); i++)
          {
            cout << " " << calculator->currentResult.at(i) << " ";
          }
          cout << "]" << endl;
        }
      }
    }
    break;

    case 4:
    {
      std::vector<float> v1, v2;

      /*Se quer usar o ultimo resultado armazenado*/
      if (calculator->currentResult.size() != 0)
      {
        cout << "Voce deseja utilizar o ultimo resultado? (y/n) ";
        getline(cin, values);
        int option = getUserOption(values);
        if (option < 0)
          cout << "Opcao invalida. Tente novamente" << endl;
        /*Se quer usar, atribuo o valor do ultimo resultado ao v1. Se nao, peco para entrar com o v1*/
        if (option == 1)
          v1 = calculator->currentResult;
        else
          v1 = getVectorFromUser(true);

        v2 = getVectorFromUser(false);
      }
      /*Se nao quer usar o ultimo resultado armazenado*/
      else
      {
        v1 = getVectorFromUser(true);
        v2 = getVectorFromUser(false);
      }

      if (v1.size() != v2.size())
        cout << "Vetores com tamanhos diferentes" << endl;
      else if (v1.size() != dimension || v2.size() != dimension)
        cout << "Vetores nao condizem com a dimensao definida na calculadora. Dimensao: " << dimension << endl;
      else
      {
        float result = calculator->calculateInnerProduct(v1, v2);
        /*Printando resultado*/
        cout << "Resultado do produto interno: " << result << endl;
      }
    }
    break;

    case 5:
    {
      std::vector<float> v1;

      /*Se quer usar o ultimo resultado armazenado*/
      if (calculator->currentResult.size() != 0)
      {
        cout << "Voce deseja utilizar o ultimo resultado? (y/n) ";
        getline(cin, values);
        int option = getUserOption(values);
        if (option < 0)
          cout << "Opcao invalida. Tente novamente" << endl;
        /*Se quer usar, atribuo o valor do ultimo resultado ao v1. Se nao, peco para entrar com o v1*/
        if (option == 1)
          v1 = calculator->currentResult;
        else
          v1 = getVectorFromUser(true);
      }
      /*Se nao quer usar o ultimo resultado armazenado*/
      else
        v1 = getVectorFromUser(true);

      if (v1.size() != dimension)
        cout << "Vetor nao condiz com a dimensao definida na calculadora. Dimensao: " << dimension << endl;
      else
      {
        float result = calculator->calculateVectorNorm(v1);
        /*Printando resultado*/
        cout << "Resultado da norma vetorial: " << result << endl;
      }
    }
    break;

    case 6:
    {
      std::vector<float> v1, v2;

      /*Se quer usar o ultimo resultado armazenado*/
      if (calculator->currentResult.size() != 0)
      {
        cout << "Voce deseja utilizar o ultimo resultado? (y/n) ";
        getline(cin, values);
        int option = getUserOption(values);
        if (option < 0)
          cout << "Opcao invalida. Tente novamente" << endl;
        /*Se quer usar, atribuo o valor do ultimo resultado ao v1. Se nao, peco para entrar com o v1*/
        if (option == 1)
          v1 = calculator->currentResult;
        else
          v1 = getVectorFromUser(true);

        v2 = getVectorFromUser(false);
      }
      /*Se nao quer usar o ultimo resultado armazenado*/
      else
      {
        v1 = getVectorFromUser(true);
        v2 = getVectorFromUser(false);
      }

      if (v1.size() != v2.size())
        cout << "Vetores com tamanhos diferentes" << endl;
      else if (v1.size() != dimension || v2.size() != dimension)
        cout << "Vetores nao condizem com a dimensao definida na calculadora. Dimensao: " << dimension << endl;
      else
      {
        float result = calculator->calculateDistance(v1, v2);
        /*Printando resultado*/
        cout << "Distancia entre os vetores (u.m.): " << result << endl;
      }
    }
    break;

    case 7:
    {
      std::vector<float> v1, v2;

      /*Se quer usar o ultimo resultado armazenado*/
      if (calculator->currentResult.size() != 0)
      {
        cout << "Voce deseja utilizar o ultimo resultado? (y/n) ";
        getline(cin, values);
        int option = getUserOption(values);
        if (option < 0)
          cout << "Opcao invalida. Tente novamente" << endl;
        /*Se quer usar, atribuo o valor do ultimo resultado ao v1. Se nao, peco para entrar com o v1*/
        if (option == 1)
          v1 = calculator->currentResult;
        else
          v1 = getVectorFromUser(true);

        v2 = getVectorFromUser(false);
      }
      /*Se nao quer usar o ultimo resultado armazenado*/
      else
      {
        v1 = getVectorFromUser(true);
        v2 = getVectorFromUser(false);
      }

      if (v1.size() != v2.size())
        cout << "Vetores com tamanhos diferentes" << endl;
      else if (v1.size() != dimension || v2.size() != dimension)
        cout << "Vetores nao condizem com a dimensao definida na calculadora. Dimensao: " << dimension << endl;
      else
      {
        float result = calculator->calculateAngle(v1, v2);
        /*Printando resultado*/
        cout << "Angulo (em radianos): " << result << endl;
      }
    }
    break;

    case 8:
    {
      cout << "Digite o novo valor para a dimensao dos vetores (valor natural): ";
      getline(cin, values);
      std::vector<float> arg = getNumbersFromInput(values, ' ');

      if (arg.size() != 1)
      {
        cout << "Quantidade de argumentos invalida" << endl;
      }
      else
      {
        float n = arg.at(0);

        /*Testa se eh inteiro*/
        if (fmod(n, 1) != 0)
        {
          cout << "Valor de dimensao nao inteiro" << endl;
        }
        else
        {
          cout << "valor: " << n << endl;
          string message;
          calculator->setVectorDimension(n) ? message = "Valor alterado com sucesso" : message = "Erro ao alterar valor, pois eh menor que zero.";
          cout << message << endl;
        }
      }
    }
    break;

    case 9:
    {
      if (calculator->currentResult.size() == 0)
        cout << "Nao ha um resultado armazenado na calculadora" << endl;
      else if (calculator->setMemory(calculator->currentResult))
        cout << "Resultado armazenado na memoria com sucesso" << endl;
      else
        cout << "Erro ao armazenar resultado na memoria" << endl;
    }
    break;

    case 10:
      if (calculator->currentResult.size() == 0)
        cout << "Nao ha um resultado armazenado na calculadora" << endl;
      else
      {
        cout << "O ultimo resultado na calculadora foi: [";
        for (unsigned i = 0; i < calculator->currentResult.size(); i++)
        {
          cout << " " << calculator->currentResult.at(i) << " ";
        }
        cout << "]" << endl;
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
