/* ---------------------------------------
  Fabiana Ferreira Fonseca
  Universidade Federal do Rio de Janeiro
  DRE: 115037241
----------------------------------------*/

#include "Lista.h"

#include "functions.h"
#include "sortRules.h"

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

std::vector<std::vector<float>> Lista::getStudentsGrades()
{
    std::vector<std::vector<float>> result;
    std::vector<float> current;

    for (unsigned i = 0; i < 6; i++)
    {
        current.clear();
        for (auto const &a : lista)
        {
            Aluno *aluno = a.second;
            std::vector<float> studentGrades(aluno->getGrades());

            if (i < 4)
            {
                float grade = studentGrades.at(i);
                // If grade is -1, it will not count to calculate statistics
                if (grade > 0)
                {
                    current.push_back(grade);
                }
            }
            else if (i == 4)
            {
                current.push_back(aluno->calculatePartialAverage());
            }
            else
            {
                current.push_back(aluno->calculateFinalAverage());
            }
        }
        result.push_back(current);
    }
    return result;
}

std::vector<std::vector<float>> Lista::calculateStatistics()
{
    float mean, median, mode, var, stdDev;

    std::vector<std::vector<float>> gradeArray = getStudentsGrades();
    std::vector<std::vector<float>> stats;

    for (auto &grades : gradeArray)
    {
        std::vector<float> gradesStats(5, 0);

        sort(grades.begin(), grades.end(), sortValues);

        float mean = calculateMean(grades);
        float var = calculateVariance(grades, mean);

        gradesStats.at(0) = mean;
        gradesStats.at(1) = calculateMedian(grades);
        gradesStats.at(2) = calculateMode(grades);
        gradesStats.at(3) = var;
        if (var > 0)
            gradesStats.at(4) = sqrt(var);
        else
            gradesStats.at(4) = -1;

        stats.push_back(gradesStats);
    }

    return stats;
}