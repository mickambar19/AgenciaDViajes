#ifndef SECUNDARIO_H
#define SECUNDARIO_H
#include <iostream>
#include <fstream>
using namespace std;
class Secundario
{
public:
    char pais[100];
    int primerNodo;
public:
    Secundario();
    void inicializar();
    friend ostream&operator<<(ostream& os,Secundario &d);
    bool operator==(const Secundario &d);
    bool operator<(const Secundario &d);
    bool operator<=(const Secundario &d);
};

#endif // SECUNDARIO_H
