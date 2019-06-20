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

	void print();

	DiagonalMatrix operator+(DiagonalMatrix);

	DiagonalMatrix operator-(DiagonalMatrix);

	DiagonalMatrix operator*(DiagonalMatrix);

	// Matrix operator*(unsigned);

	DiagonalMatrix &operator=(const DiagonalMatrix &);
};

#endif
