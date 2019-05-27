/* ---------------------------------------
  Fabiana Ferreira Fonseca
  Universidade Federal do Rio de Janeiro
  DRE: 115037241
----------------------------------------*/

#include <vector>
#include <map>
#include <iostream>
#include <fstream>

#include "Aluno.h"

class Lista
{
  private:
    std::map<std::string, Aluno> lista;

  public:
    Lista();

    // Lista(std::string);

    // void readFile(std::string, bool);

    void save(std::string);

    void list();

    std::vector<Aluno> get(std::string, bool);

    void insert(std::string, Aluno);

    void remove(std::string);

    void clear();
};