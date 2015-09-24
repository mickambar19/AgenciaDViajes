#ifndef HOTEL_H
#define HOTEL_H
#define MAX_CARS 30
#include <iostream>
using namespace std;
class Hotel
{
public:
    int codigo;
    int codigoPais;
    char nombreHotel[MAX_CARS];
    int tarifa;
    char tipo[MAX_CARS];
public:
    Hotel();
    int getCodigo() const;
    void setCodigo(int value);
    int getCodigoPais() const;
    void setCodigoPais(int value);
    char *getNombreHotel();
    void setNombreHotel(string value);
    int getTarifa() const;
    void setTarifa(int value);
    char* getTipo();
    void setTipo(string value);
};

#endif // HOTEL_H
