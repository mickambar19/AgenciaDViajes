#ifndef INDICEHOTEL_H
#define INDICEHOTEL_H
#include <iostream>
using namespace std;
class IndiceHotel
{
public:
    long int posicion;
    char llave[30];//CodigoDelHotel
public:
    IndiceHotel();
    long getPosicion() const;
    void setPosicion(long value);
    string getLlave() const;
    void setLlave(string value);
};

#endif // INDICEHOTEL_H
