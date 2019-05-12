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

int getUserOption(char option)
{
  if (option == 'y')
    return 1;
  if (option == 'n')
    return 0;
  return -1;
}

Matrix getMatrixFromUser()
{
  Matrix result;
  std::string values;
  unsigned lines, columns;

  std::cout << "Digite a quantidade de linhas da matriz: ";
  std::cin >> lines;
  std::cin.ignore();
  std::cout << lines << " linhas" << std::endl;

  std::cout << "Digite a quantidade de colunas da matriz: ";
  std::cin >> columns;
  std::cin.ignore();
  std::cout << columns << " colunas" << std::endl;

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

void printMatrix(Matrix matrix)
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

void printMatrix(Matrix matrix, unsigned lineLimit, unsigned columnLimit)
{
  for (unsigned i = 0; i < lineLimit; i++)
  {
    std::cout << "[ ";
    for (unsigned j = 0; j < columnLimit; j++)
    {
      std::cout << matrix.at(i).at(lineLimit + j) << " ";
    }
    std::cout << "]";
    std::cout << std::endl;
  }
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
  std::cout << "**-- Opções --**" << std::endl;
  std::cout << "12. Imprimir uma ou mais matrizes da lista" << std::endl;
  std::cout << "13. Inserir uma nova matriz" << std::endl;
  std::cout << "14. Inserir uma matriz identidade n x n" << std::endl;
  std::cout << "15. Alterar ou remover uma ou mais matrizes da lista" << std::endl;
  std::cout << "16. Listar todas as matrizes da lista" << std::endl;
  std::cout << "17. Fazer um backup da lista" << std::endl;
  std::cout << "18. Ler uma outra lista de matrizes (adicionar à existente ou substituir)" << std::endl;
  std::cout << "19. Zerar a lista de matrizes" << std::endl;
  std::cout << "Digite 'exit' para sair do programa" << std::endl;
}
