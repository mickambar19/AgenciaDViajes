#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <iostream>
#include <cstring>
#define MAX_CARACT 30
using namespace std;
class Empleado
{
private:
    int codigoEmpleado;
    char nombreEmpleado[MAX_CARACT];
    char usuarioEmpleado[MAX_CARACT];
    char contraseniaEmpleado[MAX_CARACT];
    char tipoEmpleado[MAX_CARACT];
public:
    Empleado();
    int getCodigoEmpleado() const;
    void setCodigoEmpleado(int value);
    string getNombreEmpleado() const;
    void setNombreEmpleado(string value);
    string getTipoEmpleado() const;
    void setTipoEmpleado(string value);
    string getUsuarioEmpleado() const;
    void setUsuarioEmpleado(string value);
    string getContraseniaEmpleado() const;
    void setContraseniaEmpleado(string value);
    void guardar();
};

#endif // EMPLEADO_H
