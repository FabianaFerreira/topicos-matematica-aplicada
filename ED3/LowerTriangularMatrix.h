/* ---------------------------------------
  Fabiana Ferreira Fonseca
  Universidade Federal do Rio de Janeiro
  DRE: 115037241
----------------------------------------*/

#ifndef LOWERTRIANGULARMATRIX_H
#define LOWERTRIANGULARMATRIX_H

#include "SquareMatrix.h"

#ifndef types_h
typedef std::vector<std::vector<float>> TypeMatrix;
#endif

class LowerTriangularMatrix : public SquareMatrix
{

public:
	LowerTriangularMatrix(unsigned, unsigned, TypeMatrix);

	LowerTriangularMatrix(const LowerTriangularMatrix &);

	int calculateDeterminant();

	LowerTriangularMatrix operator+(LowerTriangularMatrix);

	LowerTriangularMatrix operator*(LowerTriangularMatrix);

	LowerTriangularMatrix &operator=(const LowerTriangularMatrix &);

	void print();
};

#endif