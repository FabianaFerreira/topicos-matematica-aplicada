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

  printMenu();

  cout << endl;

  lista.readFile("teste.txt");

  while (input.compare("exit") != 0)
  {
    cout << "Digite uma opcao: ";
    getline(cin, input);

    /*INSERIR ALUNO*/
    if (input == "1")
    {
      string name, dre, course;
      unsigned semester;
      cout << "Digite o nome do aluno (nome e sobrenome): ";
      getline(cin, name);

      cout << "Digite o DRE do aluno : ";
      cin >> dre;

      cout << "Qual o curso? ";
      cin >> course;

      cout << "Qual o periodo atual do aluno? ";
      cin >> semester;

      cout << "nome : " << name << endl;

      Aluno *student = new Aluno(dre, name, course, semester);

      lista.insert(dre, student);
      cin.ignore();
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

    /*ALTERAR DADOS DOS ALUNOS*/
    else if (input == "3")
    {
      string dreToChange;
      unsigned option, exam;

      cout << "Digite 0 para alterar notas ou 1 para alterar frequencia: ";
      cin >> option;
      cin.ignore();

      if (option != 0 && option != 1)
      {
        cout << "Opcao invalida. Tente novamente" << endl;
        break;
      }

      // Copy constructor
      vector<Aluno *> students(lista.getAllStudents());

      if (option == 0)
      {
        float grade;
        cout << "Qual nota deseja alterar? 1 para P1, 2 para P2, 3 para PF e 4 para 2a chamada: ";
        cin >> exam;

        if (exam > 4 || exam < 0)
        {
          cout << "Opcao invalida. Tente novamente" << endl;
          break;
        }
      }

      for (auto student : students)
      {
        cout << "-- Aluno: " << student->getName() << " DRE: " << student->getDre() << " --" << endl;
        string placeholder = option == 0 ? "nota" : "frequencia";
        float value;
        cout << "Digite a " << placeholder << ": ";

        cin >> value;

        if (value < 0)
        {
          cout << "Valor de " << placeholder << " invalido." << endl;
          break;
        }
        option == 0 ? student->setGrade(exam - 1, value) : student->setFrequency(value);
      }
      cout << "Alteracoes feitas com sucesso" << endl;
      cin.ignore();
    }

    /*REMOVER ALUNO*/
    else if (input == "4")
    {
      string dreToRemove;
      cout << "Digite o DRE do aluno a ser removido: ";
      getline(cin, dreToRemove);

      lista.remove(dreToRemove);
      cout << "Aluno removido com sucesso" << endl;
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
      cout << "Arquivo criado com sucesso" << endl;
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
