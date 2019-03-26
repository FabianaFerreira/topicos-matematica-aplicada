/* ---------------------------------------
  Fabiana Ferreira Fonseca
  Universidade Federal do Rio de Janeiro
  DRE: 115037241
----------------------------------------*/

#include <string>
#include <vector>
#include <sstream>

const float mapCoordinates[10][2] = {
    {0, 1},
    {1.2, 0},
    {1.7, 1},
    {3, 4},
    {2.5, 7.6},
    {5, 8},
    {9.2, 2.3},
    {4, 6.5},
    {0, 5.5},
    {7, 10}
};

std::vector<float> getNumbersFromInput(std::string, char);

void callEquationSolver(std::string);

void calculateMultiples(std::string);

std::vector<int> generateRandomVector(unsigned);

void sumTwoVectors(std::vector<int>, std::vector<int>);

void listPointsInRange(std::string);

void printMenu();
