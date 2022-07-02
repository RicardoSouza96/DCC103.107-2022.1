#include <iostream>
#include "ListaDupla.h"

using namespace std;

ListaDupla::ListaDupla()
{
    cout << "Criando objeto ListaDupla" << endl;
    primeiro = NULL;
    ultimo = NULL;
    n = 0;
}

ListaDupla::~ListaDupla()
{
    NoDuplo *p = primeiro;

    while(p != NULL)
    {
        primeiro = primeiro->getProx();
        delete p;
        p = primeiro;
    }
}

bool ListaDupla::busca(int val)
{
    NoDuplo* p = primeiro;
    while(p != NULL)
    {
        if(p->getInfo() == val)
            return true;
        p = p->getProx();
    }
    return false;
}

void ListaDupla::insereInicio(int val)
{
    NoDuplo *p = new NoDuplo();
    p->setInfo(val);
    p->setProx(primeiro);
    p->setAnt(NULL);
    if(n == 0)
        ultimo = p;
    else
        primeiro->setAnt(p);
    primeiro = p;
    n = n + 1;
}

void ListaDupla::removeInicio()
{
    NoDuplo *p;
    if(primeiro != NULL)
    {
        p = primeiro;
        primeiro = p->getProx();
        delete p;
        n = n - 1;
        if(n == 0)
            ultimo = NULL;
        else
            primeiro->setAnt(NULL);
    }
    else
        cout << "Lista vazia" << endl;
}

void ListaDupla::insereFinal(int val)
{
    NoDuplo *p = new NoDuplo();
    p->setInfo(val);
    p->setProx(NULL);
    p->setAnt(ultimo);
    if(n == 0)
        primeiro = p;
    else
        ultimo->setProx(p);
    ultimo = p;
    n = n+1;
}

void ListaDupla::removeFinal()
{
    NoDuplo *p;
    if(ultimo != NULL)
    {
        p = ultimo;
        ultimo = p->getAnt();
        delete p;
        n = n-1;
        if(n == 0)
            primeiro = NULL;
        else
            ultimo->setProx(NULL);
    }
    else
        cout << "Lista vazia" << endl;
}

void ListaDupla::imprimir()
{
    NoDuplo *p;
    if(primeiro != NULL)
    {
        p = primeiro;
        while(p != NULL)
        {
            cout << p->getInfo() << " ";
            p = p->getProx();
        }
        cout << endl;
    }
    else
        cout << "Lista vazia" << endl;
}
 void ListaDupla::imprimirReverso()
 {
     NoDuplo *p;
     if(ultimo != NULL)
     {
         p = ultimo;
         while(p != NULL)
         {
             cout << p->getInfo() << " ";
             p = p->getAnt();
         }
         cout << endl;
     }
     else
        cout << "Lista vazia" << endl;
 }
