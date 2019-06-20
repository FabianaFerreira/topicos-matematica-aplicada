/* ---------------------------------------
  Fabiana Ferreira Fonseca
  Universidade Federal do Rio de Janeiro
  DRE: 115037241
----------------------------------------*/

#ifndef MATRIX_H
#define MATRIX_H

#include <sstream>
#include <vector>
#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>

#ifndef types_h
typedef std::vector<std::vector<float>> TypeMatrix;
#endif

class Matrix
{

public:
	Matrix();

	Matrix(unsigned, unsigned, TypeMatrix);

	Matrix(const Matrix &);

	~Matrix();

	Matrix transposeMatrix();

	unsigned getLines();

	unsigned getColumns();

	TypeMatrix getMatrix();

	void setMatrix(TypeMatrix);

	virtual void print()
	{
		std::cout << "Sou Geral" << std::endl;
	}

	// OVERLOADED OPERATOR *
	virtual Matrix operator+(Matrix matrix)
	{
		TypeMatrix result(m);
		TypeMatrix m2 = matrix.getMatrix();
		for (unsigned i = 0; i < lines; i++)
		{
			for (unsigned j = 0; j < columns; j++)
			{
				result.at(i).at(j) = m.at(i).at(j) + (m2.at(i).at(j));
			}
		}

		return Matrix(lines, matrix.getColumns(), result);
	}

	//OVERLOADED OPERATOR *
	virtual Matrix operator-(Matrix matrix)
	{
		TypeMatrix result(m);
		TypeMatrix m2 = matrix.getMatrix();
		for (unsigned i = 0; i < lines; i++)
		{
			for (unsigned j = 0; j < columns; j++)
			{
				result.at(i).at(j) = m.at(i).at(j) - (m2.at(i).at(j));
			}
		}

		return Matrix(lines, matrix.getColumns(), result);
	}

	//OVERLOADED OPERATOR *
	virtual Matrix operator*(Matrix matrix)
	{
		TypeMatrix result;
		//Creating m1Lines x m2Columns matrix and inserting zeros
		for (unsigned i = 0; i < lines; i++)
		{
			result.push_back(std::vector<float>(matrix.getColumns(), 0));
		}

		for (unsigned i = 0; i < lines; i++)
		{
			for (unsigned j = 0; j < matrix.getColumns(); j++)
			{
				for (unsigned k = 0; k < m.at(i).size(); k++)
				{
					result.at(i).at(j) += m.at(i).at(k) * matrix.getMatrix().at(k).at(j);
				}
			}
		}
		return Matrix(lines, matrix.getColumns(), result);
	}

	virtual Matrix operator*(unsigned scalar)
	{
		TypeMatrix result(m);
		for (unsigned i = 0; i < lines; i++)
		{
			for (unsigned j = 0; j < columns; j++)
				result.at(i).at(j) = m.at(i).at(j) * scalar;
		}
		return Matrix(lines, columns, result);
	}

protected:
	unsigned lines, columns;

	TypeMatrix m;
};

#endif
