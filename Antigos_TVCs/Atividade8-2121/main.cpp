#include <iostream>
#include "FilaEncad.h"

using namespace std;

int main()
{
    FilaEncad f;
    //inicializa a fila
    f.enfileira(15);
    f.enfileira(85);
    f.enfileira(71);
    f.enfileira(75);
    f.enfileira(62);
    f.enfileira(70);
    f.enfileira(30);
    f.enfileira(92);
    f.enfileira(100);
    f.enfileira(54);

    f.imprime();

    FilaEncad *novaFila;
    novaFila=f.reorganiza(&f);

    novaFila->imprime();

    return 0;
}
