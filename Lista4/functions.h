/* ---------------------------------------
  Fabiana Ferreira Fonseca
  Universidade Federal do Rio de Janeiro
  DRE: 115037241
----------------------------------------*/

#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <math.h>

#include "types.h"

std::vector<float> getNumbersFromInput(std::string, char);

std::vector<std::string> parseInput(std::string, char);

int getUserOption(char);

Matrix getMatrixFromUser();

void generateBlockMatrix(Matrix const, Matrix &, unsigned);

Matrix initializeSquareMatrix(unsigned);

void createEquationMatrix(Matrix const, std::vector<float> const, Matrix &, unsigned);

void printMatrix(Matrix);

void printMatrix(Matrix, unsigned, unsigned, bool);

bool fillContour (Matrix, unsigned, unsigned, unsigned, unsigned);

void solveHanoiTower(int, char, char, char);

void printMenu();
