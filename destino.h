#ifndef DESTINO_H
#define DESTINO_H
#include <iostream>
#include <cstring> //Para copiar string to char y comparar
#define MAX_CARACTERES 35
using namespace std;
class Destino
{
private:
    int codigoDestino;
    char nombreDestino[MAX_CARACTERES];
    char tipoDestino[MAX_CARACTERES];
    char estatusDestino[MAX_CARACTERES];
public:
    Destino();

    int getCodigoDestino() const;
    void setCodigoDestino(int value);
    string getNombreDestino() const;
    void setNombreDestino(string value);
    string getTipoDestino() const;
    void setTipoDestino(string value);
    string getEstatusDestino() const;
    void setEstatusDestino(string value);
};

#endif // DESTINO_H
