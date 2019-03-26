/* ---------------------------------------
  Fabiana Ferreira Fonseca
  Universidade Federal do Rio de Janeiro
  DRE: 115037241
----------------------------------------*/

#include "functions.h"

/*Funcao que faz o parser de string atraves de um delimiter*/
std::vector<float> getNumbersFromInput (std::string str, char delimiter) {
    std::vector<float> tokenVector;
    std::stringstream ss(str);
    std::string token;
    while (getline(ss, token, delimiter))
    {
        tokenVector.push_back(stof(token));
    }

    return tokenVector;
}

void sumDigitsFromPow (std::string input) {
    std::vector<float> arg = getNumbersFromInput(input, ' ');
    int number;
    long digitsSum;

    if (arg.size() != 1)
      std::cout << "Quantidade invalida de argumentos" << std::endl;
    else {
      number = pow(2,arg.at(0));
      std::cout << "2^" << arg.at(0) << " = " << number << std::endl;
      while (number != 0) {
          digitsSum = digitsSum + number % 10;
          number = number / 10;
      }
      std::cout << "Soma dos digitos: " << digitsSum << std::endl;
    }
}

void sumOddTermsFromFibonacci (std::string input) {
    std::vector<float> arg = getNumbersFromInput(input, ' ');
    std::vector<long> fiboTerms;
    long long termsSum;
    int index = arg.at(0);

    if (arg.size() != 1 || index < 0)
      std::cout << "Quantidade invalida de argumentos ou valor de n invalido" << std::endl;
    else if (index >= 4E6) {
      std::cout << "Valor de n ultrapassou quatro milhoes";
      return;
    }
    else {
      /*Termos de Fibonacci de indice 0 e 1*/
      fiboTerms.push_back(0);
      fiboTerms.push_back(1);

      termsSum = fiboTerms.at(1);

      for (unsigned i = 2; i < index; i++) {
        fiboTerms.push_back(fiboTerms.at(i - 1) + fiboTerms.at(i - 2));
        /*Se nao for par*/
        if (i % 2 != 0)
          termsSum += fiboTerms.at(i);
      }
      std::cout << "Soma dos termos impares: " << termsSum << std::endl;
    }
}

void calculateLargestPrimeNumber(std::string input) {

}

void writeNumberInPortuguese (std::string input) {

}

/*Funcao para printar o menu*/
void printMenu () {
    std::cout << "Digite 1 para soma dos digitos" << std::endl;
    std::cout << "Digite 2 para soma dos termos impares de Fibonacci" << std::endl;
    std::cout << "Digite 3 para maior fator primo de um numero" << std::endl;
    std::cout << "Digite 4 para escrever por extenso um numero" << std::endl;
    std::cout << "Digite 'exit' para sair do programa" << std::endl;
}
