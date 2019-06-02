/* ---------------------------------------
  Fabiana Ferreira Fonseca
  Universidade Federal do Rio de Janeiro
  DRE: 115037241
----------------------------------------*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stdio.h>
#include <algorithm>
#include "functions.h"
#include "sortRules.h"
#include "Lista.h"

using namespace std;

int main()
{
    string input;

    Lista lista;

    string filename;
    cout << "Digite o nome da lista de alunos a ser lida (.txt): ";
    cin >> filename;
    cin.ignore();
    lista.readFile(filename);

    cout << endl;

    printMenu();

    cout << endl;

    vector<Aluno *> students = lista.getAllStudents();

    while (input.compare("exit") != 0)
    {
        cout << "Digite uma opcao: ";
        getline(cin, input);

        /*LISTA ALUNOS EM ORDEM CRESCENTE DE NOME*/
        if (input == "1")
        {
            std::cout << " | "
                      << std::setw(19) << " Nome | "
                      << std::setw(13) << " DRE | "
                      << std::setw(17) << " Curso |"
                      << " Per | "
                      << std::setw(5) << " Freq |"
                      << std::setw(8) << " P1 |"
                      << std::setw(8) << " P2 |"
                      << std::setw(8) << " PF |"
                      << std::setw(8) << " P2ch |"
                      << std::endl;

            sort(students.begin(), students.end(), sortByName);
            for (Aluno *a : students)
                a->printData();

            cout << endl;
        }
        /*LISTA ALUNOS EM ORDEM DECRESCENTE DE MEDIA*/
        else if (input == "2")
        {
            std::cout << " | "
                      << std::setw(19) << " Nome | "
                      << std::setw(13) << " DRE | "
                      << std::setw(17) << " Curso |"
                      << " Per | "
                      << std::setw(5) << " Freq |"
                      << std::setw(8) << " P1 |"
                      << std::setw(8) << " P2 |"
                      << std::setw(8) << " PF |"
                      << std::setw(8) << " P2ch |"
                      << std::endl;

            sort(students.begin(), students.end(), sortByAverage);
            for (Aluno *a : students)
                a->printData();

            cout << endl;
        }

        /*LISTA NOMES DOS ALUNOS QUE FIZERAM DETERMINADA PROVA*/
        else if (input == "3")
        {
            float exam;
            cout << "Quais provas voce deseja visualizar? 1 para P1, 2 para P2, 3 para PF e 4 para 2a chamada: ";
            cin >> exam;

            if (exam > 4 || exam < 0)
            {
                cout << "Opcao invalida. Tente novamente" << endl;
                break;
            }

            std::cout << " | "
                      << std::setw(19) << " Nome | "
                      << std::setw(13) << " DRE | "
                      << std::setw(17) << " Curso |"
                      << " Per | "
                      << std::setw(5) << " Freq |"
                      << std::setw(8) << " P1 |"
                      << std::setw(8) << " P2 |"
                      << std::setw(8) << " PF |"
                      << std::setw(8) << " P2ch |"
                      << std::endl;

            for (Aluno *a : students)
            {
                if (a->getGrades().at(exam - 1) > 0)
                    a->printData();
            }

            cout << endl;
        }

        /*LISTAR ALUNOS ORDENADOS POR MEDIA E NOTAS*/
        else if (input == "4")
        {
            std::cout << " | "
                      << std::setw(19) << " Nome | "
                      << std::setw(13) << " DRE | "
                      << std::setw(17) << " Curso |"
                      << " Per | "
                      << std::setw(5) << " Freq |"
                      << std::setw(8) << " P1 |"
                      << std::setw(8) << " P2 |"
                      << std::setw(8) << " PF |"
                      << std::setw(8) << " P2ch |"
                      << std::endl;

            sort(students.begin(), students.end(), sortByGradesAndAverage);
            for (Aluno *a : students)
                a->printData();

            cout << endl;
        }

        /*ESTATISTICAS DAS NOTAS*/
        else if (input == "5")
        {
            cout << endl;
            cout << "Estatisticas para provas e medias, na seguinte ordem:" << endl;
            cout << "P1, P2, PF, 2a chamada, media parcial e media final" << endl;
            cout << endl;

            //Copy constructor
            vector<vector<float>> stats(lista.calculateStatistics());

            for (auto const &gradeStats : stats)
            {
                cout << "Media: " << gradeStats.at(0) << endl;
                cout << "Mediana: " << gradeStats.at(1) << endl;
                cout << "Moda: " << gradeStats.at(2) << endl;
                cout << "Variancia: " << gradeStats.at(3) << endl;
                cout << "Desvio Padrao: " << gradeStats.at(4) << endl;
                cout << endl;
            }
        }

        /*SALVAR EM ARQUIVO*/
        else if (input == "6")
        {
        }

        else if (input.compare("exit") != 0)
        {
            cout << "Digite uma opcao valida" << endl;
        }

        cout << endl;
    }

    cout << "Obrigada por testar!" << endl;

    return 0;
}
