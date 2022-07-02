#include <iostream>
#include "ListaDescri.h"

using namespace std;

ListaDescri::ListaDescri()
{
    cout << "Criando objeto ListaDescri" << endl;
    primeiro = NULL;
    ultimo = NULL;
    n = 0;
}

ListaDescri::~ListaDescri()
{
    cout << "Destruindo objeto ListaDescri" << endl;
    No *p = primeiro;
    while(p != NULL)
    {
        No *t = p->getProx();
        delete p;
        p = t;
    }
}

void ListaDescri::insereInicio(int val)
{
    No* p = new No();
    p->setInfo(val);
    p->setProx(primeiro);

    primeiro = p;
    n++;

    if(n == 1)
        ultimo = p;
}

///Exercicio 1, slide 54
void ListaDescri::insereFinal(int val)
{
    No* p = new No();
    p->setInfo(val);
    p->setProx(NULL);

    if(ultimo != NULL)
        ultimo->setProx(p);
    ultimo = p;
    n++;

    if(n == 1)
        primeiro = p;
}

void ListaDescri::removeInicio()
{
    No* p;
    if(primeiro != NULL)
    {
        p = primeiro;
        primeiro = p->getProx();
        delete p;
        n--;

        if(n == 0)
            ultimo = NULL;
    }
    else
        cout << "ERRO: lista vazia!" << endl;
}

///Exercicio 1, slide 54
void ListaDescri::removeFinal()
{
    No* p;
    if(ultimo != NULL)
    {
        if(primeiro == ultimo) //lista com apenas 1 nó
        {
            primeiro = NULL;
            p = NULL;
        }
        else //lista com 2 ou mais nós
        {
            p = primeiro;
            while(p->getProx() != ultimo) //faz p andar até o penultimo
                p = p->getProx();
            p->setProx(NULL);
        }
        delete ultimo;
        ultimo = p;
        n--;
    }
    else
        cout << "ERRO: lista vazia!" << endl;
}

bool ListaDescri::busca(int val)
{
    No *p;
    for(p = primeiro; p != NULL; p = p->getProx())
        if(p->getInfo() == val)
            return true;
    return false;
}

void ListaDescri::imprime()
{
    No *p;
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

///Exercício 3, slide 54
void ListaDescri::insereApos(int val, int x)
{
    No* aux = new No();
    aux->setInfo(val);
    int cont = 0;

    No *p;
    for(p = primeiro; p != NULL; p = p->getProx())
    {
        if(p->getInfo() == x)
        {
            aux->setProx(p->getProx());
            p->setProx(aux);
            n++;
            cont++;
        }
    }
    if(cont == 0)
        cout << "Valor nao encontrado na lista" << endl;
}
