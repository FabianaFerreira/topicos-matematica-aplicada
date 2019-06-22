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

	float calculateDeterminant ();

	Matrix *operator+(const Matrix &) const;

	Matrix *operator-(const Matrix &) const;

	Matrix *operator*(const Matrix &) const;

	Matrix *operator*(float) const;
};

#endif
