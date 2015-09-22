#ifndef MENU_H
#define MENU_H
#include "menudestinos.h"
#include "menuempleados.h"
#include "menuvuelos.h"
#include <QWidget>

namespace Ui {
class Menu;
}

class Menu : public QWidget
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = 0);
    ~Menu();

private slots:
    void on_botonDestino_clicked();

    void on_botonEmpleados_clicked();

    void on_botonVuelos_clicked();

private:
    Ui::Menu *ui;
    MenuDestinos *menuDestino;
    MenuEmpleados *menuEmpleado;
    MenuVuelos *menuVuelos;

};

#endif // MENU_H
