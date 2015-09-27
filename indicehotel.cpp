#include "indicehotel.h"
#include <cstring>


long IndiceHotel::getPosicion() const
{
    return posicion;
}

void IndiceHotel::setPosicion(long value)
{
    posicion = value;
}

string IndiceHotel::getLlave() const
{
    string nombreDestinoString;
    nombreDestinoString.assign(llave);
    return nombreDestinoString;
    return llave;
}

void IndiceHotel::setLlave(string value)
{
    strcpy(llave , value.c_str());
}
IndiceHotel::IndiceHotel()
{
}
