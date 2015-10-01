#ifndef NODOSECUNDARIO_H
#define NODOSECUNDARIO_H
#include <iostream>
#include "nododoble.h"
class NodoSecundario
{
    public:
    char pais[100];
    char codigo[100];
    NodoDoble<NodoSecundario>* sigNodo;
    public:
    NodoSecundario();
    friend ostream&operator<<(ostream& os,NodoSecundario &d);
    bool operator==(const NodoSecundario &d);
    bool operator<(const NodoSecundario &d);
    bool operator<=(const NodoSecundario &d);
    bool operator!=(const NodoSecundario &d);
};

#endif // NODOSECUNDARIO_H
