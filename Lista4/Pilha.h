/* ---------------------------------------
  Fabiana Ferreira Fonseca
  Universidade Federal do Rio de Janeiro
  DRE: 115037241
----------------------------------------*/

#ifndef PILHA_H
#define PILHA_H

#include <iostream>
#include <vector>

class Pilha
{
protected:
    std::vector<unsigned> pilha;

public:
    void push(unsigned elemento);
    unsigned pop(void);
};

#endif
