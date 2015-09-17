#include "empleado.h"
#include <fstream>
Empleado::Empleado()
{

}

int Empleado::getCodigoEmpleado() const
{
    return codigoEmpleado;
}

void Empleado::setCodigoEmpleado(int value)
{
    codigoEmpleado = value;
}

void Empleado::setNombreEmpleado(string value)
{
    strcpy(nombreEmpleado , value.c_str());
}

string Empleado::getNombreEmpleado() const
{
    string nombreEmpleadoString;
    nombreEmpleadoString.assign(nombreEmpleado);
    return nombreEmpleadoString;
}

void Empleado::setUsuarioEmpleado(string value)
{
    strcpy(usuarioEmpleado , value.c_str());
}

string Empleado::getUsuarioEmpleado() const
{
    string usuarioEmpleadoString;
    usuarioEmpleadoString.assign(usuarioEmpleado);
    return usuarioEmpleadoString;
}

string Empleado::getTipoEmpleado() const
{
    string tipoEmpleadoString;
    tipoEmpleadoString.assign(tipoEmpleado);
    return tipoEmpleadoString;
}

void Empleado::setTipoEmpleado(string value)
{
    strcpy(tipoEmpleado , value.c_str());
}

string Empleado::getContraseniaEmpleado() const
{
    string contraseniaEmpleadoString;
    contraseniaEmpleadoString.assign(contraseniaEmpleado);
    return contraseniaEmpleadoString;
}

void Empleado::setContraseniaEmpleado(string value)
{
    strcpy(contraseniaEmpleado , value.c_str());
}

void Empleado::guardar()
{
    ofstream esc1("Empleados.txt",ios::app);
    esc1.write((char *)this,sizeof(this));
    esc1.close();

}
