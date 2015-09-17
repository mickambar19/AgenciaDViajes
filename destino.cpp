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

void Destino::guardar()
{
    ofstream esc("Destinos.txt",ios::app);
    int tamanio;
    char buffer[MAX_CARACTERES];
    itoa(codigoDestino,buffer,10);
    tamanio = strlen(buffer);
    esc.write((char *)&tamanio,sizeof(int));
    esc.write((char *)&buffer,tamanio);
    tamanio = strlen(nombreDestino);
    esc.write((char *)&tamanio,sizeof(int));
    esc.write((char *)&nombreDestino,tamanio);
    tamanio = strlen(tipoDestino);
    esc.write((char *)&tamanio,sizeof(int));
    esc.write((char *)&tipoDestino,tamanio);
    tamanio = strlen(estatusDestino);
    esc.write((char *)&tamanio,sizeof(int));
    esc.write((char *)&estatusDestino,tamanio);
    esc.close();

}
Destino::Destino()
{

}

