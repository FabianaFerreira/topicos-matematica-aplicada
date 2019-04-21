/* ---------------------------------------
  Fabiana Ferreira Fonseca
  Universidade Federal do Rio de Janeiro
  DRE: 115037241
----------------------------------------*/

#include "functions.h"

/*Funcao que faz o parser de string atraves de um delimiter*/
vector<float> getNumbersFromInput(string str, char delimiter)
{
  vector<float> tokenVector;
  stringstream ss(str);
  string token;
  while (getline(ss, token, delimiter))
  {
    tokenVector.push_back(stof(token));
  }

  return tokenVector;
}

string decimalToBinary(unsigned n)
{
  string r;
  unsigned counter = 1;
  unsigned length = 0;
  while (n != 0)
  {
    r = (n % 2 == 0 ? "0" : "1") + r;
    n /= 2;

    counter++;
  }

  length = r.length();

  if (length != 8)
  {
    for (unsigned i = 0; i < 8 - length; i++)
    {
      r = "0" + r;
    }
  }
  //Inserindo espaço entre os primeiros 4 bits e o resto
  r.insert(4, " ");
  return r;
}

int printAsciiTable(unsigned begin, unsigned end, unsigned linesQnt)
{
  unsigned pagesQnt = (end - begin + 1) / linesQnt;
  unsigned counter1 = 0;
  unsigned counter2 = begin;
  unsigned currentNumber = begin;

  cout << begin << "," << end << "," << linesQnt << "," << pagesQnt << endl;

  if (begin > end)
    return -1;

  if (begin < 32)
    begin = 32;
  if (end > 127)
    end = 127;

  while (counter1 < pagesQnt)
  {
    cout << "+-----------+-----+-----+-----+-----+" << endl;
    cout << "|  Binário  | Oct | Hex | Dec | Chr |" << endl;
    cout << "+-----------+-----+-----+-----+-----+" << endl;

    while (counter2 <= (currentNumber + linesQnt - 1))
    {
      cout << "| " << decimalToBinary(counter2) << " | " << setw(3) << setbase(8) << setprecision(3) << counter2 << " | " << setw(3) << setbase(16) << counter2 << " | " << setw(3) << setbase(10) << setprecision(3) << counter2 << " | " << setw(3) << char(counter2) << " | " << endl;

      counter2++;
    }
    cout << "+-----------+-----+-----+-----+-----+" << endl;
    cout << endl;
    currentNumber = counter2;
    counter1++;
  }
  return 0;
}

/*Funcao para printar o menu*/
void printMenu()
{
  cout << "Digite 1 para tabela ASCII" << endl;
  cout << "Digite 'exit' para sair do programa" << endl;
}
