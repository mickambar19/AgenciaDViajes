#ifndef MENU_H
#define MENU_H
#include "menudestinos.h"
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

private:
    Ui::Menu *ui;
    MenuDestinos *menuDestino;

};

#endif // MENU_H
