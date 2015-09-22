#ifndef MODPESO_H
#define MODPESO_H
#include <QTableWidget>
#include <QWidget>

#include <iostream>
using namespace std;
namespace Ui {
class ModPeso;
}

class ModPeso : public QWidget
{
    Q_OBJECT

public:
    explicit ModPeso(QWidget *parent = 0);
    ~ModPeso();
    void pasar(QTableWidget *tabla,int fila,int columna, string pesoActual);
private slots:


    void on_pushOkNuevoPeso_clicked();

private:
    Ui::ModPeso *ui;
    QTableWidget *vuelosTabla;
    int filaI;
    int columnaI;
    string pesoActualI;
};

#endif // MODPESO_H
