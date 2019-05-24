/* ---------------------------------------
  Fabiana Ferreira Fonseca
  Universidade Federal do Rio de Janeiro
  DRE: 115037241
----------------------------------------*/

#include "Pino.h"

Pino::Pino(unsigned num_discos)
{
    for (unsigned i = num_discos; i > 0; i--)
        push(i);
}

void Pino::print(void)
{
    std::cout << "[ ";
    for (int i = 0; i < pilha.size(); i++)
    {
        std::cout << pilha[i];
        if (i + 1 != pilha.size())
            std::cout << " ";
    }

    std::cout << " ]" << std::endl;
}
