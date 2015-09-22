#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    QPixmap pix("../picmenu.jpg");
    ui->pictureMenu->setPixmap(pix);
    menuDestino = new MenuDestinos;
    menuEmpleado = new MenuEmpleados;
    menuVuelos = new MenuVuelos;
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_botonDestino_clicked()
{
    menuDestino->show();
}

void Menu::on_botonEmpleados_clicked()
{
    menuEmpleado->show();
}

void Menu::on_botonVuelos_clicked()
{
    menuVuelos->show();
}
