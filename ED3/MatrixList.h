/* ---------------------------------------
  Fabiana Ferreira Fonseca
  Universidade Federal do Rio de Janeiro
  DRE: 115037241
----------------------------------------*/

#ifndef MATRIXLIST_H
#define MATRIXLIST_H

#include <vector>
#include <map>
#include <iostream>
#include <fstream>

#include "types.h"
#include "Matrix.h"
#include "DiagonalMatrix.h"
#include "SquareMatrix.h"
#include "UpperTriangularMatrix.h"
#include "LowerTriangularMatrix.h"

class MatrixList
{

public:
	MatrixList();

	MatrixList(std::string);

	~MatrixList();

	void readFile(std::string, bool);

	void save(std::string);

	void list();

	Matrix get(char);

	void insert(char, Matrix *);

	void insertIdentity(char, unsigned);

	void remove(char);

	void clear();

private:
	std::map<char, Matrix *> m_matrixList;
};

#endif