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
#include <dirent.h>
#include <map>
#include <fstream>

std::vector<float> getNumbersFromInput(std::string, char);

std::vector<std::string> getStringsFromLine(std::string, char);

std::string decimalToBinary(unsigned long);

int printAsciiTable(unsigned, unsigned, unsigned);

int printUnicodeTable(unsigned, unsigned, unsigned);

std::string getFileExtension(const std::string);

bool getFilesList(const std::string &, std::vector<std::string> &, const bool);

void generateWordsFile(std::vector<std::string>);

void writeResultFile(std::map<std::string, unsigned>);

void printMenu();
