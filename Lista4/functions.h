/* ---------------------------------------
  Fabiana Ferreira Fonseca
  Universidade Federal do Rio de Janeiro
  DRE: 115037241
----------------------------------------*/

#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>
#include <cmath>
#include <math.h>
#include <algorithm> 

#include "Pino.h"
#include "types.h"

std::vector<unsigned> getNumbersFromString(std::string);

std::vector<std::string> parseInput(std::string, char);

int getUserOption(char);

Matrix getMatrixFromUser();

Matrix initializeSquareMatrix(unsigned);

void createEquationMatrix(Matrix const, std::vector<float> const, Matrix &, unsigned);

unsigned getFileLinesQuantity (std::string);

void printMatrix(Matrix);

void printMatrix(BinaryMatrix);

bool fillContour(BinaryMatrix &, unsigned, unsigned, unsigned, unsigned);

void fillContour2(BinaryMatrix &, unsigned, unsigned, unsigned, unsigned);

unsigned solveHanoiTower(int, Pino &, Pino &, Pino &);

void MoveDisc(Pino &, Pino &);

void printMenu();
