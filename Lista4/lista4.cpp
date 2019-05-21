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
        }

        break;

        /*Preenchimento de contornos*/
        case 3:
        {
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
