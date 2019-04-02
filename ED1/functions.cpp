/* ---------------------------------------
  Fabiana Ferreira Fonseca
  Universidade Federal do Rio de Janeiro
  DRE: 115037241
----------------------------------------*/

#include "functions.h"

/*Funcao que faz o parser de string atraves de um delimiter*/
std::vector<float> getNumbersFromInput(std::string str, char delimiter) {
    std::vector<float> tokenVector;
    std::stringstream ss(str);
    std::string token;
    while (getline(ss, token, delimiter))
    {
        tokenVector.push_back(stof(token));
    }

    return tokenVector;
}

/*Funcao para printar o menu*/
void printMenu () {
    std::cout << "-------- Calculadora Vetorial --------" << std::endl;
    std::cout << "**-- Operações --**" << std::endl;
    std::cout << "1. Soma vetorial" << std::endl;
    std::cout << "2. Multiplicação por escalar " << std::endl;
    std::cout << "3. Combinação linear de dois vetores " << std::endl;
    std::cout << "4. Produto interno" << std::endl;
    std::cout << "5. Norma vetorial (módulo)" << std::endl;
    std::cout << "6. Distância entre dois vetores" << std::endl;
    std::cout << "7. Ângulo entre dois vetores" << std::endl;
    std::cout << "**-- Opções --**" << std::endl;
    std::cout << "8. Alterar a dimensão dos vetores" << std::endl;
    std::cout << "9. Memorizar o último resultado" << std::endl;
    std::cout << "10. Acumular um resultado vetorial" << std::endl;
}
