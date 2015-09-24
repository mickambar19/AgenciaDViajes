#ifndef HOTEL_H
#define HOTEL_H
#define MAX_CARS 30
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
};

#endif // HOTEL_H
