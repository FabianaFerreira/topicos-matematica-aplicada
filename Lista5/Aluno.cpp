/* ---------------------------------------
  Fabiana Ferreira Fonseca
  Universidade Federal do Rio de Janeiro
  DRE: 115037241
----------------------------------------*/
#include "Aluno.h"
#include "functions.h"

#define QUANTITY_OF_GRADES 4

Aluno::Aluno(std::string _dre, std::string _name, std::string _course, unsigned _semester, float _frequency, std::vector<float> _grades) : dre(_dre)
{
    name = _name;
    course = _course;
    semester = _semester;
    frequency = _frequency;
    grades = std::vector<float>(_grades);
}

Aluno::Aluno(std::string _dre, std::string _name, std::string _course, unsigned _semester, float _frequency) : dre(_dre)
{
    name = _name;
    course = _course;
    semester = _semester;
    frequency = _frequency;
    grades = std::vector<float>(QUANTITY_OF_GRADES, -1);
}

Aluno::~Aluno() {}

std::string Aluno::getName()
{
    return name;
}

std::string Aluno::getDre()
{
    return dre;
}

std::vector<float> Aluno::getGrades()
{
    return grades;
}

float Aluno::getFrequency()
{
    return frequency;
}

std::string Aluno::getCourse()
{
    return course;
}

unsigned Aluno::getSemester()
{
    return semester;
}

bool Aluno::setGrade(unsigned position, float grade)
{
    if (grade > 0 && grade <= 10)
    {
        grades.at(position) = grade;
    }
}

bool Aluno::setFrequency(float _frequency)
{
    if (_frequency > 0)
    {
        frequency = _frequency;
        return true;
    }
    return false;
}

bool Aluno::setCourse(std::string _course)
{
    if (_course.length() > 0)
    {
        course = _course;
        return true;
    }
    return false;
}

bool Aluno::setSemester(unsigned _semester)
{
    if (_semester < 30)
    {
        semester = _semester;
        return true;
    }
    return false;
}

void Aluno::printData() const
{
    std::cout << " | "
              << std::setw(16) << name << " | "
              << std::setw(10) << dre << " | "
              << std::setw(15) << course << " | "
              << std::setw(3) << semester << " | "
              << std::setw(5) << frequency << " | "
              << std::setw(5) << grades.at(0) << " | "
              << std::setw(5) << grades.at(1) << " | "
              << std::setw(5) << grades.at(2) << " | "
              << std::setw(5) << grades.at(3) << " | "
              << std::endl;
}

float Aluno::calculatePartialAverage()
{

    if (grades.at(0) < 0 || grades.at(1) < 0)
    {
        return -1;
    }
    return (grades.at(0) + grades.at(1)) / 2;
}

float Aluno::calculateFinalAverage()
{
    float partial = calculatePartialAverage();
    if (grades.at(0) < 0 || grades.at(1) < 0)
    {
        return -1;
    }
    if (grades.at(2) < 0)
        return partial;
    return (partial + grades.at(2)) / 2;
}