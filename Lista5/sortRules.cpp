#include "sortRules.h"
#include "Aluno.h"

bool sortByName(Aluno *a, Aluno *b)
{
    return a->getName() < b->getName();
}

bool sortByAverage(Aluno *a, Aluno *b)
{
    float partialAverageA, partialAverageB, finalAverageA, finalAverageB;

    partialAverageA = a->calculatePartialAverage();
    partialAverageB = b->calculatePartialAverage();

    finalAverageA = a->calculateFinalAverage();
    finalAverageB = b->calculateFinalAverage();

    return (partialAverageA > partialAverageB || finalAverageA > finalAverageB);
}

bool sortByFinalAverageDescending(Aluno *a, Aluno *b)
{
    float finalAverageA, finalAverageB;

    finalAverageA = a->calculateFinalAverage();
    finalAverageB = b->calculateFinalAverage();

    return (finalAverageA > finalAverageB);
}

bool sortByFinalAverageAscending(Aluno *a, Aluno *b)
{
    float finalAverageA, finalAverageB;

    finalAverageA = a->calculateFinalAverage();
    finalAverageB = b->calculateFinalAverage();

    return (finalAverageB > finalAverageA);
}

bool sortByGradesAndAverage(Aluno *a, Aluno *b)
{
    std::vector<float> gradesA(a->getGrades());
    std::vector<float> gradesB(b->getGrades());
    float partialAverageA, partialAverageB, finalAverageA, finalAverageB;

    partialAverageA = a->calculatePartialAverage();
    partialAverageB = b->calculatePartialAverage();

    finalAverageA = a->calculateFinalAverage();
    finalAverageB = b->calculateFinalAverage();

    return (gradesA.at(0) > gradesB.at(0) || gradesA.at(1) > gradesB.at(1) || partialAverageA > partialAverageB || finalAverageA > finalAverageB);
}

bool sortValues (float a, float b) {
    return a > b;
}