#ifndef MENUVUELOS_H
#define MENUVUELOS_H

#include <QWidget>

namespace Ui {
class MenuVuelos;
}

class MenuVuelos : public QWidget
{
    Q_OBJECT

public:
    explicit MenuVuelos(QWidget *parent = 0);
    ~MenuVuelos();

private:
    Ui::MenuVuelos *ui;
};

#endif // MENUVUELOS_H
