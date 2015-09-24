#include "hotel.h"
#include <cstring>


int Hotel::getCodigo() const
{
    return codigo;
}

void Hotel::setCodigo(int value)
{
    codigo = value;
}

int Hotel::getCodigoPais() const
{
    return codigoPais;
}

void Hotel::setCodigoPais(int value)
{
    codigoPais = value;
}

char *Hotel::getNombreHotel()
{
    return nombreHotel;
}

void Hotel::setNombreHotel(string value)
{
    strcpy(nombreHotel,value.c_str());
}

int Hotel::getTarifa() const
{
    return tarifa;
}

void Hotel::setTarifa(int value)
{
    tarifa = value;
}

char* Hotel::getTipo()
{
    return tipo;
}

void Hotel::setTipo(string value)
{
    strcpy(tipo,value.c_str());
}
Hotel::Hotel()
{
}
