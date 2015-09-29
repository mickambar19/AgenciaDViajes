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
    l.initialize();
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

        ofstream escH("Hoteles.txt",ios::app);
        ofstream escI("Indices.txt",ios::app);

        long int diceTel;
        escH.write((char*)&hotel,sizeof(Hotel));
        indice.setLlave(hotel.getCodigo());
        escH.seekp(0,escH.end);
        indice.posicion=escH.tellp();
        diceTel = escH.tellp();
        indice.setPosicion(indice.posicion-sizeof(Hotel));
        escI.write((char*)&indice,sizeof(indice));
        QMessageBox msgBox;
        msgBox.setText("Inicio de objeto:"+QString::number(indice.getPosicion())+
                       "\nFin de objeto:"+QString::number(indice.getPosicion()+sizeof(hotel))+
                       "\nDice tellp:"+QString::number(diceTel));

        msgBox.exec();
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

void MenuHoteles2::limpiarTablaHoteles()
{
    for(int i = 0; i <ui->tablaHoteles->rowCount();)
    {
        delete ui->tablaHoteles->item(i,0);
        delete ui->tablaHoteles->item(i,1);
        delete ui->tablaHoteles->item(i,2);
        delete ui->tablaHoteles->item(i,3);
        delete ui->tablaHoteles->item(i,4);

        ui->tablaHoteles->removeRow(i);
    }
    for(int i = 0; i < ui->tablaHoteles->columnCount();)
    {
        ui->tablaHoteles->removeColumn(i);
    }
}

void MenuHoteles2::cargarIndices()
{
    IndiceHotel indice;
    ifstream leerI("Indices.txt");
    if(!leerI.good())
    {
        
    }else{
        while(!leerI.eof()){
            if(leerI.eof())break;
            leerI.read((char *)&indice,sizeof(IndiceHotel));
            l.insertOneAfter(indice,l.first());
            if(leerI.eof())break;
        }
    }
    leerI.close();
}

void MenuHoteles2::on_botonActualizarHoteles_clicked()
{
    limpiarTablaHoteles();
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

            ifstream leerH("Hoteles.txt",ios::app);
            QMessageBox msgBox;

            msgBox.setText("Tellp:"+QString::number(leerH.tellg()));
            msgBox.exec();
            leerH.seekg(indice.getPosicion()-1,leerH.beg);
            leerH.read((char*)&hotel,sizeof(Hotel));

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
            leerH.close();
        }
    }
    ui->tablaHoteles->removeRow(ui->tablaHoteles->rowCount()-1);
    leerI.close();
}

void MenuHoteles2::on_botonBuscarModHoteles_clicked()
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
        ui->tablaModificarHoteles->insertColumn(0);
        ui->tablaModificarHoteles->insertColumn(1);
        ui->tablaModificarHoteles->insertColumn(2);
        ui->tablaModificarHoteles->insertColumn(3);
        ui->tablaModificarHoteles->insertColumn(4);
        ui->tablaModificarHoteles->setHorizontalHeaderLabels(titulosParteSuperior);
        while(!leerI.eof())
        {

            leerI.read((char*)&indice,sizeof(indice));

            ifstream leerH("Hoteles.txt",ios::app);
            QMessageBox msgBox;

            msgBox.setText("Tellp:"+QString::number(leerH.tellg()));
            msgBox.exec();
            leerH.seekg(indice.getPosicion()-1,leerH.beg);
            leerH.read((char*)&hotel,sizeof(Hotel));
            QString actualHotel = QString::fromStdString(hotel.getCodigo());
            if(leerI.eof())break;
            if(actualHotel.toInt() == ui->inputCodigoHotelMod->text().toInt()){
                ui->tablaModificarHoteles->insertRow(i);
                elemento = new QTableWidgetItem(QString::fromStdString(hotel.getCodigo()));
                ui->tablaModificarHoteles->setItem(i,0,elemento);
                elemento = new QTableWidgetItem(QString::fromStdString(hotel.getPaisDeHotel()));
                ui->tablaModificarHoteles->setItem(i,1,elemento);
                elemento = new QTableWidgetItem(QString::fromStdString(hotel.getNombreHotel()));
                ui->tablaModificarHoteles->setItem(i,2,elemento);
                elemento = new QTableWidgetItem(QString::fromStdString(hotel.getTipo()));
                ui->tablaModificarHoteles->setItem(i,3,elemento);
                elemento = new QTableWidgetItem(QString::fromStdString(hotel.getTarifa()));
                ui->tablaModificarHoteles->setItem(i,4,elemento);
                i++;
            }
            if(leerI.eof())break;
            leerH.close();
        }
    }
    leerI.close();

}

void MenuHoteles2::on_botonEliminarModHoteles_clicked()
{

    Hotel hotel;
    IndiceHotel indice;
    ifstream leerI("Indices.txt");
    ofstream escAI("IndicesAux.txt",ios::app);
    ofstream escAH("HotelesAux.txt",ios::app);
    //limpiartablaHoteles();
    if(!leerI.good())
    {
        QMessageBox msgBox;
        msgBox.setText("No existe el archivo de Empleados");
        msgBox.exec();
    }else
    {
        while(!leerI.eof())
        {

            leerI.read((char*)&indice,sizeof(indice));

            ifstream leerH("Hoteles.txt",ios::app);

            leerH.seekg(indice.getPosicion()-1,leerH.beg);
            leerH.read((char*)&hotel,sizeof(Hotel));
            QString actualHotel = QString::fromStdString(hotel.getCodigo());
            if(leerI.eof())break;
            if(actualHotel.toInt() != ui->inputCodigoHotelEliminar->text().toInt()){

                escAH.write((char *)&hotel,sizeof(Hotel));
                escAH.seekp(0,escAH.end);
                indice.setLlave(hotel.getCodigo());
                indice.setPosicion(escAH.tellp());
                indice.setPosicion(indice.getPosicion()-sizeof(Hotel));
                escAI.write((char*)&indice,sizeof(indice));

            }else{
                QMessageBox msgBox;

                msgBox.setText("Se encontro:"+QString::fromStdString(hotel.getCodigo()));
                msgBox.exec();
            }
            if(leerI.eof())break;
            leerH.close();
        }
    }
    leerI.close();
    escAH.close();
    escAI.close();
    remove("Indices.txt");
    remove("Hoteles.txt");
    rename("IndicesAux.txt","Indices.txt");
    rename("HotelesAux.txt","Hoteles.txt");
}

void MenuHoteles2::on_tabWidget_tabBarClicked(int index)
{
    if(index == 0){
        cargar_Paises();
    }
}

void MenuHoteles2::on_botonGuardarModHoteles_clicked()
{
    Hotel hotel;
    IndiceHotel indice;
    ifstream leerI("Indices.txt");
    ofstream escAH("HotelesAux.txt",ios::app);
    //limpiartablaHoteles();
    if(!leerI.good())
    {
        QMessageBox msgBox;
        msgBox.setText("No existe el archivo de Empleados");
        msgBox.exec();
    }else
    {
        while(!leerI.eof())
        {

            leerI.read((char*)&indice,sizeof(indice));

            ifstream leerH("Hoteles.txt",ios::app);

            leerH.seekg(indice.getPosicion()-1,leerH.beg);
            leerH.read((char*)&hotel,sizeof(Hotel));
            QString actualHotel = QString::fromStdString(hotel.getCodigo());
            if(leerI.eof())break;
            QTableWidgetItem* item = ui->tablaModificarHoteles->item(0,0);
            if(!item || item->text() == "")
            {

            }else{
                if(actualHotel.toInt() == ui->inputCodigoHotelMod->text().toInt()){

                    QMessageBox msgBox;
                    msgBox.setText("Se efectuaran los cambios");
                    msgBox.exec();
                    hotel.setCodigo(ui->tablaModificarHoteles->item(0,0)->text().toStdString());
                    hotel.setNombreHotel(ui->tablaModificarHoteles->item(0,1)->text().toStdString());
                    hotel.setPaisDeHotel(ui->tablaModificarHoteles->item(0,2)->text().toStdString());
                    hotel.setTarifa(ui->tablaModificarHoteles->item(0,3)->text().toStdString());
                    hotel.setTipo(ui->tablaModificarHoteles->item(0,4)->text().toStdString());
                }

            }
            escAH.write((char *)&hotel,sizeof(Hotel));

            if(leerI.eof())break;
            leerH.close();
        }
    }
    leerI.close();
    escAH.close();

    remove("Hoteles.txt");
    rename("HotelesAux.txt","Hoteles.txt");
}

void MenuHoteles2::on_guardarIndices_clicked()
{
    IndiceHotel indice;
    ofstream escI("IndicesAux.txt");
    NodoDoble<IndiceHotel> *nodoActual;
    nodoActual = l.first();
    while(nodoActual != NULL){
        indice = nodoActual->getData();
        escI.read((char *)&indice,sizeof(IndiceHotel));
        nodoActual = nodoActual->getNext();
    }
    escI.close();
    remove("Indices.txt");
    rename("IndicesAux.txt","Indices.txt");
}
