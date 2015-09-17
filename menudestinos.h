#ifndef MENUDESTINOS_H
#define MENUDESTINOS_H
#include <iostream>
#include <fstream>
#include "destino.h"
#include <string>
using namespace std;
#include <QWidget>
#include <QMessageBox>
namespace Ui {
class MenuDestinos;
}

class MenuDestinos : public QWidget
{
    Q_OBJECT

public:
    explicit MenuDestinos(QWidget *parent = 0);
    ~MenuDestinos();
private slots:

    void on_botonAceptarAgregar_clicked();

private:
    Ui::MenuDestinos *ui;
};

#endif // MENUDESTINOS_H
