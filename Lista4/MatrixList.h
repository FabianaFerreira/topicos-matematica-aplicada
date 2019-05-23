/* ---------------------------------------
  Fabiana Ferreira Fonseca
  Universidade Federal do Rio de Janeiro
  DRE: 115037241
----------------------------------------*/

#include <vector>
#include <map>
#include <iostream>
#include <fstream>
#include <regex> 
#include <sstream>
#include "types.h"

class MatrixList
{
private:
    std::map<unsigned, Matrix> m_matrixList;

public:
    MatrixList(std::string);

    void list();

    void clear();
};