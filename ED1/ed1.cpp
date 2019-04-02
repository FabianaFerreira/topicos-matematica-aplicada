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
#include <time.h>
#include <stdio.h>
#include "functions.h"
#include "ClasseCalculadora.h"

using namespace std;

/*--------------------------------------------- MAIN -------------------------------------------------------*/
int main () {
  string input;
  //setando o seed
  srand(time(NULL));

  printMenu();

  cout << endl;

  while (input.compare("exit") != 0) {
    cout << "Digite uma opcao: ";
    getline (cin,input);

    switch (atoi(input.c_str()))
    {
     case 1:
       cout << input << endl;
       break;

     case 2:
       cout << input << endl;
       break;

     case 3:
       cout << input << endl;
       break;

     case 4:
       cout << input << endl;
       break;

     case 5:
       cout << input << endl;
       break;

     case 6:
       cout << input << endl;
       break;

     case 7:
       cout << input << endl;
       break;

     case 8:
       cout << input << endl;
       break;

     case 9:
       cout << input << endl;
       break;

     case 10:
       cout << input << endl;
       break;
    }
    cout << "Opcao invalida. Por favor, tente novamente." << endl;
  }
  cout << "Obrigada por testar!" << endl;

  return 0;
}
