/* ---------------------------------------
  Fabiana Ferreira Fonseca
  Universidade Federal do Rio de Janeiro
  DRE: 115037241
----------------------------------------*/

#ifndef PINO_H
#define PINO_H

#include "Pilha.h"

class Pino : public Pilha
{
public:
    Pino(unsigned num_discos);
    void print();
};

#endif
