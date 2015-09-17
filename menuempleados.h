#ifndef MENUEMPLEADOS_H
#define MENUEMPLEADOS_H

#include <QWidget>

namespace Ui {
class MenuEmpleados;
}

class MenuEmpleados : public QWidget
{
    Q_OBJECT

public:
    explicit MenuEmpleados(QWidget *parent = 0);
    ~MenuEmpleados();

private:
    Ui::MenuEmpleados *ui;
};

#endif // MENUEMPLEADOS_H
