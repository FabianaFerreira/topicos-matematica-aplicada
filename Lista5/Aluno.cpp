#include "Aluno.h"
#include "functions.h"

#define QUANTITY_OF_GRADES 4

Aluno::Aluno() {}

Aluno::Aluno(std::string _name, std::string _dre, std::string _course, unsigned _semester) : grades(QUANTITY_OF_GRADES, -1),
                                                                                             name(_name),
                                                                                             dre(_dre),
                                                                                             course(_course),
                                                                                             semester(_semester) {}

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

float calculateAverage(float g1, float g2)
{
    if ((g1 > 0 && g1 <= 10) && (g2 > 0 && g2 <= 10))
    {
        return (g1 + g2) / 2;
    }
    return -1;
}