/* ---------------------------------------
  Fabiana Ferreira Fonseca
  Universidade Federal do Rio de Janeiro
  DRE: 115037241
----------------------------------------*/

#include <iostream>
#include <fstream>
#include <sstream>

#include <string>
#include <vector>

#include <stdlib.h>
#include <stdio.h>

#include "functions.h"
#include "ClasseCalculadora.h"
#include "MatrixList.h"

using namespace std;

/*--------------------------------------------- MAIN -------------------------------------------------------*/
int main()
{
  char index;

  // MatrixList matrixList;

  // --- Constructing from file ---
  MatrixList matrixList("matrix.txt");
  // matrixList.list();
  // ------------------------------

  // // --- Adding matrix ---

  // // --- Adding identity 3x3 ---
  // matrixList.insertIdentity('i', 3);
  // cout << "Inserted identity 'i' 3x3" << endl;
  // matrixList.list();
  // // ---------------------------

  // // --- Get matrix by index ---
  // cout << "Getting the matrix 'i'" << endl;
  // printMatrix(matrixList.get('i'));
  // cout << endl;
  // // ---------------------------

  // // --- Removing matrix by index ---
  // matrixList.remove('a');
  // cout << "After removing the matrix 'a'" << endl;
  // matrixList.list();
  // // --------------------------------

  // // --- Clearing the matrix list ---
  // // matrixList.clear();
  // // matrixList.list();
  // // --------------------------------

  // // --- Reading from file (appending or not) ---
  // cout << "Reading from file" << endl;
  // matrixList.readFile("matrix2.txt", true);
  // matrixList.list();
  // // --------------------------------

  // // --- Saving to file ---
  // matrixList.save("teste.txt");
  // // ----------------------

  string input;

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
      cout << "Digite o identificador da primeira matriz: " << endl;
      cin >> index;

      //Copy constructor
      Matrix m1(matrixList.get(index));

      cout << "Digite o identificador da segunda matriz: " << endl;
      cin >> index;

      //Copy constructor
      Matrix m2(matrixList.get(index));

      cout << "Eh substracao? (y/n): " << endl;
      cin >> index;

      int isSub = getUserOption(index);

      //In case of getUserOption throwing -1 as result -> invalid option
      if (isSub == -1)
      {
        cout << "Opcao invalida" << endl;
      }
      else
      {
        vector<unsigned> size1(Calculator::getMatrixDimension(m1));
        vector<unsigned> size2(Calculator::getMatrixDimension(m2));

        cout << "Linhas: " << size1.at(0) << " " << size2.at(0) << endl;
        cout << "Colunas: " << size1.at(1) << " " << size2.at(1) << endl;

        if (size1.at(0) == size2.at(0) && size1.at(1) == size2.at(1))
        {
          Matrix result(calculator->sumOrSubMatrices(m1, m2, isSub));
          cout << "Resultado: " << endl;
          printMatrix(result);
        }

        else
          cout << "Numero de linhas da matriz 1 eh diferente do numero de colunas da matriz 2. Nao eh possivel realizar a operacao" << endl;
      }
    }
    break;

    /*Multiplicação por escalar*/
    case 2:
    {
      cout << "Digite o identificador da matriz: " << endl;
      cin >> index;

      //Copy constructor
      Matrix m(matrixList.get(index));

      string mult;
      cout << "Digite o multiplicador: " << endl;
      cin >> mult;

      Matrix result(calculator->scaleMatrix(m, stof(mult)));

      //Printing result
      cout << "Resultado: " << endl;
      printMatrix(result);
    }

    break;

    /*Multiplicação matricial*/
    case 3:
    {
      cout << "Digite o identificador da primeira matriz: " << endl;
      cin >> index;

      //Copy constructor
      Matrix m1(matrixList.get(index));

      cout << "Digite o identificador da segunda matriz: " << endl;
      cin >> index;

      //Copy constructor
      Matrix m2(matrixList.get(index));

      vector<unsigned> size1(Calculator::getMatrixDimension(m1));

      vector<unsigned> size2(Calculator::getMatrixDimension(m2));

      if (size1.at(1) == size2.at(0))
      {
        Matrix result(calculator->multiplyMatrices(m1, m2, size1.at(0), size2.at(1)));
        cout << "Resultado: " << endl;
        printMatrix(result);
      }

      else
        cout << "Numero de linhas da matriz 1 eh diferente do numero de colunas da matriz 2. Nao eh possivel realizar a operacao" << endl;
    }
    break;

    /*Transposição*/
    case 4:
    {
      cout << "Digite o identificador da matriz: " << endl;
      cin >> index;

      //Copy constructor
      Matrix m(matrixList.get(index));

      vector<unsigned> size(Calculator::getMatrixDimension(m));

      Matrix result(calculator->transposeMatrix(m, size.at(0), size.at(1)));

      //Printing result
      cout << "Resultado: " << endl;
      printMatrix(result);
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

    case 12:
    {
    }
    break;

    case 13:
    {
      cout << "Digite uma letra para identificar a nova matriz: " << endl;
      cin >> index;
      cin.ignore();
      Matrix newMatrix = getMatrixFromUser();
      matrixList.insert(index, newMatrix);
      matrixList.list();
    }
    break;

    case 14:
    {
    }
    break;

    case 15:
    {
    }
    break;

    case 16:
    {
    }
    break;

    case 17:
    {
    }
    break;

    case 18:
    {
    }
    break;

    case 19:
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
