/* ---------------------------------------
  Fabiana Ferreira Fonseca
  Universidade Federal do Rio de Janeiro
  DRE: 115037241
----------------------------------------*/

#ifndef UPPERTRIANGULARMATRIX_H
#define UPPERTRIANGULARMATRIX_H

#include "SquareMatrix.h"

#ifndef types_h
typedef std::vector<std::vector<float>> TypeMatrix;
#endif

class UpperTriangularMatrix : public SquareMatrix
{

public:
	UpperTriangularMatrix(unsigned, unsigned, TypeMatrix);

	UpperTriangularMatrix(const UpperTriangularMatrix &);

	int calculateDeterminant();

	UpperTriangularMatrix operator+(UpperTriangularMatrix);

	UpperTriangularMatrix operator*(UpperTriangularMatrix);

	UpperTriangularMatrix &operator=(const UpperTriangularMatrix &);

	void print();
};

#endif