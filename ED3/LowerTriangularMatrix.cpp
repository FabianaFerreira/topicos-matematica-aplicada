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

float LowerTriangularMatrix::calculateDeterminant()
{
    float determinant = 1;
    for (unsigned i = 0; i < lines; i++)
    {
        determinant *= m.at(i).at(i);
    }

    return determinant;
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

    //Initializing result matrix with zeros
    for (unsigned i = 0; i < lines; i++)
    {
        result.push_back(std::vector<float>(columns, 0));
    }

    for (unsigned i = 0; i < lines; i++)
    {
        for (unsigned j = 0; j <= i; j++)
        {
            result.at(i).at(j) = m.at(i).at(j) + (m2.at(i).at(j));
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

    //Initializing result matrix with zeros
    for (unsigned i = 0; i < lines; i++)
    {
        result.push_back(std::vector<float>(columns, 0));
    }

    for (unsigned i = 0; i < lines; i++)
    {
        for (unsigned j = 0; j <= i; j++)
        {
            result.at(i).at(j) = m.at(i).at(j) - (m2.at(i).at(j));
        }
    }

    return new LowerTriangularMatrix(lines, columns, result);
}

Matrix *LowerTriangularMatrix::operator*(float scalar) const
{
    TypeMatrix result;

    //Initializing result matrix with zeros
    for (unsigned i = 0; i < lines; i++)
    {
        result.push_back(std::vector<float>(columns, 0));
    }

    for (unsigned i = 0; i < lines; i++)
    {
        for (unsigned j = 0; j <= i; j++)
        {
            result.at(i).at(j) = m.at(i).at(j) * scalar;
        }
    }

    return new LowerTriangularMatrix(lines, columns, result);
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

    //Initializing result matrix with zeros
    for (unsigned i = 0; i < lines; i++)
    {
        result.push_back(std::vector<float>(columns, 0));
    }

    for (unsigned i = 0; i < lines; i++)
    {
        for (unsigned j = 0; j <= i; j++)
        {
            for (unsigned k = 0; k <= i; k++)
            {
                result.at(i).at(j) += m.at(i).at(k) * m2.at(k).at(j);
            }
        }
    }

    return new LowerTriangularMatrix(lines, columns, result);
}