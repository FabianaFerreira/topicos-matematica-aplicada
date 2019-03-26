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

}

void sumOddTermsFromFibonacci (std::string input) {
    
}

void calculateLeastPrimeNumber(std::string input) {

}

void writeNumberInPortuguese (std::string input) {
  
}

/*Funcao para printar o menu*/
void printMenu () {
    std::cout << "Digite 1 para equacao do segundo grau" << std::endl;
    std::cout << "Digite 2 para N primeiros multiplos entre dois numeros" << std::endl;
    std::cout << "Digite 3 para soma de vetores de N coordenadas" << std::endl;
    std::cout << "Digite 4 para a questao dos postos em um raio de X km" << std::endl;
    std::cout << "Digite 'exit' para sair do programa" << std::endl;
}