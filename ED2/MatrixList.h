/* ---------------------------------------
  Fabiana Ferreira Fonseca
  Universidade Federal do Rio de Janeiro
  DRE: 115037241
----------------------------------------*/

#include <vector>
#include <map>
#include <iostream>
#include <fstream>

#include "types.h"

class MatrixList
{
private:
    std::map<char, Matrix> m_matrixList;

public:
    MatrixList();

    MatrixList(std::string);

    void readFile(std::string, bool);

    void save(std::string);

    void list();

    Matrix get(char);

    void insert(char, Matrix);

    void insertIdentity(char, unsigned);

    void remove(char);

    void clear();
};