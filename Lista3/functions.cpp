/* ---------------------------------------
  Fabiana Ferreira Fonseca
  Universidade Federal do Rio de Janeiro
  DRE: 115037241
----------------------------------------*/

#include "functions.h"

#define BUFFER 100

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

/*Funcao que converte decimal para binario e insere um espaco no meio do binario*/
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

  if (length % 2 != 0)
  {
    unsigned mod = length % 2;
    for (unsigned i = 0; i < mod; i++)
    {
      r = "0" + r;
    }
  }
  // Inserindo espaço entre os primeiros 4 bits e o resto
  r.insert((r.length() / 2), " ");
  return r;
}

/*Funcao que printa a tabela ascii dados um inicio e um fim*/
int printAsciiTable(unsigned begin, unsigned end, unsigned linesQnt)
{
  unsigned totalLines = end - begin + 1;
  unsigned pagesQnt = ceil((float)totalLines / linesQnt);
  unsigned pageCounter = 0;
  unsigned linesPerPageCounter = begin;
  unsigned currentNumber = begin;

  if (begin > end)
    return -1;

  if (begin < 32)
    begin = 32;
  if (end > 127)
    end = 127;

  unsigned loopLimit;

  while (pageCounter < pagesQnt)
  {
    cout << "+---------------+-----+-----+-----+-----+" << endl;
    cout << "|    Binário    | Oct | Hex | Dec | Chr |" << endl;
    cout << "+---------------+-----+-----+-----+-----+" << endl;
    linesPerPageCounter = 0;
    if (totalLines - pageCounter * linesQnt < linesQnt)
      loopLimit = totalLines - pageCounter * linesQnt;
    else
      loopLimit = linesQnt;

    while (linesPerPageCounter < loopLimit)
    {
      currentNumber = begin + linesQnt * pageCounter + linesPerPageCounter;
      cout << "| " << decimalToBinary(currentNumber) << " | "
           << setw(3) << setbase(8) << setprecision(3)
           << currentNumber << " | " << setw(3)
           << setbase(16) << currentNumber << " | " << setw(3)
           << setbase(10) << setprecision(3) << currentNumber
           << " | " << setw(3) << char(currentNumber) << " | " << endl;

      linesPerPageCounter++;
    }
    cout << "+-----------+-----+-----+-----+-----+" << endl;
    cout << endl;

    pageCounter++;
  }
  return 0;
}

/*Funcao que printa a tabela unicode dados um inicio e um fim e tambem a lingua*/
int printUnicodeTable(unsigned begin, unsigned end, unsigned linesQnt)
{
  unsigned totalLines = end - begin + 1;
  unsigned pagesQnt = ceil((float)totalLines / linesQnt);
  unsigned pageCounter = 0;
  unsigned linesPerPageCounter;
  unsigned currentNumber = begin;

  if (begin > end)
    return -1;

  // if (begin < 32)
  //   begin = 32;
  // if (end > 127)
  //   end = 127;

  unsigned loopLimit;

  while (pageCounter < pagesQnt)
  {
    if (currentNumber > 10000)
    {
      cout << "+-----------------+-------+------+-------+-----+" << endl;
      cout << "|     Binário     |  Oct  |  Hex |  Dec  | Chr |" << endl;
      cout << "+-----------------+-------+------+-------+-----+" << endl;
    }
    else
    {
      cout << "+---------------+-----+-----+-----+-----+" << endl;
      cout << "|    Binário    | Oct | Hex | Dec | Chr |" << endl;
      cout << "+---------------+-----+-----+-----+-----+" << endl;
    }

    linesPerPageCounter = 0;
    if (totalLines - pageCounter * linesQnt < linesQnt)
      loopLimit = totalLines - pageCounter * linesQnt;
    else
      loopLimit = linesQnt;

    while (linesPerPageCounter < loopLimit)
    {
      currentNumber = begin + linesQnt * pageCounter + linesPerPageCounter;

      cout << "| " << decimalToBinary(currentNumber) << " | "
           << setw(3) << setbase(8) << setprecision(3) << currentNumber << " | "
           << setw(3) << setbase(16) << currentNumber
           << " | " << setw(3) << setbase(10) << setprecision(3) << currentNumber << " | ";

      /*Quantidade de bytes vai depender do numero de decimais a serem representados*/
      if (currentNumber < 10000)
      {
        /*Caractere unicode com operadores bitwise*/
        char byte1 = 0xc0 | ((currentNumber & 0x7c0) >> 6); // 206
        char byte2 = 0x80 | (currentNumber & 0x3f);         // 177
        printf("%c%c | \n", byte1, byte2);
      }
      else
      {
        /*Caractere unicode com operadores bitwise*/
        char byte1 = 0xe0 | ((currentNumber >> 12) & 0x0f);
        char byte2 = 0x80 | ((currentNumber >> 6) & 0x3f);
        char byte3 = 0x80 | (currentNumber & 0x3f);
        printf(" %c%c%c  | \n", byte1, byte2, byte3);
      }
      linesPerPageCounter++;
    }
    if (currentNumber > 10000)
    {
      cout << "+-----------------+-------+------+-------+-----+" << endl;
      cout << endl;
    }
    else
    {
      cout << "+---------------+-----+-----+-----+-----+" << endl;
      cout << endl;
    }

    pageCounter++;
  }
  return 0;
}

vector<string> generateFilesList(string path)
{
  char commandList[BUFFER * 20];
  int pipefd[2];
  string token, list;
  vector<string> files;

  /*Faço uma chamada de execlp para listar os comandos que estão na
	pasta bin, de forma a conseguir tratar o erro, caso o usuário entre
	com um comando que não está na pasta*/

  pipe(pipefd);
  pid_t dirPathPID = fork();
  if (dirPathPID == 0)
  {
    //Fecha o lado de entrada do pipe (do filho)
    close(pipefd[0]);

    dup2(pipefd[1], fileno(stdout));
    close(pipefd[1]);

    execlp("/bin/dir", "dir", "-1", path.c_str(), NULL);
  }
  else
  {
    wait(NULL);
    close(pipefd[1]);
    while (read(pipefd[0], commandList, sizeof(commandList)) != 0)
    {
    }
  }

  list = string(commandList);

  // Removendo ultimo \n
  list.pop_back();

  istringstream filesStream(commandList);

  while (getline(filesStream, token, '\n'))
  {
    files.push_back(token);
  }

  return files;
}

/*Funcao para printar o menu*/
void printMenu()
{
  cout << "Digite 1 para tabela ASCII" << endl;
  cout << "Digite 2 para tabela Unicode" << endl;
  cout << "Digite 3 para contagem de palavras em uma arquivo .txt" << endl;
  cout << "Digite 'exit' para sair do programa" << endl;
}
