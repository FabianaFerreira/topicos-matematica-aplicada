/* ---------------------------------------
  Fabiana Ferreira Fonseca
  Universidade Federal do Rio de Janeiro
  DRE: 115037241
----------------------------------------*/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

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

void printMenu();

float calculateMean(std::vector<float>);

float calculateMedian(std::vector<float>);

float calculateMode(std::vector<float>);

float calculateVariance(std::vector<float>, float);

#endif