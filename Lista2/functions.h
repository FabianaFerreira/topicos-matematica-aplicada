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

const std::string numbersInPortuguese[5][10] = {
    {
      "um",
      "dois",
      "tres",
      "quatro",
      "cinco",
      "seis",
      "sete",
      "oito",
      "nove"
    },
    {
      "dez",
      "vinte",
      "trinta",
      "quarenta",
      "cinquenta",
      "sessenta",
      "setenta",
      "oitenta",
      "noventa"
    },
    {
      "cento",
      "duzentos",
      "trezentos",
      "quatrocentos",
      "quinhentos",
      "seiscentos",
      "setecentos",
      "oitocentos",
      "novecentos"
    },
};

std::vector<float> getNumbersFromInput(std::string, char);

void sumDigitsFromPow(std::string);

void sumOddTermsFromFibonacci(std::string);

void calculateLargestPrimeNumber();

std::vector<int> getDigitsFromNumber (std::string);

void writeNumberInPortuguese(std::string);

bool checkQuantityOfArguments (unsigned, unsigned);

void printMenu();
