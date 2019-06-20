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
#include <iostream>
#include <math.h>

#include "types.h"

std::vector<float> getNumbersFromInput(std::string, char);

std::vector<std::string> parseInput(std::string, char);

int getUserOption(char);

TypeMatrix getMatrixFromUser();

void printMatrix(TypeMatrix);

void printMenu();

#endif
