/* ---------------------------------------
  Fabiana Ferreira Fonseca
  Universidade Federal do Rio de Janeiro
  DRE: 115037241
----------------------------------------*/

#include <string>
#include <vector>
#include <sstream>
#include <math.h>
#include <string.h>
#include <iostream>
#include <iomanip>

using namespace std;

vector<float> getNumbersFromInput(std::string, char);

string decimalToBinary(unsigned);

/*Definindo valores padrão para as variaveis*/
// void printAsciiTable(short int = 32, unsigned short = 127, unsigned = 25);
int printAsciiTable(unsigned, unsigned, unsigned);

void printMenu();
