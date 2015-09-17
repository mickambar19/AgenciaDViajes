#include "menuempleados.h"
#include "ui_menuempleados.h"

MenuEmpleados::MenuEmpleados(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuEmpleados)
{
    ui->setupUi(this);
}

MenuEmpleados::~MenuEmpleados()
{
    delete ui;
}
