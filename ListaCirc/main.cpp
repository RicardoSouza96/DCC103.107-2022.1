#include <iostream>
#include "ListaDupla.h"

using namespace std;

int main()
{
    ListaDupla lista;

    lista.insereInicio(20);
    lista.insereInicio(30);
    lista.insereInicio(-10);
    lista.insereInicio(15);
    lista.imprimir();

    lista.insereFinal(12);
    lista.imprimir();

    lista.removeFinal();
    lista.imprimir();

    lista.imprimirReverso();

    return 0;
}
