/* ---------------------------------------
  Fabiana Ferreira Fonseca
  Universidade Federal do Rio de Janeiro
  DRE: 115037241
----------------------------------------*/

#include "UpperTriangularMatrix.h"

UpperTriangularMatrix::UpperTriangularMatrix(unsigned _lines, unsigned _columns, TypeMatrix _m) : SquareMatrix(_lines, _columns, _m) {}

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

Matrix *UpperTriangularMatrix::operator+(const Matrix &matrix) const
{
    TypeMatrix result;

    const UpperTriangularMatrix *pointer = dynamic_cast<const UpperTriangularMatrix *>(&matrix);

    if (!pointer)
    {
        return Matrix::operator+(matrix);
    }

    UpperTriangularMatrix matrix2 = *pointer;

    TypeMatrix m2 = matrix2.getMatrix();

    for (unsigned i = 0; i < columns; i++)
    {
        for (unsigned j = 0; j < lines; j++)
        {
            if (i < j)
                continue;
            result.at(j).at(i) = m.at(j).at(i) + (m2.at(j).at(i));
        }
    }

    return new UpperTriangularMatrix(lines, columns, result);
}

Matrix *UpperTriangularMatrix::operator-(const Matrix &matrix) const
{
    TypeMatrix result;

    const UpperTriangularMatrix *pointer = dynamic_cast<const UpperTriangularMatrix *>(&matrix);

    if (!pointer)
    {
        return Matrix::operator-(matrix);
    }

    UpperTriangularMatrix matrix2 = *pointer;

    TypeMatrix m2 = matrix2.getMatrix();
    for (unsigned i = 0; i < columns; i++)
    {
        for (unsigned j = 0; j < lines; j++)
        {
            if (i < j)
                continue;
            result.at(j).at(i) = m.at(j).at(i) - (m2.at(j).at(i));
        }
    }

    return new UpperTriangularMatrix(lines, columns, result);
}

Matrix *UpperTriangularMatrix::operator*(const Matrix &matrix) const
{
    TypeMatrix result;

    const UpperTriangularMatrix *pointer = dynamic_cast<const UpperTriangularMatrix *>(&matrix);

    if (!pointer)
    {
        return Matrix::operator*(matrix);
    }

    UpperTriangularMatrix matrix2 = *pointer;

    TypeMatrix m2 = matrix2.getMatrix();

    for (unsigned i = 0; i < columns; i++)
    {
        for (unsigned j = 0; j < lines; j++)
        {
            if (i < j)
                continue;
            result.at(j).at(i) = m.at(j).at(i) - (m2.at(j).at(i));
        }
    }

    return new UpperTriangularMatrix(lines, columns, result);
}

Matrix *UpperTriangularMatrix::operator*(float scalar) const
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

    return new UpperTriangularMatrix(lines, columns, result);
}