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
#include "Lista.h"

using namespace std;

int main()
{
  string input;

  Lista lista;

  lista.readFile("teste.txt");

  printMenu();

  cout << endl;

  while (input.compare("exit") != 0)
  {
    cout << "Digite uma opcao: ";
    getline(cin, input);

    /*INSERIR ALUNO*/
    if (input == "1")
    {
    }
    /*CONSULTAR ALUNO*/
    else if (input == "2")
    {
      bool searchByName = false;
      unsigned option;
      string text;
      string key;

      cout << "Voce deseja procurar por DRE ou nome? Digite 0 para DRE e 1 para nome: ";
      cin >> option;
      cin.ignore();

      cout << option << endl;

      // Tests if option is not a valid value
      if (option != 0 && option != 1)
      {
        cout << "Opcao invalida. Tente novamente" << endl;
        break;
      }

      // Uses this variable to customize string that appears to user
      searchByName = option == 1;
      text = option == 1 ? "nome" : "DRE";

      cout << "Digite o " << text << " do aluno a ser consultado: ";
      getline(cin, key);

      // Retrieves the search result
      vector<Aluno *> result = lista.get(key, option);

      // Prints information
      cout << "|" << setw(10) << "Nome"
           << "|" << setw(10) << "DRE"
           << "|" << setw(10) << "Curso"
           << "|" << setw(8) << "Periodo"
           << "|" << endl;

      for (auto const &aluno : result)
      {
        aluno->printData();
      }
    }

    /*ALTERAR DADOS DO ALUNO*/
    else if (input == "3")
    {
      string dreToChange;
      cout << "Digite o DRE do aluno a ser alterado: ";
      getline(cin, dreToChange);
    }

    /*REMOVER ALUNO*/
    else if (input == "4")
    {
      string dreToRemove;
      cout << "Digite o DRE do aluno a ser removido: ";
      getline(cin, dreToRemove);

      lista.remove(dreToRemove);
    }

    /*LISTAR ALUNOS*/
    else if (input == "5")
    {
      lista.list();
    }

    /*SALVAR EM ARQUIVO*/
    else if (input == "6")
    {
      string filename;
      cout << "Digite o nome do arquivo a ser usado (.txt): ";
      getline(cin, filename);

      lista.save(filename);
    }

    else if (input.compare("exit") != 0)
    {
      cout << "Digite uma opcao valida" << endl;
    }

    cout << endl;
  }

  // cout << "Obrigada por testar!" << endl;

  return 0;
}
