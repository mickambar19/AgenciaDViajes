#include "hotel.h"
#include <cstring>

string Hotel::getCodigo() const
{
    return codigo;
}

void Hotel::setCodigo(string value)
{
    strcpy(codigo , value.c_str());
}

string Hotel::getPaisDeHotel() const
{
    return paisDeHotel;
}

void Hotel::setPaisDeHotel(string value)
{
    strcpy(paisDeHotel , value.c_str());
}

string Hotel::getNombreHotel() const
{
    return nombreHotel;
}

void Hotel::setNombreHotel(string value)
{
    strcpy(nombreHotel , value.c_str());
}

string Hotel::getTarifa() const
{
    return tarifa;
}

void Hotel::setTarifa(string value)
{
    strcpy(tarifa , value.c_str());
}

string Hotel::getTipo() const
{
    return tipo;
}

void Hotel::setTipo(string value)
{
    strcpy(tipo , value.c_str());
}
Hotel::Hotel()
{
}
