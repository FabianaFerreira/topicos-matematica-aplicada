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

  Aluno aluno1("Fabiana", "114037241", "Eletronica", 9);
  Aluno aluno4("Fabiana", "110037241", "Farmacia", 4);
  Aluno aluno2("Lucas", "113037241", "Eletronica", 1);
  Aluno aluno3("Tamine", "112037241", "Eletronica", 2);

  lista.insert(aluno1.getDre(), aluno1);
  lista.insert(aluno2.getDre(), aluno2);
  lista.insert(aluno3.getDre(), aluno3);
  lista.insert(aluno4.getDre(), aluno4);

  lista.list();

  lista.save("teste.txt");

  std::vector<Aluno> result(lista.get("Fabiana", 1));

  cout << "Tamanho do array: " << result.size() << endl;

  // printMenu();

  // cout << endl;

  // while (input.compare("exit") != 0)
  // {
  //   cout << "Digite uma opcao: ";
  //   getline(cin, input);
  //   if (input == "1")
  //   {

  //   }
  //   else if (input == "2")
  //   {

  //   }
  //   else if (input == "3")
  //   {

  //   }
  //   else if (input == "4")
  //   {

  //   }
  //   else if (input.compare("exit") != 0)
  //   {
  //     cout << "Digite uma opcao valida" << endl;
  //   }

  //   cout << endl;
  // }

  // cout << "Obrigada por testar!" << endl;

  return 0;
}
