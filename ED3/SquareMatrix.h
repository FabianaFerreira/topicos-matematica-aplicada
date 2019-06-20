/* ---------------------------------------
  Fabiana Ferreira Fonseca
  Universidade Federal do Rio de Janeiro
  DRE: 115037241
----------------------------------------*/

#ifndef SQUAREMATRIX_H
#define SQUAREMATRIX_H

#include "Matrix.h"

#ifndef types_h
typedef std::vector<std::vector<float>> TypeMatrix;
#endif

class SquareMatrix : public Matrix
{

public:
	SquareMatrix(unsigned, unsigned, TypeMatrix);

	SquareMatrix(const SquareMatrix &);

	void print();

	SquareMatrix &operator=(const SquareMatrix &);

	unsigned calculateTrace();
};

#endif