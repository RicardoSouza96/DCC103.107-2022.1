#include <iostream>
#include "FilaEncad.h"

using namespace std;

FilaEncad::FilaEncad()
{
    inicio=NULL;
    fim=NULL;
}

FilaEncad ::~FilaEncad ()
{
    No *p = inicio;
    while(inicio != NULL)
    {
        inicio = p->getProx();
        delete p;
        p = inicio;
    }
}

bool FilaEncad::vazia() // verifica se fila esta vazia
{
    if(inicio == NULL)
        return true;
    else
        return false;
}

int FilaEncad::getInicio()
{
    if(inicio != NULL)
        return inicio->getInfo();
    else
    {
        cout << "ERRO: Fila vazia!" << endl;
        exit(1);
    }
}

void FilaEncad::enfileira(int val)
{
    No *p = new No();
    p->setInfo(val);
    p->setProx(NULL);
    if(fim == NULL)
        inicio = p; // insere o primeiro No
    else
        fim->setProx(p); // liga No p na fila
    fim = p; // No p passa a ser o ultimo
}

int FilaEncad::desenfileira()
{
    No *p;
    if(inicio != NULL)
    {
        p = inicio;
        inicio = p->getProx();
        if(inicio == NULL)
            fim = NULL; // a fila esvaziou
        int val = p->getInfo();
        delete p; // exclui o No do inicio
        return val;
    }
    cout << "ERRO: Fila vazia" << endl;
    exit(1);
}

void FilaEncad::imprime()
{
    No *p;
    if(inicio!=NULL)
    {
        p=inicio;
        while(p!=NULL)
        {
            cout << p->getInfo() << " ";
            p=p->getProx();
        }
        cout << endl;
    }
}

FilaEncad* FilaEncad::reorganiza(FilaEncad *f)
{
    FilaEncad* novaFila = new FilaEncad;
    No* p;
    int val;
    if(inicio!=NULL)
    {
        p=inicio;
        while(p!=NULL)
        {
            if(p->getInfo()>70)
            {
                val=p->getInfo();
                novaFila->enfileira(val);
            }
            p=p->getProx();
        }
    }
    return novaFila;
}
