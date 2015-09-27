#include "menuhoteles2.h"
#include "ui_menuhoteles2.h"
#include <QMessageBox>
MenuHoteles2::MenuHoteles2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuHoteles2)
{
    ui->setupUi(this);
    //cargar lista de Paises
    cargar_Paises();
}

MenuHoteles2::~MenuHoteles2()
{
    delete ui;
}

void MenuHoteles2::on_botonAceptarAgregaHotel_clicked()
{
    Hotel hotel;
    IndiceHotel indice;
    QString codigo = ui->inputCodigoHotel->text();
    QString paisDeHotel = ui->paisComboBox->currentText();
    QString nombreHotel = ui->inputNombreHotel->text();
    QString tarifa = ui->inputTarifaHotel->text();
    QString tipo = ui->inputTipoHotel->text();
    if(codigo == "" || paisDeHotel == ""|| nombreHotel == ""|| tarifa == "" || tipo == "")
    {
        // Se desprende un MessageBox Si el usuario no ingreso cualquiera de los anteriores datos
        if(codigo == "")
        {

        }else if(paisDeHotel == "")
        {

        }else if(nombreHotel == "")
        {

        }else if(tarifa == "")
        {

        }else if(tipo == "")
        {

        }

    }else
    {
        hotel.setCodigo(codigo.toStdString());
        hotel.setPaisDeHotel(paisDeHotel.toStdString());
        hotel.setNombreHotel(nombreHotel.toStdString());
        hotel.setTipo(tipo.toStdString());
        hotel.setTarifa(tarifa.toStdString());
        indice.setLlave(hotel.getCodigo());
        ofstream escH("Hoteles.txt",ios::out);
        ofstream escI("Indices.txt",ios::out);
        escH.write((char *)&hotel,sizeof(Hotel));
        escH.seekp(0,escH.end);
        QMessageBox msgBox;
        msgBox.setText(QString::number(escH.tellp()));
        msgBox.exec();
        indice.setPosicion(escH.tellp());
        indice.setPosicion(indice.getPosicion()-sizeof(Hotel));
        indice.setPosicion(indice.getPosicion()-1);
        escI.write((char *)&indice,sizeof(indice));
        escI.close();
        escH.close();
    }
}

void MenuHoteles2::cargar_Paises()
{
    QStringList paisesDisponibles;
    ifstream lee("Destinos.txt",ios::app);
    int tamanioCadena;
    char cadenaLeida[100];
    int i = 0;
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
            paisesDisponibles<<cadenaLeida;
            while(i<2){
                lee.read((char *)&tamanioCadena,sizeof(int));
                lee.read((char *)&cadenaLeida, tamanioCadena);
                cadenaLeida[tamanioCadena] = '\0';
                i++;
            }
            i = 0;

        }
    }
    lee.close();
    ui->paisComboBox->addItems(paisesDisponibles);
}

void MenuHoteles2::on_botonActualizarHoteles_clicked()
{
    QTableWidgetItem *elemento;
    Hotel hotel;
    IndiceHotel indice;
    ifstream leerI("Indices.txt");
    QStringList titulosParteSuperior;
    int i = 0;
    titulosParteSuperior<<"Codigo"<<"NombrePais"<<"NombreHotel"<<"Tarifa"<<"Tipo";
    //limpiartablaHoteles();
    if(!leerI.good())
    {
        QMessageBox msgBox;
        msgBox.setText("No existe el archivo de Empleados");
        msgBox.exec();
    }else
    {
        ui->tablaHoteles->insertColumn(0);
        ui->tablaHoteles->insertColumn(1);
        ui->tablaHoteles->insertColumn(2);
        ui->tablaHoteles->insertColumn(3);
        ui->tablaHoteles->insertColumn(4);
        ui->tablaHoteles->setHorizontalHeaderLabels(titulosParteSuperior);
        while(!leerI.eof())
        {

            ui->tablaHoteles->insertRow(i);
            leerI.read((char*)&indice,sizeof(indice));
            QMessageBox msgBox2;
            msgBox2.setText("Indice leido" );
            msgBox2.setInformativeText(QString::number(indice.getPosicion())+"\nLLave:"+QString::fromStdString(indice.getLlave()));
            msgBox2.exec();
            ifstream leerH("Hoteles.txt",ios::out);
            leerH.seekg(indice.getPosicion(),ios::beg);
            leerH.read((char*)&hotel,sizeof(Hotel));
            QMessageBox msgBox;
            msgBox.setText("Hotel leido" );
            msgBox.setInformativeText("Nuevo Hotel:\n Codigo:"+QString::fromStdString(hotel.getCodigo())+"\nPais:"+QString::fromStdString(hotel.getPaisDeHotel())+"\nNombre:"+QString::fromStdString(hotel.getNombreHotel())+"\nTipo:"+QString::fromStdString(hotel.getTipo())+"\nTarifa"+QString::fromStdString(hotel.getTarifa()));
            msgBox.exec();
            if(leerI.eof())break;
            elemento = new QTableWidgetItem(QString::fromStdString(hotel.getCodigo()));
            ui->tablaHoteles->setItem(i,0,elemento);
            elemento = new QTableWidgetItem(QString::fromStdString(hotel.getPaisDeHotel()));
            ui->tablaHoteles->setItem(i,1,elemento);
            elemento = new QTableWidgetItem(QString::fromStdString(hotel.getNombreHotel()));
            ui->tablaHoteles->setItem(i,2,elemento);
            elemento = new QTableWidgetItem(QString::fromStdString(hotel.getTipo()));
            ui->tablaHoteles->setItem(i,3,elemento);
            elemento = new QTableWidgetItem(QString::fromStdString(hotel.getTarifa()));
            ui->tablaHoteles->setItem(i,4,elemento);
            i++;
            if(leerI.eof())break;
        }
    }
    ui->tablaHoteles->removeRow(ui->tablaHoteles->rowCount()-1);
    leerI.close();
}
