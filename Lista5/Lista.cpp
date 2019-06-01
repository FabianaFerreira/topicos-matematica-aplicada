/* ---------------------------------------
  Fabiana Ferreira Fonseca
  Universidade Federal do Rio de Janeiro
  DRE: 115037241
----------------------------------------*/

#include "Lista.h"

#include "functions.h"

Lista::Lista(){};

Lista::~Lista()
{
    // Destroying all pointers to Aluno
    for (auto const &x : lista)
    {
        delete x.second;
    }
    clear();
};

bool Lista::sortByName(Aluno *a, Aluno *b)
{
    return a->getName() < b->getName();
}

bool Lista::sortByAverage(Aluno *a, Aluno *b)
{
    std::vector<float> gradesA(a->getGrades());
    std::vector<float> gradesB(b->getGrades());
    float partialAverageA, partialAverageB, finalAverageA, finalAverageB;

    if (gradesA.at(0) < 0 || gradesA.at(1) < 0)
    {
        partialAverageA = -1;
        finalAverageA = -1;
    }
    else
    {
        partialAverageA = (gradesA.at(0) + gradesA.at(1)) / 2;

        if (gradesA.at(2) > 0)
        {
            finalAverageA = (partialAverageA + gradesA.at(2)) / 2;
        }
        else
        {
            finalAverageA = partialAverageA;
        }
    }

    if (gradesB.at(0) < 0 || gradesB.at(1) < 0)
    {
        partialAverageB = -1;
        finalAverageB = -1;
    }
    else
    {

        partialAverageB = (gradesB.at(0) + gradesB.at(1)) / 2;
        if (gradesB.at(2) > 0)
        {
            finalAverageB = (partialAverageB + gradesB.at(2)) / 2;
        }
        else
        {
            finalAverageB = partialAverageB;
        }
    }

    return (partialAverageA > partialAverageB || finalAverageA > finalAverageB);
}

bool Lista::sortByGradesAndAverage(Aluno *a, Aluno *b)
{
    std::vector<float> gradesA(a->getGrades());
    std::vector<float> gradesB(b->getGrades());
    float partialAverageA, partialAverageB, finalAverageA, finalAverageB;

    if (gradesA.at(0) < 0 || gradesA.at(1) < 0)
    {
        partialAverageA = -1;
        finalAverageA = -1;
    }
    else
    {
        partialAverageA = (gradesA.at(0) + gradesA.at(1)) / 2;

        if (gradesA.at(2) > 0)
        {
            finalAverageA = (partialAverageA + gradesA.at(2)) / 2;
        }
        else
        {
            finalAverageA = partialAverageA;
        }
    }

    if (gradesB.at(0) < 0 || gradesB.at(1) < 0)
    {
        partialAverageB = -1;
        finalAverageB = -1;
    }
    else
    {

        partialAverageB = (gradesB.at(0) + gradesB.at(1)) / 2;
        if (gradesB.at(2) > 0)
        {
            finalAverageB = (partialAverageB + gradesB.at(2)) / 2;
        }
        else
        {
            finalAverageB = partialAverageB;
        }
    }

    return (gradesA.at(0) > gradesB.at(0) || gradesA.at(1) > gradesB.at(1) || partialAverageA > partialAverageB || finalAverageA > finalAverageB);
}

void Lista::readFile(std::string filename)
{
    std::string id, name, surname, course;
    unsigned semester;
    float frequency, p1, p2, pf, p2ch;

    std::map<std::string, Aluno *> list;
    float element;
    bool wasEmpty = (lista.size() == 0);

    std::ifstream f;

    f.open(filename);

    if (!f)
    {
        std::cout << "Unable to open file";
        exit(1); // terminate with error
    }

    while (!f.eof())
    {
        f >> name >> surname >> id >> course >> semester >> frequency >> p1 >> p2 >> pf >> p2ch;
        std::vector<float> grades = {p1, p2, pf, p2ch};
        Aluno *current = new Aluno(id, name + " " + surname, course, semester, frequency, grades);
        lista[id] = current;
    }

    f.close();
}

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
        Aluno *aluno = x.second;

        f << aluno->getName() << " " << x.first << " " << aluno->getCourse() << " " << aluno->getSemester() << " " << aluno->getFrequency();

        // Putting all grades in file
        for (auto const &grade : aluno->getGrades())
        {
            f << " " << grade;
        }

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
        Aluno *aluno = x.second;

        std::cout << "Aluno " << x.first << std::endl;
        std::cout << "Nome: " << aluno->getName() << std::endl;
        std::cout << "DRE: " << aluno->getDre() << std::endl;
        std::cout << "Curso: " << aluno->getCourse() << std::endl;
        std::cout << "Periodo: " << aluno->getSemester() << std::endl;
        std::cout << std::endl;
    }
}

std::vector<Aluno *> Lista::get(std::string const searchKey, bool isSearchByName)
{
    std::vector<Aluno *> results;
    if (isSearchByName)
    {
        for (auto const &x : lista)
        {
            Aluno *aluno = x.second;

            if (aluno->getName().find(searchKey) != std::string::npos)
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

std::vector<Aluno *> Lista::getAllStudents()
{
    std::vector<Aluno *> results;

    for (auto const &x : lista)
    {
        Aluno *aluno = x.second;

        results.push_back(aluno);
    }

    return results;
}

void Lista::insert(std::string index, Aluno *aluno)
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