#ifndef MENUVUELOS_H
#define MENUVUELOS_H
#include <iostream>
#include <fstream>
#include <cstring>
#include <QMessageBox>
#include <QWidget>
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

private:
    Ui::MenuVuelos *ui;
};

#endif // MENUVUELOS_H
