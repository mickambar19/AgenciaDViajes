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
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_botonDestino_clicked()
{
    menuDestino->show();
}
