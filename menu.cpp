#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    QPixmap pix("../picmenu.jpg");
    ui->pictureMenu->setPixmap(pix);
}

Menu::~Menu()
{
    delete ui;
}
