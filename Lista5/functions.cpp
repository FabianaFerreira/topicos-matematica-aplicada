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
  cout << "Digite 1 para inserir um novo aluno" << endl;
  cout << "Digite 2 para consultar informacoes de um aluno" << endl;
  cout << "Digite 3 para alterar as informacoes de um aluno" << endl;
  cout << "Digite 4 para remover um aluno da lista" << endl;
  cout << "Digite 5 para listar alunos" << endl;
  cout << "Digite 6 salvar lista em um arquivo" << endl;
  cout << "Digite 'exit' para sair do programa" << endl;
}
