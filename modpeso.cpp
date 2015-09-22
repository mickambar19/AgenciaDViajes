#include "modpeso.h"
#include "ui_modpeso.h"

ModPeso::ModPeso(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModPeso)
{
    ui->setupUi(this);
}

ModPeso::~ModPeso()
{
    delete ui;
}

void ModPeso::pasar(QTableWidget *tabla, int fila, int columna, string pesoActual)
{
    vuelosTabla = tabla;
    filaI = fila;
    columnaI = columna;
    pesoActualI = pesoActual;
    ui->label->setText("Fila Seleccionada: "+QString::number(fila)+"\nColumna Seleccionada: "+QString::number(columna)+"\nPeso ACtual: "+QString::fromStdString(pesoActual));
}

void ModPeso::on_pushOkNuevoPeso_clicked()
{
    QTableWidgetItem *remplazo;
    remplazo = new QTableWidgetItem(ui->nuevoPeso->text());
    QTableWidgetItem *remplazo2;
    remplazo2 = new QTableWidgetItem(ui->nuevoPeso->text());
    vuelosTabla->setItem(filaI,columnaI,remplazo);
    vuelosTabla->setItem(columnaI,filaI,remplazo2);
    this->close();
}
