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
int main () {
  string input;

  printMenu();

  cout << endl;

  while (input.compare("exit") != 0) {
      cout << "Digite uma opcao: ";
      getline (cin,input);
      if (input == "1") {
        cout << "Digite um numero (n) para ter os digitos de 2^n somados: ";
        getline(cin,input);
        sumDigitsFromPow(input);
      }
      else if (input == "2") {
        cout << "Digite a ordem do termo Fibonacci a ser calculado para somar os termos impares: ";
        getline(cin, input);
        sumOddTermsFromFibonacci(input);
      }
      else if (input == "3") {
        cout << "Digite um numero para ter seu maior fator primo calculado: ";
        getline(cin, input);
        calculateLargestPrimeNumber(input);
      }
      else if (input == "4") {
        cout << "Digite um numero de ate cinco casas para ser escrito por extenso: ";
        getline(cin, input);
        writeNumberInPortuguese(input);
      }
      else if (input.compare("exit") != 0){
        cout << "Digite uma opcao valida" << endl;
      }

      cout << endl;
  }

  cout << "Obrigada por testar!" << endl;

  return 0;
}
