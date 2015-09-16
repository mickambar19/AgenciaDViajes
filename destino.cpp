#include "destino.h"


int Destino::getCodigoDestino() const
{
    return codigoDestino;
}

void Destino::setCodigoDestino(int value)
{
    codigoDestino = value;
}

string Destino::getNombreDestino() const
{
    string nombreDestinoString;
    nombreDestinoString.assign(nombreDestino);
    return nombreDestinoString;
}

void Destino::setNombreDestino(string value)
{
    strcpy(nombreDestino , value.c_str());
}

string Destino::getTipoDestino() const
{
    string tipoDestinoString;
    tipoDestinoString.assign(tipoDestino);
    return tipoDestinoString;
}

void Destino::setTipoDestino(string value)
{
    strcpy(tipoDestino , value.c_str());
}

string Destino::getEstatusDestino() const
{
    string estatusDestinoString;
    estatusDestinoString.assign(tipoDestino);
    return estatusDestinoString;
}

void Destino::setEstatusDestino(string value)
{
    strcpy(estatusDestino , value.c_str());
}
Destino::Destino()
{

}

