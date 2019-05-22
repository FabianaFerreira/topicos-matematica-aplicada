/* ---------------------------------------
  Fabiana Ferreira Fonseca
  Universidade Federal do Rio de Janeiro
  DRE: 115037241
----------------------------------------*/

#include <iostream>
#include <fstream>
#include <sstream>

#include <string>
#include <vector>

#include <stdlib.h>
#include <stdio.h>

#include "functions.h"
#include "MatrixList.h"

using namespace std;

/*--------------------------------------------- MAIN -------------------------------------------------------*/
int main()
{
    char index;
    string input;
    string filename;

    printMenu();

    //Ignoring \n that is in buffer
    cin.ignore();

    while (input.compare("exit") != 0)
    {
        cout << "Digite uma opcao: ";
        getline(cin, input);

        switch (atoi(input.c_str()))
        {
        case 1:
        {
            cout << "Digite o nome da lista de matrizes a ser lido (.txt): ";
            cin >> filename;

            /*Instancias dos objetos das classes Calculator e MatrixList*/
            MatrixList matrixList(filename);

            matrixList.list();
        }
        break;

        /*Torre de Hanoi*/
        case 2:
        {
            unsigned qnt = solveHanoiTower(3, 'A', 'B', 'C');

            cout << "qnt 3: " << qnt << endl;

            qnt = solveHanoiTower(4, 'A', 'B', 'C');

            cout << "qnt 4: " << qnt << endl;

            qnt = solveHanoiTower(5, 'A', 'B', 'C');

            cout << "qnt 5: " << qnt << endl;
        }

        break;

        /*Preenchimento de contornos*/
        case 3:
        {
            BinaryMatrix m;
            std::ifstream f;
            std::string line;
            unsigned linesCounter = 0;
            unsigned columnsCounter, linePos, columnPos;

            cout << "Digite o nome da lista de matrizes a ser lido (.txt): ";
            cin >> filename;

            cout << "Digite a posicao inicial (x,y) (separados por espaco): ";
            cin >> linePos >> columnPos;

            f.open(filename);
            if (!f)
            {
                std::cout << "FileNotFoundError: Unable to open file" << std::endl;
                exit(1); // terminate with error
            }
            while (std::getline(f, line))
            {

                vector<char> v(line.begin(), line.end());

                m.push_back(v);

                linesCounter++;
            }
            f.close();

            cout << " ----------------- Depois -----------------" << endl;
            fillContour(m, linesCounter, m.at(0).size(), linePos, columnPos);
        }
        break;

        default:
        {
            if (!input.compare("exit") == 0)
                cout << "Opcao invalida. Por favor, tente novamente." << endl;
        }
        break;
        }
    }
    cout << "Obrigada por testar!" << endl;

    return 0;
}
