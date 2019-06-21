#include "LowerTriangularMatrix.h"

LowerTriangularMatrix::LowerTriangularMatrix(unsigned _lines, unsigned _columns, TypeMatrix _m) : SquareMatrix(_lines, _columns, _m)
{
    std::cout << "Construtor Triangular Inferior" << std::endl;
};

LowerTriangularMatrix::LowerTriangularMatrix(const LowerTriangularMatrix &matrix) : SquareMatrix(matrix.lines, matrix.columns, matrix.m){};

LowerTriangularMatrix &LowerTriangularMatrix::operator=(const LowerTriangularMatrix &matrix)
{
    lines = matrix.lines;
    columns = matrix.columns;
    m = matrix.m;
    return *this;
}

void LowerTriangularMatrix::print()
{
    std::cout << "Sou triangular inferior!!" << std::endl;
}

LowerTriangularMatrix LowerTriangularMatrix::operator+(LowerTriangularMatrix matrix)
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

    return LowerTriangularMatrix(lines, columns, result);
}

LowerTriangularMatrix LowerTriangularMatrix::operator-(LowerTriangularMatrix matrix)
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

    return LowerTriangularMatrix(lines, columns, result);
}

// LowerTriangularMatrix LowerTriangularMatrix::operator*(float scalar)
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

//     return LowerTriangularMatrix(lines, columns, result);
// }

// LowerTriangularMatrix LowerTriangularMatrix::operator-(LowerTriangularMatrix matrix)
// {
//     TypeMatrix result(m);
//     TypeMatrix m2 = matrix.getMatrix();

//     for (unsigned i = 0; i < columns; i++)
//     {
//         for (unsigned j = 0; j < lines; j++)
//         {
//             if (i > j)
//                 continue;
//             result.at(j).at(i) = m.at(j).at(i) - (m2.at(j).at(i));
//         }
//     }

//     return LowerTriangularMatrix(lines, columns, result);
// }