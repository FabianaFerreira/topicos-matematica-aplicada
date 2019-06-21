/* ---------------------------------------
  Fabiana Ferreira Fonseca
  Universidade Federal do Rio de Janeiro
  DRE: 115037241
----------------------------------------*/

#include "UpperTriangularMatrix.h"

UpperTriangularMatrix::UpperTriangularMatrix(unsigned _lines, unsigned _columns, TypeMatrix _m) : SquareMatrix(_lines, _columns, _m)
{
    std::cout << "Construtor Triangular Superior" << std::endl;
}

UpperTriangularMatrix::UpperTriangularMatrix(const UpperTriangularMatrix &matrix) : SquareMatrix(matrix.lines, matrix.columns, matrix.m) {}

UpperTriangularMatrix &UpperTriangularMatrix::operator=(const UpperTriangularMatrix &matrix)
{
    lines = matrix.lines;
    columns = matrix.columns;
    m = matrix.m;
    return *this;
}

void UpperTriangularMatrix::print()
{
    std::cout << "Sou triangular superior!!" << std::endl;
}

UpperTriangularMatrix UpperTriangularMatrix::operator+(UpperTriangularMatrix matrix)
{
    TypeMatrix result(m);
    TypeMatrix m2 = matrix.getMatrix();

    for (unsigned i = 0; i < columns; i++)
    {
        for (unsigned j = 0; j < lines; j++)
        {
            if (i > j)
                continue;
            result.at(j).at(i) = m.at(j).at(i) + (m2.at(j).at(i));
        }
    }

    return UpperTriangularMatrix(lines, columns, result);
}

UpperTriangularMatrix UpperTriangularMatrix::operator-(UpperTriangularMatrix matrix)
{
    TypeMatrix result(m);
    TypeMatrix m2 = matrix.getMatrix();

    for (unsigned i = 0; i < columns; i++)
    {
        for (unsigned j = 0; j < lines; j++)
        {
            if (i > j)
                continue;
            result.at(j).at(i) = m.at(j).at(i) - (m2.at(j).at(i));
        }
    }

    return UpperTriangularMatrix(lines, columns, result);
}

// UpperTriangularMatrix UpperTriangularMatrix::operator*(float scalar)
// {
//     TypeMatrix result(m);

//     for (unsigned i = 0; i < columns; i++)
//     {
//         for (unsigned j = 0; j < lines; j++)
//         {
//             if (i > j)
//                 continue;
//             result.at(j).at(i) = m.at(j).at(i) * scalar;
//         }
//     }

//     return UpperTriangularMatrix(lines, columns, result);
// }