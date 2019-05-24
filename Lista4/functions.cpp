/* ---------------------------------------
  Fabiana Ferreira Fonseca
  Universidade Federal do Rio de Janeiro
  DRE: 115037241
----------------------------------------*/
#include "functions.h"

/*Funcao que faz o parser de string atraves de um delimiter*/
std::vector<unsigned> getNumbersFromString(std::string str)
{
  std::vector<unsigned> result;
  std::stringstream ss;

  /* Storing the whole string into string stream */
  ss << str;

  /* Running loop till the end of the stream */
  std::string temp;
  unsigned number;
  while (!ss.eof())
  {

    /* extracting word by word from stream */
    ss >> temp;

    /* Checking the given word is integer or not */
    if (std::stringstream(temp) >> number)
    {
      result.push_back(number);
    }
  }
  return result;
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

unsigned getFileLinesQuantity(std::string filename)
{
  std::ifstream f;
  std::string line;
  unsigned linesCounter = 0;

  f.open(filename);

  while (std::getline(f, line))
  {
    linesCounter++;
  }

  f.close();

  return linesCounter;
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

void fillContour2(BinaryMatrix &matrix, unsigned maxLines, unsigned maxColumns, unsigned line, unsigned column)
{ 
  int currentLine = line;
  int currentColumn = column;
  int nextLine, nextColumn;

  bool stop = false; // stop from moving diagonally
  bool switched = false; // switched from going down diagonally

  bool zeroAbove, zeroBelow, zeroLeft, zeroRight;
  // Get the biggest amount of offset from the line x column selected that is enough
  // to go through all the elements.
  unsigned maxOffsetLine;
  unsigned maxOffsetColumn;
  unsigned maxOffset;

  // Pile of (line, column) to fill with 0
  std::vector<std::pair<int, int>> pile;

  // Nothing to paint
  if (matrix[line][column] == '0')
    return;

  while (!stop)
  {
    maxOffsetLine = std::max((unsigned) currentLine, maxLines - line - 1);
    maxOffsetColumn = std::max((unsigned) currentColumn, maxColumns - column - 1);
    maxOffset = std::max(maxOffsetLine, maxOffsetColumn);

    // Reset the flags
    zeroAbove = false;
    zeroBelow = false;
    zeroLeft = false;
    zeroRight = false;

    if (matrix[currentLine][currentColumn] == '1')
      pile.push_back(std::make_pair(currentLine, currentColumn));

    // Painting in a cross shape
    for (unsigned offset=1; offset <= maxOffset; offset++)
    {
      // Element above
      nextLine = (int) (currentLine - offset);
      if ((nextLine >= 0) && (matrix[nextLine][currentColumn] == '1') && !zeroAbove)
        pile.push_back(std::make_pair(nextLine, currentColumn));
      else if ((nextLine >= 0) && (matrix[nextLine][currentColumn] == '0'))
        zeroAbove = !zeroAbove;
      
      // Element below
      nextLine = currentLine + offset;
      if ((nextLine < maxLines) && (matrix[nextLine][currentColumn] == '1') && !zeroBelow)
        pile.push_back(std::make_pair(nextLine, currentColumn));
      else if ((nextLine < maxLines) && (matrix[nextLine][currentColumn] == '0'))
        zeroBelow = !zeroBelow;

      // Element to the left
      nextColumn = (int) (currentColumn - offset);
      if ((nextColumn >= 0) && (matrix[currentLine][nextColumn] == '1') && !zeroLeft)
        pile.push_back(std::make_pair(currentLine, nextColumn));
      else if ((nextColumn >= 0) && (matrix[currentLine][nextColumn] == '0'))
        zeroLeft = !zeroLeft;

      // Element to the right
      nextColumn = currentColumn + offset;
      if ((nextColumn < maxColumns) && (matrix[currentLine][nextColumn] == '1') && !zeroRight)
        pile.push_back(std::make_pair(currentLine, nextColumn));
      else if ((nextColumn < maxColumns) && (matrix[currentLine][nextColumn] == '0'))
        zeroRight = !zeroRight;
    }

    // Go down-right diagonally
    if (!switched)
    {
      currentLine ++; currentColumn++;
    }
    // Go up-left diagonally
    else
    {
      currentLine --; currentColumn--;
    }

    if (!switched && (matrix[currentLine][currentColumn] == '0' || currentLine >= maxLines || currentColumn >= maxColumns))
    {
      switched = true;
      currentLine = line - 1;
      currentColumn = column - 1;
    }
    else if (matrix[currentLine][currentColumn] == '0' || currentLine < 0 || currentColumn < 0)
      stop = true;
  }

  for (unsigned i=0; i < pile.size(); i++)
    matrix[pile.at(i).first][pile.at(i).second] = '0';

  printMatrix(matrix);
}

void MoveDisc(Pino &from, Pino &to)
{
  to.push(from.pop());
}

/*Function to sole Hanoi tower*/
unsigned solveHanoiTower(int n, Pino &p1, Pino &p2, Pino &p3)
{
  if (n == 1)
  {
    MoveDisc(p1, p3);
    return 1;
  }
  unsigned qnt1 = solveHanoiTower(n - 1, p1, p3, p2);
  MoveDisc(p1, p3);
  unsigned qnt2 = solveHanoiTower(n - 1, p2, p1, p3);

  return qnt1 + qnt2 + 1;
}

/*Function to print menu on the screen*/
void printMenu()
{
  std::cout << "-------- Lista 4 --------" << std::endl;
  std::cout << "**-- Operações --**" << std::endl;
  std::cout << "1. Armazenar matriz de um arquivo na memória interna do programa" << std::endl;
  std::cout << "2. Torre de Hanoi " << std::endl;
  std::cout << "3. Preenchimento de contorno recursivo" << std::endl;
  std::cout << "4. Preenchimento de contorno iterativo" << std::endl;
  std::cout << "Digite 'exit' para sair do programa" << std::endl;
  std::cout << std::endl;
}
