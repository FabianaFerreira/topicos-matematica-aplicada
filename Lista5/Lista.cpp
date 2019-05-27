/* ---------------------------------------
  Fabiana Ferreira Fonseca
  Universidade Federal do Rio de Janeiro
  DRE: 115037241
----------------------------------------*/

#include "Lista.h"

#include "functions.h"

Lista::Lista(){};

// Lista::Lista(std::string filename)
// {
//     std::string index;
//     unsigned lines, columns;
//     std::vector<float> matrixLine;
//     float element;

// std::ifstream f;

// f.open(filename);
// if (!f)
// {
//     std::cout << "Unable to open file" << std::endl;
//     exit(1); // terminate with error
// };

// while (!f.eof())
// {
//     f >> index >> lines >> columns;
//     for (int i = 0; i < lines; i++)
//     {
//         matrixLine.clear();
//         for (int j = 0; j < columns; j++)
//         {
//             f >> element;
//             matrixLine.push_back(element);
//         }
//         lista[index].push_back(matrixLine);
//     }
// }

// f.close();
// };

// Read matrix list from file. If `append` is true, then append the new
// matrix list content to the current one, overwriting existing indexes.
// If `append` is false, set the matrix list content to the file data.
// void Lista::readFile(std::string filename, bool append = false)
// {
//     std::string index;
//     unsigned lines, columns;
//     std::vector<float> matrixLine;
//     std::map<std::string, Aluno> tempList;
//     float element;
//     bool wasEmpty = (lista.size() == 0);

//     std::cout << "Construtor arquivo" << std::endl;
//     std::ifstream f;

//     f.open(filename);
//     if (!f)
//     {
//         std::cout << "Unable to open file";
//         exit(1); // terminate with error
//     };

//     while (!f.eof())
//     {
//         f >> index >> lines >> columns;
//         for (int i = 0; i < lines; i++)
//         {
//             matrixLine.clear();
//             for (int j = 0; j < columns; j++)
//             {
//                 f >> element;
//                 matrixLine.push_back(element);
//             }
//             if (append || wasEmpty)
//                 lista[index].push_back(matrixLine);
//             else
//                 tempList[index].push_back(matrixLine);
//         }
//     }

//     f.close();

//     if (!append)
//         lista = tempList;
// }

void Lista::save(std::string filename)
{
    std::ofstream f;

    f.open(filename);
    if (!f)
    {
        std::cout << "Unable to open file";
        exit(1); // terminate with error
    };

    unsigned counter = 0;
    for (auto const &x : lista)
    {
        Aluno aluno = x.second;

        f << x.first << " " << aluno.getName() << " " << aluno.getCourse() << " " << aluno.getSemester();

        if (counter != (lista.size() - 1))
            f << std::endl;

        counter++;
    }

    f.close();
}

void Lista::list()
{
    if (lista.size() == 0)
    {
        std::cout << "Empty list" << std::endl;
        return;
    }

    for (auto const &x : lista)
    {
        Aluno aluno = x.second;

        std::cout << "Aluno " << x.first << std::endl;
        std::cout << "Nome: " << aluno.getName() << std::endl;
        std::cout << "DRE: " << aluno.getDre() << std::endl;
        std::cout << "Curso: " << aluno.getCourse() << std::endl;
        std::cout << "Periodo: " << aluno.getSemester() << std::endl;
        std::cout << std::endl;
    }
}

std::vector<Aluno> Lista::get(std::string searchKey, bool isSearchByName)
{
    std::vector<Aluno> results;
    if (isSearchByName)
    {
        for (auto const &x : lista)
        {
            Aluno aluno = x.second;

            if (aluno.getName().find(searchKey) != std::string::npos)
            {
                results.push_back(aluno);
            }
        }
    }
    else
    {
        results.push_back(lista[searchKey]);
    }
    return results;
}

void Lista::insert(std::string index, Aluno aluno)
{
    lista[index] = aluno;
}

void Lista::remove(std::string index)
{
    lista.erase(index);
}

void Lista::clear()
{
    lista.clear();
}