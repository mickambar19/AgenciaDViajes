#ifndef MENUDESTINOS_H
#define MENUDESTINOS_H
#include <iostream>
#include <fstream>
#include "destino.h"
#include <string>
using namespace std;
#include <QWidget>
#include <QMessageBox>
#include <QTableWidgetItem>
namespace Ui {
class MenuDestinos;
}

class MenuDestinos : public QWidget
{
    Q_OBJECT

public:
    explicit MenuDestinos(QWidget *parent = 0);
    ~MenuDestinos();
    void limpiarVentana();
    void limpiarTablaDestinos();
    int contarRegistros();
    void reEnumerar();
private slots:

    void on_botonAceptarAgregar_clicked();

    void on_botonActualizarDestinos_clicked();

    void on_botonBuscarModDest_clicked();

    void on_botonGuardarModDest_clicked();

    void on_botonEliminarDestino_clicked();

private:
    Ui::MenuDestinos *ui;
};

#endif // MENUDESTINOS_H
