#ifndef MENUHOTELES2_H
#define MENUHOTELES2_H

#include <QWidget>
#include <iostream>
#include <fstream>
#include "hotel.h"
#include "indicehotel.h"
#include "listasimple.h"
#include "secundario.h"
#include "nodosecundario.h"

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
    void limpiarTablaMod();
    void cargarIndices();
    void ligarlista(NodoSecundario bus);
    void seguimiento(NodoSecundario bus);
    void on_botonActualizarHoteles_clicked();

    void on_botonBuscarModHoteles_clicked();

    void on_botonEliminarModHoteles_clicked();

    void on_tabWidget_tabBarClicked(int index);

    void on_botonGuardarModHoteles_clicked();

    void on_guardarIndices_clicked();

    void on_mostrarLista_clicked();

    void on_mostrarListaSecundaria_clicked();

private:
    Ui::MenuHoteles2 *ui;
    ListaSimple<IndiceHotel> l;
    ListaSimple<NodoSecundario> lsecundaria;
    int numpos;
};


#endif // MENUHOTELES2_H
