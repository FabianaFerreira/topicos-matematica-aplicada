/* ---------------------------------------
  Fabiana Ferreira Fonseca
  Universidade Federal do Rio de Janeiro
  DRE: 115037241
----------------------------------------*/

#include "Pilha.h"

void Pilha::push(unsigned elemento)
{
    pilha.push_back(elemento);
}

unsigned Pilha::pop(void)
{
    unsigned aux;
    aux = pilha.back();
    pilha.pop_back();
    return aux;
}
