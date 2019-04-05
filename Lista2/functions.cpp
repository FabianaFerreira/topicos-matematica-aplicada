/* ---------------------------------------
  Fabiana Ferreira Fonseca
  Universidade Federal do Rio de Janeiro
  DRE: 115037241
----------------------------------------*/

#include "functions.h"

/*Funcao que faz o parser de string atraves de um delimiter*/
std::vector<float> getNumbersFromInput(std::string str, char delimiter)
{
  std::vector<float> tokenVector;
  std::stringstream ss(str);
  std::string token;
  while (getline(ss, token, delimiter))
  {
    tokenVector.push_back(stof(token));
  }

  return tokenVector;
}

void sumDigitsFromPow(std::string input)
{
  std::vector<float> arg = getNumbersFromInput(input, ' ');
  int number;
  long digitsSum;

  if (arg.size() != 1)
    std::cout << "Quantidade invalida de argumentos" << std::endl;
  else
  {
    number = pow(2, arg.at(0));
    std::cout << "2^" << arg.at(0) << " = " << number << std::endl;
    while (number != 0)
    {
      digitsSum = digitsSum + number % 10;
      number = number / 10;
    }
    std::cout << "Soma dos digitos: " << digitsSum << std::endl;
  }
}

void sumOddTermsFromFibonacci(std::string input)
{
  std::vector<float> arg = getNumbersFromInput(input, ' ');
  std::vector<long> fiboTerms;
  std::string terms = "";
  long long termsSum;
  long long maxFibTerm = arg.at(0);
  unsigned counter = 2;

  if (arg.size() != 1 || maxFibTerm < 0)
    std::cout << "Quantidade invalida de argumentos ou valor de n invalido" << std::endl;
  else
  {
    /*Termos de Fibonacci de indice 0 e 1*/
    fiboTerms.push_back(0);
    fiboTerms.push_back(1);

    termsSum = fiboTerms.at(1);

    /*Concatenando string para printar todos os termos*/
    std::cout << "Termos Fibonacci: ";
    terms = std::to_string(fiboTerms.at(0)) + " " + std::to_string(fiboTerms.at(1)) + " ";

    /*Itera para calcular os termos e a soma dos impares*/
    while (termsSum <= maxFibTerm)
    {
      fiboTerms.push_back(fiboTerms.at(counter - 1) + fiboTerms.at(counter - 2));
      /*Se nao for par*/
      if (counter % 2 != 0)
        termsSum += fiboTerms.at(counter);

      /*Concatenando string para printar todos os termos*/
      terms += std::to_string(fiboTerms.at(counter)) + " ";

      counter++;
    }
    std::cout << terms << std::endl;
    std::cout << "Soma dos termos impares: " << termsSum << std::endl;
  }
}

void calculateLargestPrimeNumber()
{
  long long number = 3852914583882;
  bool isPrime;
  long long largestPrime;
  for (long long x = 2; x < number; x++)
  {
    isPrime = true;
    for (long long y = 2; y < x; y++)
    {
      if (x % y == 0)
      {
        isPrime = false;
        break;
      }
    }
    if (isPrime)
      largestPrime = x;    
      
  }
  std::cout << "O maior primo de 3852914583882 eh " << largestPrime << std::endl;
}

std::vector<int> getDigitsFromNumber(std::string input)
{
  std::vector<float> arg = getNumbersFromInput(input, ' ');
  std::vector<int> digitsArray;
  bool isQntCorrect = checkQuantityOfArguments(arg.size(), 1);

  if (isQntCorrect)
  {
    int number = (int)arg.at(0);
    while (number != 0)
    {
      int digit = number % 10;
      std::cout << digit << std::endl;
      digitsArray.push_back(digit);
      number /= 10;
    }
  }

  return digitsArray;
}

/*Recebe um vetor de digitos e gera uma string com os numeros por extenso*/
void writeNumberInPortuguese(std::string input)
{
  unsigned counter = 0;
  std::vector<int> digits = getDigitsFromNumber(input);
  std::string literalNumber = "";
  while (counter < digits.size())
  {
    if (digits.at(counter) != 0)
    {
      if (counter < 3)
      {
        if (counter == 0)
          literalNumber = numbersInPortuguese[counter][digits.at(counter) - 1];
        else
          literalNumber = numbersInPortuguese[counter][digits.at(counter) - 1] + " e " + literalNumber;
      }
      else if (counter == 3)
        literalNumber = numbersInPortuguese[0][digits.at(counter) - 1] + " mil " + literalNumber;
      else
        literalNumber = numbersInPortuguese[0][digits.at(counter) - 1] + " milhoes " + literalNumber;
    }
    counter++;
  }
  std::cout << literalNumber << std::endl;
}

/*Checa se a quantidade de argumentos eh valida*/
bool checkQuantityOfArguments(unsigned length, unsigned n)
{
  if (length != n)
  {
    std::cout << "Quantidade invalida de argumentos";
    return false;
  }
  return true;
}

/*Funcao para printar o menu*/
void printMenu()
{
  std::cout << "Digite 1 para soma dos digitos" << std::endl;
  std::cout << "Digite 2 para soma dos termos impares de Fibonacci" << std::endl;
  std::cout << "Digite 3 para maior fator primo de 3852914583882" << std::endl;
  std::cout << "Digite 4 para escrever por extenso um numero" << std::endl;
  std::cout << "Digite 'exit' para sair do programa" << std::endl;
}
