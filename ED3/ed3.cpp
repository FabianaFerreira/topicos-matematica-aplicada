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
  // Calculator *calculator = new Calculator();
  MatrixList matrixList(filename);

  matrixList.list();

  return 0;

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
      // Matrix m1(matrixList.get(index));

      cout << "Digite o identificador da segunda matriz: ";
      cin >> index;
    }
    break;

    /*Multiplicação por escalar*/
    case 2:
    {
      cout << "Digite o identificador da matriz: ";
      cin >> index;

      //Copy constructor
      // Matrix m(matrixList.get(index));

      string mult;
      cout << "Digite o multiplicador: " << endl;
      cin >> mult;
    }

    break;

    /*Multiplicação matricial*/
    case 3:
    {
      cout << "Digite o identificador da primeira matriz: ";
      cin >> index;

      //Copy constructor
      // Matrix m1(matrixList.get(index));

      cout << "Digite o identificador da segunda matriz: " << endl;
      cin >> index;
    }
    break;

    /*Transposição*/
    case 4:
    {
      cout << "Digite o identificador da matriz: ";
      cin >> index;
    }
    break;

      /*Imprimir uma ou mais matrizes da lista*/
    case 5:
    {
      std::string id;
      cout << "Digite o(s) identificador(es) da(s) matriz(es) a ser(em) listada(s) separados por espaco: ";
      getline(std::cin, id);
      vector<string> identifiers(parseInput(id, ' '));
      // for (unsigned i = 0; i < identifiers.size(); i++)
      // {
      //   char ident = identifiers.at(i).c_str()[0];
      //   cout << "** Matrix " << ident << " **" << endl;
      //   printMatrix(matrixList.get(ident));
      //   cout << endl;
      // }
    }
    break;

    /*Inserir matriz qualquer*/
    case 6:
    {
      cout << "Digite uma letra para identificar a nova matriz: ";
      cin >> index;
      cin.ignore();
      // Matrix newMatrix = getMatrixFromUser();
      // matrixList.insert(index, newMatrix);

      // cout << endl;
      // cout << "Lista alterada com sucesso!" << endl;
      // ;
      // cout << endl;

      // cout << "** -- Lista atual -- **" << endl;
      // matrixList.list();
      // cout << "** ----------------- **" << endl;
      // cout << endl;
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

      // matrixList.insertIdentity(identifier, dimension);
      // matrixList.list();
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

      // for (unsigned i = 0; i < identifiers.size(); i++)
      // {
      //   char ident = identifiers.at(i).c_str()[0];
      //   cout << "Voce deseja alterar a matriz " << ident << "? (y/n). Se nao, voce ira remove-la. ";
      //   cin >> option;

      //   if (getUserOption(option) == -1)
      //   {
      //     cout << "Opcao invalida" << endl;
      //     break;
      //   }
      //   removes = getUserOption(option) == 0 ? true : false;

      //   if (removes)
      //   {
      //     matrixList.remove(ident);
      //     cout << "Matriz " << ident << " removida com sucesso!" << endl;
      //     matrixList.save(filename);
      //   }
      //   else
      //   {
      //     cout << "Voce optou por alterar a matriz " << ident << "." << endl;
      //     cout << endl;
      //     Matrix newMatrix(getMatrixFromUser());
      //     matrixList.insert(ident, newMatrix);
      //     matrixList.save(filename);
      //   }
      //   cout << endl;
      // }

      // cout << endl
      //      << "Lista alterada com sucesso!" << endl;
      // cout << endl;
      // matrixList.list();
      // cin.ignore();
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
