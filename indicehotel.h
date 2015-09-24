#ifndef INDICEHOTEL_H
#define INDICEHOTEL_H

class IndiceHotel
{
public:
    long int posicion;
    int llave;//CodigoDelHotel
public:
    IndiceHotel();
    long getPosicion() const;
    void setPosicion(long value);
    int getLlave() const;
    void setLlave(int value);
};

#endif // INDICEHOTEL_H
