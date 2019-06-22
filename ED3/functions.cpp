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

/*Funcao que faz o parser de string atraves de um delimiter*/
std::vector<std::string> parseInput(std::string str, char delimiter)
{
  std::vector<std::string> tokenVector;
  std::stringstream ss(str);
  std::string token;
  while (getline(ss, token, delimiter))
  {
    tokenVector.push_back(token);
  }

  return tokenVector;
}

int getUserOption(char option)
{
  if (option == 'y')
    return 1;
  if (option == 'n')
    return 0;
  return -1;
}

TypeMatrix getMatrixFromUser(unsigned lines, unsigned columns)
{
  TypeMatrix result;
  std::string values;
  // unsigned lines, columns;

  for (int i = 0; i < lines; i++)
  {
    std::cout << "Digite os elementos da linha " << (i + 1) << " separados por espaço: ";
    getline(std::cin, values);
    std::vector<float> line = getNumbersFromInput(values, ' ');
    if (line.size() != columns)
    {
      std::cout << "ERRO: Quantidade de elementos diferente do numero de colunas" << std::endl;
      exit(1);
    }
    result.push_back(line);
  }

  return result;
}

/*Function to print matrix on the screen*/
void printMatrix(TypeMatrix matrix)
{
  unsigned lines = matrix.size();
  unsigned columns = matrix[0].size();
  for (unsigned i = 0; i < lines; i++)
  {
    std::cout << "[ ";
    for (unsigned j = 0; j < columns; j++)
    {
      std::cout << matrix.at(i).at(j) << " ";
    }
    std::cout << "]";
    std::cout << std::endl;
  }
}

/*Function to print menu on the screen*/
void printMenu()
{
  std::cout << "-------- Calculadora Vetorial --------" << std::endl;
  std::cout << "**-- Operações --**" << std::endl;
  std::cout << "1. Soma ou subtração matricial" << std::endl;
  std::cout << "2. Multiplicação por escalar " << std::endl;
  std::cout << "3. Multiplicação de duas matrizes " << std::endl;
  std::cout << "4. Transposição" << std::endl;
  std::cout << "5. Determinante de uma matriz triangular" << std::endl;
  std::cout << "6. Traco de uma matriz quadrada" << std::endl;
  std::cout << "**-- Opções --**" << std::endl;
  std::cout << "7. Imprimir uma ou mais matrizes da lista" << std::endl;
  std::cout << "8. Inserir uma nova matriz" << std::endl;
  std::cout << "9. Inserir uma matriz identidade n x n" << std::endl;
  std::cout << "10. Alterar ou remover uma ou mais matrizes da lista" << std::endl;
  std::cout << "11. Listar todas as matrizes da lista" << std::endl;
  std::cout << "12. Fazer um backup da lista" << std::endl;
  std::cout << "13. Ler uma outra lista de matrizes (adicionar à existente ou substituir)" << std::endl;
  std::cout << "14. Zerar a lista de matrizes" << std::endl;
  std::cout << "Digite 'exit' para sair do programa" << std::endl;
  std::cout << std::endl;
}
