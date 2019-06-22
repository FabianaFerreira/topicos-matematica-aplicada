#include "LowerTriangularMatrix.h"

LowerTriangularMatrix::LowerTriangularMatrix(unsigned _lines, unsigned _columns, TypeMatrix _m) : SquareMatrix(_lines, _columns, _m){};

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

Matrix *LowerTriangularMatrix::operator+(const Matrix &matrix) const
{
    TypeMatrix result;

    const LowerTriangularMatrix *pointer = dynamic_cast<const LowerTriangularMatrix *>(&matrix);

    if (!pointer)
    {
        return Matrix::operator+(matrix);
    }

    LowerTriangularMatrix matrix2 = *pointer;

    TypeMatrix m2 = matrix2.getMatrix();

    for (unsigned i = 0; i < columns; i++)
    {
        for (unsigned j = 0; j < lines; j++)
        {
            if (i > j)
                continue;
            result.at(j).at(i) = m.at(j).at(i) + (m2.at(j).at(i));
        }
    }

    return new LowerTriangularMatrix(lines, columns, result);
}

Matrix *LowerTriangularMatrix::operator-(const Matrix &matrix) const
{
    TypeMatrix result;

    const LowerTriangularMatrix *pointer = dynamic_cast<const LowerTriangularMatrix *>(&matrix);

    if (!pointer)
    {
        return Matrix::operator-(matrix);
    }

    LowerTriangularMatrix matrix2 = *pointer;

    TypeMatrix m2 = matrix2.getMatrix();

    for (unsigned i = 0; i < columns; i++)
    {
        for (unsigned j = 0; j < lines; j++)
        {
            if (i > j)
                continue;
            result.at(j).at(i) = m.at(j).at(i) - (m2.at(j).at(i));
        }
    }

    return new Matrix(lines, columns, result);
}

Matrix *LowerTriangularMatrix::operator*(float scalar) const
{
    TypeMatrix result;

    for (unsigned i = 0; i < columns; i++)
    {
        for (unsigned j = 0; j < lines; j++)
        {
            if (i > j)
                continue;
            result.at(j).at(i) = m.at(j).at(i) * scalar;
        }
    }

    return new Matrix(lines, columns, result);
}

Matrix *LowerTriangularMatrix::operator*(const Matrix &matrix) const
{
    TypeMatrix result;

    const LowerTriangularMatrix *pointer = dynamic_cast<const LowerTriangularMatrix *>(&matrix);

    if (!pointer)
    {
        return Matrix::operator*(matrix);
    }

    LowerTriangularMatrix matrix2 = *pointer;

    TypeMatrix m2 = matrix2.getMatrix();

    for (unsigned i = 0; i < columns; i++)
    {
        for (unsigned j = 0; j < lines; j++)
        {
            if (i > j)
                continue;
            result.at(j).at(i) = m.at(j).at(i) * (m2.at(j).at(i));
        }
    }

    return new LowerTriangularMatrix(lines, columns, result);
}