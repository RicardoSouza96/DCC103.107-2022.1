#ifndef LISTADESCRI_H_INCLUDED
#define LISTADESCRI_H_INCLUDED
#include "No.h"

class ListaDescri
{
public:
    ListaDescri();
    ~ListaDescri();
    void insereInicio(int val);
    void insereFinal(int val);
    void removeInicio();
    void removeFinal();
    bool busca(int val);
    void imprime();
    void insereApos(int val, int x); //val será inserido após x
private:
    No *primeiro; // ponteiro para o primeiro
    No *ultimo; // ponteiro para o ultimo
    int n; // total de nos
};

#endif // LISTAENCAD_H_INCLUDED
