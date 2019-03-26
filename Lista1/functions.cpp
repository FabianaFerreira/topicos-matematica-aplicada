/* ---------------------------------------
  Fabiana Ferreira Fonseca
  Universidade Federal do Rio de Janeiro
  DRE: 115037241
----------------------------------------*/

#include "functions.h"
#include "ClasseEquacaoSegundoGrau.h"

/*Funcao que faz o parser de string atraves de um delimiter*/
std::vector<float> getNumbersFromInput(std::string str, char delimiter) {
    std::vector<float> tokenVector;
    std::stringstream ss(str);
    std::string token;
    while (getline(ss, token, delimiter))
    {
        tokenVector.push_back(stof(token));
    }

    return tokenVector;
}

/*Funcao que checa erros de input e usa a classe de equacao de segundo grau*/
void callEquationSolver (std::string input) {
    std::vector<float> arg = getNumbersFromInput(input, ' ');

    if (arg.size() != 3)
        std::cout << "Quantidade invalida de argumentos" << std::endl;
    else if (arg[0] == 0)
        std::cout << "Coeficiente a = 0. Equacao de primeira ordem." << std::endl;
    else
    {
        Equation *eq = new Equation(arg[0], arg[1], arg[2]);
        eq->solveEquation();
        std::cout << std::endl;
  }
}

/*Funcao que calcula os multiplos*/
void calculateMultiples (std::string input) {
    std::vector<float> arg = getNumbersFromInput(input, ' ');

    if (arg.size() != 3)
        std::cout << "Quantidade invalida de argumentos" << std::endl;

    int x = arg[0];
    int y = arg[1];
    unsigned n = arg[2];
    unsigned counter = 0;
    std::string multiplesX = "";
    std::string multiplesY = "";

    while (counter < n)
    {
        multiplesX += " " + std::to_string(counter * x);
        multiplesY += " " + std::to_string(counter * y);
        counter++;
  }

  std::cout << "Multiplos de x: " << multiplesX << std::endl
            << "Multiplos de y: " << multiplesY << std::endl;
}

/*Cria um vetor de dimensao n com valores aleatorios*/
std::vector<int> generateRandomVector(unsigned n) {
    std::vector<int> randomVector;

    unsigned counter = 0;

    std::cout << "Vetor: ";
    while (counter < n)
    {
        int randomNumber = rand() % 101;
        std::cout << randomNumber << ",";
        randomVector.push_back(randomNumber);
        counter++;
  }

  std::cout << std::endl;

  return randomVector;
}

void sumTwoVectors (std::vector<int> v1, std::vector<int> v2) {
  std::vector <int> result;
  if (v1.size() != v2.size()) {
      std::cout << "Vetores de dimensoes diferentes" << std::endl;
  }
  else {
    std::cout << "Resultado: ";
    for (int i = 0; i < v1.size(); i++) {
      int sum = v1.at(i) + v2.at(i);
      result.push_back(sum);
      std::cout << sum << ", ";
    }
  }
  std::cout << std::endl;
}

void listPointsInRange (std::string input) {
    std::vector<float> arg = getNumbersFromInput(input, ' ');

    if (arg.size() != 3)
        std::cout << "Quantidade invalida de argumentos" << std::endl;
    else {
        /*.at() eh usado para que um erro seja gerado caso haja uma tentativa de acessar um index do vector que nao existe*/
        float coordX = arg.at(0);
        float coordY = arg.at(1);
        float radius = arg.at(2);
        unsigned counter = 0;
        std::vector<unsigned> pointsInsideRadius;

        /*pre-definido como uma constante em functions.h*/
        int arraySize = 10;

        for (unsigned i = 0; i < arraySize; i++) {
            float d1 = coordX - mapCoordinates[i][0];
            float d2 = coordY - mapCoordinates[i][1];
            if (sqrt(pow(d1, 2) + pow(d2, 2)) <= radius)
                pointsInsideRadius.push_back(i);
        }
        std::cout << "Pontos do mapa a uma distancia menor ou igual ao raio: ";

        while (counter < pointsInsideRadius.size()) {
            std::cout << "(" << mapCoordinates[pointsInsideRadius.at(counter)][0] << "," << mapCoordinates[pointsInsideRadius.at(counter)][1] << ")" << " | ";
            counter++;
        }

        std::cout << std::endl;
    }
}

/*Funcao para printar o menu*/
void printMenu () {
    std::cout << "Digite 1 para equacao do segundo grau" << std::endl;
    std::cout << "Digite 2 para N primeiros multiplos entre dois numeros" << std::endl;
    std::cout << "Digite 3 para soma de vetores de N coordenadas" << std::endl;
    std::cout << "Digite 4 para a questao dos postos em um raio de X km" << std::endl;
    std::cout << "Digite 'exit' para sair do programa" << std::endl;
}