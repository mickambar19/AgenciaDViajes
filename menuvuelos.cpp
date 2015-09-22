#include "menuvuelos.h"
#include "ui_menuvuelos.h"

MenuVuelos::MenuVuelos(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuVuelos)
{
    ui->setupUi(this);
}

MenuVuelos::~MenuVuelos()
{
    delete ui;
}
