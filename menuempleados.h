#ifndef MENUEMPLEADOS_H
#define MENUEMPLEADOS_H
#include <iostream>
#include <fstream>
#include "empleado.h"
#include <string>
#include <QWidget>
#include <QMessageBox>
#include <QTableWidgetItem>
using namespace std;
namespace Ui {
class MenuEmpleados;
}

class MenuEmpleados : public QWidget
{
    Q_OBJECT

public:
    explicit MenuEmpleados(QWidget *parent = 0);
    ~MenuEmpleados();
    void limpiarVentana();
    void limpiarTablaEmpleados();
    int contarRegistros();
    void reEnumerar();

private slots:
    void on_botonAceptarAgregaEmpleado_clicked();

    void on_botonActualizarEmpleados_clicked();

    void on_botonBuscarModEmpleados_clicked();

    void on_botonGuardarModEmpleados_clicked();

    void on_botonEliminarModEmpleados_clicked();

private:
    Ui::MenuEmpleados *ui;
};

#endif // MENUEMPLEADOS_H
