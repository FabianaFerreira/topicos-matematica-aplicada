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

float calculateMode(std::vector<float> v)
{
  float number = v.at(0);
  float mode = number;
  int count = 1;
  int countMode = 1;

  for (int i = 1; i < v.size(); i++)
  {
    if (v.at(i) == number)
    { // count occurrences of the current number
      ++count;
    }
    else
    { // now this is a different number
      if (count > countMode)
      {
        countMode = count; // mode is the biggest ocurrences
        mode = number;
      }
      count = 1; // reset count for the new number
      number = v.at(i);
    }
  }
  return mode;
}
