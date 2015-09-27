#ifndef HOTEL_H
#define HOTEL_H
#define MAX_CARS 30
#include <iostream>
using namespace std;
class Hotel
{
public:
    char codigo[MAX_CARS];
    char paisDeHotel[MAX_CARS];
    char nombreHotel[MAX_CARS];
    char tarifa[MAX_CARS];
    char tipo[MAX_CARS];
public:
    Hotel();
    string getCodigo() const;
    void setCodigo(string value);
    string getPaisDeHotel() const;
    void setPaisDeHotel(string value);
    string getNombreHotel() const;
    void setNombreHotel(string value);
    string getTarifa() const;
    void setTarifa(string value);
    string getTipo() const;
    void setTipo(string value);
};

#endif // HOTEL_H
