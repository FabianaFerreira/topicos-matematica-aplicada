/* ---------------------------------------
  Fabiana Ferreira Fonseca
  Universidade Federal do Rio de Janeiro
  DRE: 115037241
----------------------------------------*/

#include "functions.h"

#define EXTENSION "txt"
#define RESULTFILENAME "Resultado_Contagem.txt"
#define NOTALLOWEDCHARS "!?.,;"

using namespace std;

/*Function that gets the numbers from a string. It is used to get user options*/
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

/*Function that gets the substrings from a string, given a delimiter. 
  It is used to parse strings from file lines*/
vector<string> getStringsFromLine(string str, char delimiter)
{
  vector<string> tokenVector;
  stringstream ss(str);
  string token;
  while (getline(ss, token, delimiter))
  {
    tokenVector.push_back(token);
  }

  return tokenVector;
}

/*Function that converts decimal number to binary. It also appends a space in the middle of
  the number to format it*/
string decimalToBinary(unsigned long n)
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

/*Function that prints an ASCII table. It has three numbers as parameters: 
  begin and end of the table and also the number of lines per page*/
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

/*Function that prints an unicode table. It has three numbers as parameters: 
  begin and end of the table and also the number of lines per page*/
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

string getFileExtension(const string s)
{

  size_t i = s.rfind('.', s.length());
  if (i != string::npos)
  {
    return (s.substr(i + 1, s.length() - i));
  }

  return ("");
}

bool getFilesList(const string &path, vector<string> &files, const bool showHiddenDirs = false)
{
  DIR *dpdf;
  struct dirent *epdf;
  dpdf = opendir(path.c_str());
  if (dpdf != NULL)
  {
    while ((epdf = readdir(dpdf)) != NULL)
    {
      if (showHiddenDirs ? (epdf->d_type == DT_DIR && string(epdf->d_name) != ".." && string(epdf->d_name) != ".") : (epdf->d_type == DT_DIR && strstr(epdf->d_name, "..") == NULL && strstr(epdf->d_name, ".") == NULL))
      {
        getFilesList(path + "/" + epdf->d_name, files, showHiddenDirs);
      }
      if (epdf->d_type == DT_REG)
      {
        string extension = getFileExtension(string(epdf->d_name));
        if (extension.compare(EXTENSION) == 0)
          files.push_back(path + "/" + epdf->d_name);
      }
    }
    closedir(dpdf);
    return true;
  }
  return false;
}

/*Function that formats string so as to remove dots, comma and etc. 
  It also puts every char in lower case*/
void formatString(string &str)
{
  string excludeChars = NOTALLOWEDCHARS;

  auto writeIter = str.begin();

  for (auto readIter = str.begin(); readIter != str.end(); ++readIter)
  {
    auto chr = *readIter;

    if (excludeChars.find(chr) != string::npos)
      continue;

    *writeIter = tolower((unsigned char)chr);
    ++writeIter;
  }

  str.erase(writeIter, str.end());
}

/*Function that generates the word/counter pairs and writes them in a 
  result file which name is defined as a const*/
void generateWordsFile(vector<string> files)
{
  string currentWord;
  map<string, unsigned> words;

  for (string file : files)
  {
    ifstream input(file);

    for (string line; getline(input, line);)
    {
      formatString(line);
      vector<string> wordsFromLine = getStringsFromLine(line, ' ');
      for (string currentWord : wordsFromLine)
      {
        if (words.find(currentWord) == words.end())
        {
          words.insert(make_pair(currentWord, 1));
        }
        else
        {
          unsigned value = words.at(currentWord);
          words.at(currentWord) = value + 1;
        }
      }
    }
  }
  writeResultFile(words);
}

/*Function that will write all the information in an output file*/
void writeResultFile(map<string, unsigned> words)
{
  fstream fs;
  fs.open(RESULTFILENAME, fstream::out);

  for (auto const pair : words)
  {
    fs << pair.first + ":" + to_string(pair.second) + "\n";
  }

  fs.close();
}

vector<long> getLinesAndColumnsQnt(string filename)
{
  ifstream input(filename);
  long numberOfLines = 0;
  long numberOfColumns = 0;
  vector<long> result;
  for (string line; getline(input, line);)
  {
    if (numberOfLines == 0)
    {
      if (line.find(',') != std::string::npos)
        numberOfColumns = getStringsFromLine(line, ',').size();
      else if (line.find(';') != std::string::npos)
        numberOfColumns = getStringsFromLine(line, ';').size();
    }
    numberOfLines++;
  }
  //Exclui a primeira linha
  numberOfLines--;

  result.push_back(numberOfLines);
  result.push_back(numberOfColumns);

  return result;
}

/*Function that show the user menu*/
void printMenu()
{
  cout << "Digite 1 para tabela ASCII" << endl;
  cout << "Digite 2 para tabela Unicode" << endl;
  cout << "Digite 3 para contagem de palavras em um diretorio" << endl;
  cout << "Digite 4 para contagem de linhas e colunas em um arquivo csv" << endl;
  cout << "Digite 'exit' para sair do programa" << endl;
}
