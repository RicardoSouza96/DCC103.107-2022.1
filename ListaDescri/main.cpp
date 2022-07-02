#include <iostream>
#include "ListaDescri.h"

using namespace std;

int main()
{
    ListaDescri lista;

    lista.insereInicio(20);
    lista.insereInicio(30);
    lista.insereInicio(-10);
    lista.insereInicio(15);
    lista.imprime();

    lista.insereApos(12, 30);
    lista.imprime();

    return 0;
}
