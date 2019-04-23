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
#include <sstream>

#include <unistd.h>
#include <sys/wait.h>

#include <string>
#include <functional>
#include <dirent.h>

using namespace std;

vector<float> getNumbersFromInput(string, char);

string decimalToBinary(unsigned long);

int printAsciiTable(unsigned, unsigned, unsigned);

int printUnicodeTable(unsigned, unsigned, unsigned);

void GetReqDirs(const string &, vector<string> &, const bool);

vector<string> generateFilesList(string);

void printMenu();
