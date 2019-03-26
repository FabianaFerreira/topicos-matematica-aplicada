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

}

void calculateLeastPrimeNumber(std::string input) {

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
