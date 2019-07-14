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

float UpperTriangularMatrix::calculateDeterminant()
{
    float determinant = 1;
    for (unsigned i = 0; i < lines; i++)
    {
        determinant *= m.at(i).at(i);
    }

    return determinant;
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

    //Initializing result matrix with zeros
    for (unsigned i = 0; i < lines; i++)
    {
        result.push_back(std::vector<float>(columns, 0));
    }

    for (int i = 0; i < lines; i++)
    {
        int j = columns - 1;
        do
        {
            result.at(i).at(j) = m.at(i).at(j) - m2.at(i).at(j);
            j--;
        } while (j >= i);
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

    //Initializing result matrix with zeros
    for (unsigned i = 0; i < lines; i++)
    {
        result.push_back(std::vector<float>(columns, 0));
    }

    for (int i = 0; i < lines; i++)
    {
        int j = columns - 1;
        do
        {
            result.at(i).at(j) = m.at(i).at(j) - m2.at(i).at(j);
            j--;
        } while (j >= i);
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

    //Initializing result matrix with zeros
    for (unsigned i = 0; i < lines; i++)
    {
        result.push_back(std::vector<float>(columns, 0));
    }

    for (int i = 0; i < lines; i++)
    {
        int j = columns - 1;
        do
        {
            for (int k = columns - 1; k >= i; k--)
            {
                result.at(i).at(j) += m.at(i).at(k) * m2.at(k).at(j);
            }
            j--;
        } while (j >= i);
    }

    return new UpperTriangularMatrix(lines, columns, result);
}

Matrix *UpperTriangularMatrix::operator*(float scalar) const
{
    TypeMatrix result;

    //Initializing result matrix with zeros
    for (unsigned i = 0; i < lines; i++)
    {
        result.push_back(std::vector<float>(columns, 0));
    }

    for (int i = 0; i < lines; i++)
    {
        int j = columns - 1;
        do
        {
            result.at(i).at(j) = m.at(i).at(j) * scalar;
            j--;
        } while (j >= i);
    }

    return new UpperTriangularMatrix(lines, columns, result);
}