/* ---------------------------------------
  Fabiana Ferreira Fonseca
  Universidade Federal do Rio de Janeiro
  DRE: 115037241
----------------------------------------*/

#include "functions.h"

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

/*Function that show the user menu*/
void printMenu()
{
  cout << "Digite 1 para listar alunos em ordem crescente de nome" << endl;
  cout << "Digite 2 para listar alunos em ordem decrescente de nota" << endl;
  cout << "Digite 3 para listar alunos que fizeram determinada prova" << endl;
  cout << "Digite 4 para listar alunos em ordem decrescente de notas e medias" << endl;
  cout << "Digite 5 para calcular media, moda, mediana, variancia e desvio padrao" << endl;
  cout << "Digite 6 para listar alunos em PF ou 2a chamada" << endl;
  cout << "Digite 7 para listar alunos com media final acima de 7.9" << endl;
  cout << "Digite 6 salvar listar alunos aprovados" << endl;
  cout << "Digite 6 salvar listar alunos aprovados" << endl;
  cout << "Digite 'exit' para sair do programa" << endl;
}

float calculateMean(std::vector<float> v)
{
  // Tests the case of not having at least one grade in vector (there
  // were no students that did the exam)
  unsigned size = v.size();
  if (size == 0)
    return -1;

  float sum = 0;
  for (unsigned i = 0; i < size; i++)
    sum += v.at(i);

  return sum / size;
}

float calculateMedian(std::vector<float> v)
{
  // Tests the case of not having at least one grade in vector (there
  // were no students that did the exam)
  unsigned size = v.size();
  if (size == 0)
  {
    return -1;
  }
  if (size % 2 == 0)
  {
    return (v.at(size / 2 - 1) + v.at(size / 2)) / 2;
  }
  return v.at(size / 2);
}

float calculateMode(std::vector<float> v)
{
  // Tests the case of not having at least one grade in vector (there
  // were no students that did the exam)
  if (v.size() == 0)
  {
    return -1;
  }

  float number = v.at(0);
  float mode = number;
  int count = 1;
  int countMode = 1;

  for (int i = 1; i < v.size(); i++)
  {
    if (v.at(i) == number)
      ++count;
    else
    {
      if (count > countMode)
      {
        countMode = count;
        mode = number;
      }
      count = 1;
      number = v.at(i);
    }
  }
  return mode;
}

float calculateVariance(std::vector<float> v, float mean)
{
  unsigned size = v.size();
  if (size == 0)
    return -1;

  float var = 0;
  for (unsigned i = 0; i < size; i++)
  {
    var += pow((v.at(i) - mean), 2);
  }
  var = var / size;
}
