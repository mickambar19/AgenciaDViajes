#ifndef MENUVUELOS_H
#define MENUVUELOS_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <QMessageBox>
#include <QWidget>
#include "modpeso.h"
#define MAX_CARTERES 30
using namespace std;


namespace Ui {
class MenuVuelos;
}

class MenuVuelos : public QWidget
{
    Q_OBJECT

public:
    explicit MenuVuelos(QWidget *parent = 0);
    ~MenuVuelos();


private slots:
    void on_botonActuzalizarVuelos_clicked();

    void on_botonGuardarVuelos_clicked();
    void limpiarTabla();
    void cambioEnCelda(int fila, int columna);
    void hacerCambios(int fila, int columna, QString text);

private:
    Ui::MenuVuelos *ui;
    int matrizPesos[30][30];
    ModPeso *modpeso;
};

#endif // MENUVUELOS_H
