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
  string input;
  string filename;
  cout << "Digite o nome da lista de matrizes a ser lido (.txt): ";
  cin >> filename;
  cout << endl
       << endl;

  /*Instancias dos objetos das classes Calculator e MatrixList*/
  Calculator *calculator = new Calculator();
  MatrixList matrixList(filename);

  printMenu();

  //Ignoring \n that is in buffer
  cin.ignore();

  while (input.compare("exit") != 0)
  {
    cout << "Digite uma opcao: ";
    getline(cin, input);

    switch (atoi(input.c_str()))
    {
    /*Soma ou subtração*/
    case 1:
    {
      cout << "Digite o identificador da primeira matriz: ";
      cin >> index;

      //Copy constructor
      Matrix m1(matrixList.get(index));

      cout << "Digite o identificador da segunda matriz: ";
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
      cout << "Digite o identificador da matriz: ";
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
      cout << "Digite o identificador da primeira matriz: ";
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
      cout << "Digite o identificador da matriz: ";
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
      cout << "Digite o identificador da matriz: ";
      cin >> index;

      //Copy constructor
      Matrix m(matrixList.get(index));

      cout << "Ira permutar linhas? (y/n) Se nao, colunas serao permutadas" << endl;
      cin >> index;

      int isLine = getUserOption(index);

      unsigned p1, p2;
      string position;

      cout << "Digite a primeira posicao a ser trocada : " << endl;
      cin >> position;

      //Checking for error
      if (!stoi(position))
      {
        cout << "Argumento invalido" << endl;
        break;
      }
      else
        p1 = stoi(position);

      cout << "Digite a segunda posicao a ser trocada : " << endl;
      cin >> position;
      //Checking for error
      if (!stoi(position))
      {
        cout << "Argumento invalido" << endl;
        break;
      }
      else
        p2 = stoi(position);

      //In case of getUserOption throwing -1 as result -> invalid option
      if (isLine == -1)
      {
        cout << "Opcao invalida" << endl;
      }
      else
      {
        vector<unsigned> size(Calculator::getMatrixDimension(m));

        if (isLine == 1)
        {
          if (size.at(0) < p1 || size.at(0) < p2)
          {
            cout << "Uma das posicoes escolhidas eh maior do que a quantidade de linhas da matriz" << endl;
            break;
          }
        }
        else
        {
          if (size.at(1) < p1 || size.at(1) < p2)
          {
            cout << "Uma das posicoes escolhidas eh maior do que a quantidade de colunas da matriz" << endl;
            break;
          }
        }

        Matrix result(calculator->swapLinesOrColumns(m, isLine, p1, p2));
        cout << "Resultado: " << endl;
        printMatrix(result);
      }
    }
    break;

    /*Soma de duas linhas ou colunas*/
    case 6:
    {
      cout << "Digite o identificador da matriz: ";
      cin >> index;

      //Copy constructor
      Matrix m(matrixList.get(index));

      cout << "Ira somar linhas? (y/n) Se nao, colunas serao somadas." << endl;
      cin >> index;

      int isLine = getUserOption(index);

      unsigned p1, p2;
      string position;

      cout << "Digite a posicao a ser substituida pela soma das duas linhas ou colunas: " << endl;
      cin >> position;

      //Checking for error
      if (!stoi(position))
      {
        cout << "Argumento invalido" << endl;
        break;
      }
      else
        p1 = stoi(position);

      cout << "Digite a segunda posicao a ser somada: " << endl;
      cin >> position;
      //Checking for error
      if (!stoi(position))
      {
        cout << "Argumento invalido" << endl;
        break;
      }
      else
        p2 = stoi(position);

      //In case of getUserOption throwing -1 as result -> invalid option
      if (isLine == -1)
      {
        cout << "Opcao invalida" << endl;
      }
      else
      {
        vector<unsigned> size(Calculator::getMatrixDimension(m));

        if (isLine == 1)
        {
          if (size.at(0) < p1 || size.at(0) < p2)
          {
            cout << "Uma das posicoes escolhidas eh maior do que a quantidade de linhas da matriz" << endl;
            break;
          }
        }
        else
        {
          if (size.at(1) < p1 || size.at(1) < p2)
          {
            cout << "Uma das posicoes escolhidas eh maior do que a quantidade de colunas da matriz" << endl;
            break;
          }
        }

        Matrix result(calculator->sumLinesOrColumns(m, isLine, p1, p2));
        cout << "Resultado: " << endl;
        printMatrix(result);
      }
    }
    break;

    /*Multiplicação de uma linha ou uma coluna por escalar*/
    case 7:
    {
      cout << "Digite o identificador da matriz: ";
      cin >> index;

      //Copy constructor
      Matrix m(matrixList.get(index));

      string mult;
      cout << "Digite o multiplicador: " << endl;
      cin >> mult;

      cout << "Ira multiplicar uma linha por um escalar? (y/n) Se nao, uma coluna sera escalada." << endl;
      cin >> index;

      int isLine = getUserOption(index);

      unsigned pos;
      string position;

      cout << "Digite a posicao a ser escalada: " << endl;
      cin >> position;

      //Checking for error
      if (!stoi(position))
      {
        cout << "Argumento invalido" << endl;
        break;
      }
      else
        pos = stoi(position);

      //In case of getUserOption throwing -1 as result -> invalid option
      if (isLine == -1)
      {
        cout << "Opcao invalida" << endl;
      }
      else
      {
        vector<unsigned> size(Calculator::getMatrixDimension(m));

        if (isLine == 1)
        {
          if (size.at(0) < pos)
          {
            cout << "Posicao escolhida eh maior do que a quantidade de linhas da matriz" << endl;
            break;
          }
        }
        else
        {
          if (size.at(1) < pos)
          {
            cout << "Posicao escolhida eh maior do que a quantidade de colunas da matriz" << endl;
            break;
          }
        }

        Matrix result(calculator->multiplyLineOrColumn(m, isLine, pos, stof(mult)));
        cout << "Resultado: " << endl;
        printMatrix(result);
      }
    }
    break;

    /*Inversão de matrix*/
    case 8:
    {
      cout << "Digite o identificador da matriz: " << endl;
      cin >> index;

      //Copy constructor
      Matrix m(matrixList.get(index));

      Matrix result(calculator->generalInverter(m));

      vector<unsigned> size(Calculator::getMatrixDimension(m));

      if (size.at(0) != size.at(1))
      {
        cout << "A matriz nao eh quadrada. A operacao nao pode ser feita." << endl;
        break;
      }
      vector<unsigned> resultSize(Calculator::getMatrixDimension(result));
      cout << "Resultado: " << endl;

      // Result has n x 2n dimension. Using function overloading to print only the part of the matrix which is the result
      printMatrix(result, size.at(0), size.at(1), false);
    }
    break;

    /*Combinação linear*/
    case 9:
    {
      string id;

      cout << "Digite o(s) identificador(es) da(s) matriz(es) a ser(em) listada(s) separados por espaco: ";
      getline(cin, id);
      vector<string> identifiers(parseInput(id, ' '));

      cout << "Digite os coeficientes a serem multiplicados em cada matriz: ";
      getline(cin, id);
      vector<float> multipliers(getNumbersFromInput(id, ' '));

      if (identifiers.size() != multipliers.size())
      {
        cout << "Quantidade de coeficientes nao condiz com a quantidade de matrizes informadas" << endl << endl;
        break;
      }

      Matrix result;
      unsigned n = matrixList.get(identifiers.at(0).c_str()[0]).size();
      for (unsigned i = 0; i < n; i++)
      {
        result.push_back(std::vector<float>(n, 0));
      }

      for (unsigned i = 0; i < identifiers.size(); i++)
      {
        char ident = identifiers.at(i).c_str()[0];
        Matrix current(matrixList.get(ident));
        result = calculator->sumOrSubMatrices(result, calculator->scaleMatrix(current, multipliers.at(i)), 0);
      }
      cout << endl;
      cout << "Resultado: " << endl;
      printMatrix(result);
      cout << endl;
    }
    break;

    /*Escalonamento*/
    case 10:
    {
      cout << "Digite o identificador da matriz: ";
      cin >> index;

      //Copy constructor
      Matrix m(matrixList.get(index));

      vector<unsigned> size(Calculator::getMatrixDimension(m));

      if (size.at(0) != size.at(1))
      {
        cout << "Matriz nao eh quadrada. Nao eh possivel realizar a operacao" << endl;
        break;
      }

      Matrix result;
      unsigned n = size.at(0);
      copyMatrix(m, result, n);

      calculator->gaussElimination(result);

      cout << "Resultado: " << endl;

      // Result has n x 2n dimension. Using function overloading to print only the part of the matrix which is the result
      printMatrix(result, size.at(0), size.at(1), true);
    }
    break;

    /*Resolução de sistema linear*/
    case 11:
    {
      cout << "Digite o identificador da matriz: ";
      cin >> index;
      string id;

      //Copy constructor
      Matrix m(matrixList.get(index));
      Matrix result;

      vector<unsigned> size(Calculator::getMatrixDimension(m));

      cout << "A matriz " << index << " tem " << size.at(1) << " colunas." << endl;
      cout << "Digite os valores do vetor b para resolucao do sistema Ax = b (separados por espaco): ";
      cin.ignore();
      getline(cin, id);

      vector<float> b(getNumbersFromInput(id, ' '));

      if (b.size() != size.at(1))
      {
        cout << "Tamanho do vetor b eh diferente do numero de colunas da matriz " << index << endl;
        break;
      }

      createEquationMatrix(m, b, result, size.at(0));

      vector<float> x(calculator->solveEquation(result));

      cout << endl;
      cout << "Resultado: " << endl
           << endl;
      ;
      cout << "[ ";
      for (int i = 0; i < size.at(0); i++)
      {
        cout << x[i] << " ";
      }
      cout << "]" << endl
           << endl;
    }
    break;

    /*Imprimir uma ou mais matrizes da lista*/
    case 12:
    {
      std::string id;
      cout << "Digite o(s) identificador(es) da(s) matriz(es) a ser(em) listada(s) separados por espaco: ";
      getline(std::cin, id);
      vector<string> identifiers(parseInput(id, ' '));
      for (unsigned i = 0; i < identifiers.size(); i++)
      {
        char ident = identifiers.at(i).c_str()[0];
        cout << "** Matrix " << ident << " **" << endl;
        printMatrix(matrixList.get(ident));
        cout << endl;
      }
    }
    break;

    /*Inserir matriz qualquer*/
    case 13:
    {
      cout << "Digite uma letra para identificar a nova matriz: ";
      cin >> index;
      cin.ignore();
      Matrix newMatrix = getMatrixFromUser();
      matrixList.insert(index, newMatrix);

      cout << endl;
      cout << "Lista alterada com sucesso!" << endl;
      ;
      cout << endl;

      cout << "** -- Lista atual -- **" << endl;
      matrixList.list();
      cout << "** ----------------- **" << endl;
      cout << endl;
    }
    break;

    /*Inserir matriz identidade n x n*/
    case 14:
    {
      char identifier;
      unsigned dimension;
      cout << "Digite o identificador da matriz a ser inserida: ";
      cin >> identifier;

      cout << "Digite a dimensao da matriz identidade a ser inserida: ";
      cin >> dimension;

      matrixList.insertIdentity(identifier, dimension);
      matrixList.list();
    }
    break;
    /*Alterar ou remover uma ou mais matrizes da lista*/
    case 15:
    {
      std::string id;
      char option;
      bool removes = false;
      cout << "Digite o(s) identificador(es) da(s) matriz(es) a ser(em) listada(s) separados por espaco: ";
      getline(cin, id);
      vector<string> identifiers(parseInput(id, ' '));

      for (unsigned i = 0; i < identifiers.size(); i++)
      {
        char ident = identifiers.at(i).c_str()[0];
        cout << "Voce deseja alterar a matriz " << ident << "? (y/n). Se nao, voce ira remove-la. ";
        cin >> option;

        if (getUserOption(option) == -1)
        {
          cout << "Opcao invalida" << endl;
          break;
        }
        removes = getUserOption(option) == 0 ? true : false;

        if (removes)
        {
          matrixList.remove(ident);
          cout << "Matriz " << ident << " removida com sucesso!" << endl;
          matrixList.save(filename);
        }
        else
        {
          cout << "Voce optou por alterar a matriz " << ident << "." << endl;
          cout << endl;
          Matrix newMatrix(getMatrixFromUser());
          matrixList.insert(ident, newMatrix);
          matrixList.save(filename);
        }
        cout << endl;
      }

      cout << endl
           << "Lista alterada com sucesso!" << endl;
      cout << endl;
      matrixList.list();
      cin.ignore();
    }
    break;

    /*Lista todas as matrizes*/
    case 16:
    {
      matrixList.list();
    }
    break;

    /*Fazer backup*/
    case 17:
    {
      string filename;
      cout << "Digite o nome do arquivo de backup: ";
      cin >> filename;

      matrixList.save(filename);

      cout << endl;
      cout << "Arquivo criado com sucesso" << endl;
    }
    break;

    /*Alterar arquivo de matrizes*/
    case 18:
    {
      string filename;
      char option;
      cout << "Digite o nome do arquivo a ser lido: ";
      cin >> filename;

      cout << "Voce deseja sobrescrever o arquivo? (y/n). Se nao, sera adicionado ao fim do arquivo existente" << endl;
      cin >> option;

      if (getUserOption(option) == -1)
      {
        cout << "Opcao invalida" << endl;
        break;
      }
      bool appends = getUserOption(option) == 0 ? true : false;

      matrixList.readFile(filename, appends);
      matrixList.save("matrix.txt");

      cout << endl;
      cout << "Arquivo alterado com sucesso" << endl;
    }
    break;

    /*Zera lista*/
    case 19:
    {
      matrixList.clear();
      matrixList.save("matrix.txt");

      cout << endl;
      cout << "Arquivo zerado com sucesso" << endl;
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
