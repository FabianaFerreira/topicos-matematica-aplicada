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

Matrix initializeSquareMatrix(unsigned n)
{
  Matrix m;
  for (unsigned i = 0; i < n; i++)
    m.push_back(std::vector<float>(n, 0));

  return m;
}

void createEquationMatrix(Matrix const m, std::vector<float> const b, Matrix &equation, unsigned n)
{
  for (unsigned i = 0; i < n; i++)
  {
    equation.push_back(std::vector<float>(n + 1, 0));
  }

  //Copying matrix to first part of result
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      equation.at(i).at(j) = m[i][j];
    }
  }
  //Putting identity matrix in the last part of matrix
  for (int i = 0; i < n; i++)
  {
    equation[i][n + i] = b.at(i);
  }
}

/*Function to print matrix on the screen*/
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

/*Overloaded function to print matrix*/
void printMatrix(BinaryMatrix matrix)
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

bool fillContour(BinaryMatrix &matrix, unsigned maxLines, unsigned maxColumns, unsigned line, unsigned column)
{

  if (line > maxLines || column > maxColumns)
    return false;

  if (matrix[line][column] == '0')
    return true;

  matrix[line][column] = '0';

  if ((line + 1) < maxLines)
    fillContour(matrix, maxLines, maxColumns, (line + 1), column);

  if ((line - 1) >= 0)
    fillContour(matrix, maxLines, maxColumns, (line - 1), column);

  if ((column + 1) < maxColumns)
    fillContour(matrix, maxLines, maxColumns, line, (column + 1));

  if ((column - 1) >= 0)
    fillContour(matrix, maxLines, maxColumns, line, (column - 1));

  std::cout << std::endl;

  printMatrix(matrix);

  return true;
}

unsigned solveHanoiTower(int n, char from, char to, char aux)
{
  if (n == 1)
  {
    std::cout << "Move disk 1 from rod " << from << " to rod " << to << std::endl;
    return 1;
  }
  unsigned qnt1 = solveHanoiTower(n - 1, from, aux, to);
  std::cout << "Move disk " << n << " from rod " << from << " to rod " << to << std::endl;
  unsigned qnt2 = solveHanoiTower(n - 1, aux, to, from);

  return qnt1 + qnt2 + 1;
}

/*Function to print menu on the screen*/
void printMenu()
{
  std::cout << "-------- Lista 4 --------" << std::endl;
  std::cout << "**-- Operações --**" << std::endl;
  std::cout << "1. Armazenar matriz de um arquivo na memória interna do programa" << std::endl;
  std::cout << "2. Torre de Hanoi " << std::endl;
  std::cout << "3. Preenchimento de contorno " << std::endl;
  std::cout << "Digite 'exit' para sair do programa" << std::endl;
  std::cout << std::endl;
}
