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

        // f << x.first << " " << lines << " " << columns << std::endl;
        // for (unsigned i = 0; i < lines; i++)
        // {
        //     for (unsigned j = 0; j < columns; j++)
        //     {
        //         f << aluno.at(i).at(j);
        //         if (j != (columns - 1))
        //             f << " ";
        //     }
        //     if ((i != (lines - 1)) || (counter != (lista.size() - 1)))
        //         f << std::endl;
        // }
        // if (counter != (lista.size() - 1))
        //     f << std::endl;

        // counter++;
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

Aluno Lista::get(std::string index, bool isSearchByName)
{
    return lista[index];
}

// Add or modify a matrix of the list given an index
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