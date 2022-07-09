#ifndef FILAENCAD_H_INCLUDED
#define FILAENCAD_H_INCLUDED

#include "No.h"

class FilaEncad
{
private:
    No *inicio;
    No *fim;
public:
    FilaEncad();
    ~FilaEncad();
    int getInicio();
    void enfileira(int val);
    int desenfileira();
    bool vazia();
    void imprime();
    FilaEncad* reorganiza(FilaEncad *f);
};


#endif // FILAENCAD_H_INCLUDED
