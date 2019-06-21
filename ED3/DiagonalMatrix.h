/* ---------------------------------------
  Fabiana Ferreira Fonseca
  Universidade Federal do Rio de Janeiro
  DRE: 115037241
----------------------------------------*/

#ifndef DIAGONALMATRIX_H
#define DIAGONALMATRIX_H

#include "Matrix.h"

#ifndef types_h
typedef std::vector<std::vector<float>> TypeMatrix;
#endif

class DiagonalMatrix : public Matrix
{

public:
	DiagonalMatrix(unsigned, unsigned, TypeMatrix);

	DiagonalMatrix(const DiagonalMatrix &);

	DiagonalMatrix &operator=(const DiagonalMatrix &);

	void print();

	virtual DiagonalMatrix *operator+(DiagonalMatrix matrix)
	{
		TypeMatrix result;
		TypeMatrix m2 = matrix.getMatrix();

		std::cout << "SOMA DIAGONAL" << std::endl;
		//Creating m1Lines x m2Columns matrix and inserting zeros
		for (unsigned i = 0; i < lines; i++)
		{
			result.push_back(std::vector<float>(columns, 0));
		}

		for (unsigned i = 0; i < lines; i++)
		{
			result.at(i).at(i) = m.at(i).at(i) + m2.at(i).at(i);
		}
		return new DiagonalMatrix(lines, columns, result);
	};

	DiagonalMatrix operator-(DiagonalMatrix);

	DiagonalMatrix operator*(DiagonalMatrix);

	Matrix operator*(float);
};

#endif
