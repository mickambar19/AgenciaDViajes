#ifndef MENUHOTELES2_H
#define MENUHOTELES2_H

#include <QWidget>
#include <iostream>
#include <fstream>
#include "hotel.h"
#include "indicehotel.h"
using namespace std;

namespace Ui {
class MenuHoteles2;
}

class MenuHoteles2 : public QWidget
{
    Q_OBJECT

public:
    explicit MenuHoteles2(QWidget *parent = 0);
    ~MenuHoteles2();

private slots:
    void on_botonAceptarAgregaHotel_clicked();
    void cargar_Paises();
    void limpiarTablaHoteles();
    void on_botonActualizarHoteles_clicked();

    void on_botonBuscarModHoteles_clicked();

    void on_botonEliminarModHoteles_clicked();

private:
    Ui::MenuHoteles2 *ui;
};

#endif // MENUHOTELES2_H
