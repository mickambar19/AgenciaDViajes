#include "menuvuelos.h"
#include "ui_menuvuelos.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
MenuVuelos::MenuVuelos(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuVuelos)
{
    ui->setupUi(this);

    memset(matrizPesos,0,sizeof(matrizPesos));
    connect(ui->tablaVuelos, SIGNAL(cellClicked(int, int)), this, SLOT(cambioEnCelda(int,int)));
    on_botonActuzalizarVuelos_clicked();
    modpeso = new ModPeso;
}

MenuVuelos::~MenuVuelos()
{
    delete ui;
}


void MenuVuelos::on_botonActuzalizarVuelos_clicked()
{
    char cadenaLeida[MAX_CARTERES];
    int tamanioCadena;
    int i, j;
    int col, fil;
    QStringList paises;
    QTableWidgetItem *elemento;
    ifstream lee("Destinos.txt",ios::app);
    Qt::ItemFlags banderas;
    i=1;
    j = 0;

    if(!lee.good())
    {
        QMessageBox msgBox;
        msgBox.setText("No existe el archivo de Destinos");
        msgBox.exec();
    }else
    {
        while(!lee.eof())
        {
            lee.read((char *)&tamanioCadena,sizeof(int));
            lee.read((char *)&cadenaLeida, tamanioCadena);
            cadenaLeida[tamanioCadena] = '\0';
            lee.read((char *)&tamanioCadena,sizeof(int));
            lee.read((char *)&cadenaLeida, tamanioCadena);
            cadenaLeida[tamanioCadena] = '\0';
            if(lee.eof())break;
            if(j == 0){
                paises<<cadenaLeida;
            }
            j++;
            if(j == 2)
            {
                //Si entra significa que ya guardo 4 columnas de datos
                i++; //se incrementa un nuevo registro destino
                j=0;
            }
        }
    }
    lee.close();



    ifstream leePesos("Pesos.txt",ios::app);
    col = fil = 0;

    if(!leePesos.good())
    {
        QMessageBox msgBox;
        msgBox.setText("No existe el archivo de Pesos");
        msgBox.exec();
    }else
    {

        while(!leePesos.eof())
        {
            string aux;
            getline(leePesos,aux,'|'); //| significa que hasta hay se termina una columna
            int a;
            if(leePesos.eof())break;
            if(aux == "&"){
                fil++;
                col = 0;
            }else{
                a = atoi(aux.c_str());
                //if(leer.eof()) break;
                matrizPesos[fil][col] = a;

                col++;
            }
            if(leePesos.eof())break;
        }
    }
    limpiarTabla();
    for(int x = 0; x < i-1 ; x++ ){
    ui->tablaVuelos->insertColumn(x);
    }
    for(int x = 0; x < i-1 ; x++ ){
    ui->tablaVuelos->insertRow(x);
    }
    ui->tablaVuelos->setHorizontalHeaderLabels(paises);
    ui->tablaVuelos->setVerticalHeaderLabels(paises);

    for(fil=0;fil<i-1;fil++){

        for(col=0;col<i;col++){
            if(fil==col){
                elemento = new QTableWidgetItem(QString::number(matrizPesos[fil][col]));
                elemento->setFlags(elemento->flags() ^ Qt::ItemIsEnabled);
                ui->tablaVuelos->setItem(col,fil,elemento);
            }else{
            elemento = new QTableWidgetItem(QString::number(matrizPesos[fil][col]));
            ui->tablaVuelos->setItem(col,fil,elemento);
            }
        }
        leePesos.close();

    }

}

void MenuVuelos::on_botonGuardarVuelos_clicked()
{
    remove("Pesos.txt");
    ofstream esc("Pesos.txt",ios::app);
    int contador = ui->tablaVuelos->rowCount();
    for(int fil = 0; fil < contador ; fil++)
    {
        for(int col = 0; col < contador ;col++)
        {

            matrizPesos[col][fil] = atoi(ui->tablaVuelos->item(fil,col)->text().toStdString().c_str());
        }
    }

    for(int fil= 0; fil<30; fil++)
    {
        for(int col= 0; col<30; col++)
        {
            esc<<matrizPesos[fil][col]<<"|";

        }
        esc<<"&|";
    }
    esc.close();
}

void MenuVuelos::limpiarTabla()
{
    int contador = ui->tablaVuelos->rowCount();
    for(int fil = contador; fil > -1 ;fil--)
    {
        ui->tablaVuelos->removeRow(fil);

    }
    for(int col = contador; col > -1 ;col--)
    {
        ui->tablaVuelos->removeColumn(col);

    }
}

void MenuVuelos::cambioEnCelda(int fila, int columna)
{

    QString text = ui->tablaVuelos->item(fila,columna)->text();
    emit hacerCambios(fila,columna,text);
}

void MenuVuelos::hacerCambios(int fila, int columna, QString text)
{
    if(fila != columna){
        modpeso->pasar(ui->tablaVuelos,fila,columna,text.toStdString());
        modpeso->show();
    }else{
        QMessageBox msgBox;
        msgBox.setText("No puedes editar este elemento.");
        msgBox.exec();
    }
}


