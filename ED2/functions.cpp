/* ---------------------------------------
  Fabiana Ferreira Fonseca
  Universidade Federal do Rio de Janeiro
  DRE: 115037241
----------------------------------------*/

#include "functions.h"

/*Funcao que faz o parser de string atraves de um delimiter*/
std::vector<float> getNumbersFromInput(std::string str, char delimiter)
{
  std::vector<float> tokenVector;
  std::stringstream ss(str);
  std::string token;
  while (getline(ss, token, delimiter))
  {
    tokenVector.push_back(stof(token));
  }

  return tokenVector;
}

int getUserOption(std::string option)
{
  if (option.compare("y") == 0)
    return 1;
  if (option.compare("n") == 0)
    return 0;
  return -1;
}

std::vector<float> getVectorFromUser(bool isFirst)
{
  std::string values;
  std::string whichVector = isFirst ? "primeiro" : "segundo";
  std::cout << "Digite as coordenadas do " << whichVector << " vetor separados por espaço: ";
  getline(std::cin, values);
  std::vector<float> vector = getNumbersFromInput(values, ' ');

  return vector;
}

/*Funcao para printar o menu*/
void printMenu()
{
  std::cout << "-------- Calculadora Vetorial --------" << std::endl;
  std::cout << "**-- Operações --**" << std::endl;
  std::cout << "1. Soma ou subtração matricial" << std::endl;
  std::cout << "2. Multiplicação por escalar " << std::endl;
  std::cout << "3. Multiplicação de duas matrizes " << std::endl;
  std::cout << "4. Transposição" << std::endl;
  std::cout << "5. Permutação de linhas ou colunas" << std::endl;
  std::cout << "6. Soma de duas linhas ou duas colunas" << std::endl;
  std::cout << "7. Multiplicação de uma linha ou uma coluna por um escalar" << std::endl;
  std::cout << "8. Inversão de matriz" << std::endl;
  std::cout << "9. Combinação linear" << std::endl;
  std::cout << "10. Escalonamento" << std::endl;
  std::cout << "11. Resolução de sistemas lineares" << std::endl;
  std::cout << "Digite 'exit' para sair do programa" << std::endl;
}
