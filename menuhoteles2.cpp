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
    lsecundaria.initialize();
    cargarIndices();
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


        long int diceTel;
        escH.write((char*)&hotel,sizeof(Hotel));
        indice.setLlave(hotel.getCodigo());
        escH.seekp(0,escH.end);
        indice.posicion=escH.tellp();
        diceTel = escH.tellp();
        indice.setPosicion(indice.posicion-sizeof(Hotel));
        l.insertOneAfter(indice,l.last());
        QMessageBox msgBox;
        msgBox.setText("Inicio de objeto:"+QString::number(indice.getPosicion())+
                       "\nFin de objeto:"+QString::number(indice.getPosicion()+sizeof(hotel))+
                       "\nDice tellp:"+QString::number(diceTel));

        msgBox.exec();
        escH.close();
        on_guardarIndices_clicked();
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

void MenuHoteles2::limpiarTablaMod()
{

    for(int i = 0; i < ui->tablaModificarHoteles->rowCount();)
    {
        delete ui->tablaModificarHoteles->item(i,0);
        delete ui->tablaModificarHoteles->item(i,1);
        delete ui->tablaModificarHoteles->item(i,2);
        delete ui->tablaModificarHoteles->item(i,3);

        ui->tablaModificarHoteles->removeRow(i);
    }
    for(int i = 0; i < ui->tablaModificarHoteles->columnCount();)
    {
        ui->tablaModificarHoteles->removeColumn(i);
    }
}

void MenuHoteles2::cargarIndices()
{
    IndiceHotel indice;
    ifstream leerI("Indices.txt");
    l.deleteAll();
    l.initialize();
    if(!leerI.good())
    {

    }else{
        while(!leerI.eof()){
            if(leerI.eof())break;
            leerI.read((char *)&indice,sizeof(IndiceHotel));
            l.insertOneAfter(indice,l.last());

            if(leerI.eof())break;
        }
    }
    leerI.close();
    l.delete_e(l.last());

}

void MenuHoteles2::on_botonActualizarHoteles_clicked()
{
    limpiarTablaHoteles();
    QTableWidgetItem *elemento;
    Hotel hotel;
    IndiceHotel indice;

    QStringList titulosParteSuperior;
    int i = 0;
    titulosParteSuperior<<"Codigo"<<"NombrePais"<<"NombreHotel"<<"Tarifa"<<"Tipo";
    //limpiartablaHoteles();
    NodoDoble<IndiceHotel> *nodoActual;
    nodoActual= l.first();
    if(l.isEmpty())
    {
        QMessageBox msgBox;
        msgBox.setText("No existe el ningun Indice");
        msgBox.exec();
    }else
    {
        ui->tablaHoteles->insertColumn(0);
        ui->tablaHoteles->insertColumn(1);
        ui->tablaHoteles->insertColumn(2);
        ui->tablaHoteles->insertColumn(3);
        ui->tablaHoteles->insertColumn(4);
        ui->tablaHoteles->setHorizontalHeaderLabels(titulosParteSuperior);
        while(nodoActual!=NULL)
        {

            ui->tablaHoteles->insertRow(i);
            indice = nodoActual->getData();

            ifstream leerH("Hoteles.txt",ios::app);
            QMessageBox msgBox;

            msgBox.setText("Tellp:"+QString::number(leerH.tellg()));
            //msgBox.exec();
             leerH.seekg(indice.getPosicion(),leerH.beg);


            leerH.read((char*)&hotel,sizeof(Hotel));


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
            nodoActual= nodoActual->getNext();
            leerH.close();
        }
    }

}

void MenuHoteles2::on_botonBuscarModHoteles_clicked()
{
    QTableWidgetItem *elemento;
    Hotel hotel;
    IndiceHotel indice;
    QStringList titulosParteSuperior;
    NodoDoble<IndiceHotel> *nodoActual;
    nodoActual = l.first();
    int i = 0;
    limpiarTablaMod();
    titulosParteSuperior<<"Codigo"<<"NombrePais"<<"NombreHotel"<<"Tarifa"<<"Tipo";

    if(l.isEmpty())
    {
        QMessageBox msgBox;
        msgBox.setText("No existen indices");
        msgBox.exec();
    }else
    {
        ui->tablaModificarHoteles->insertColumn(0);
        ui->tablaModificarHoteles->insertColumn(1);
        ui->tablaModificarHoteles->insertColumn(2);
        ui->tablaModificarHoteles->insertColumn(3);
        ui->tablaModificarHoteles->insertColumn(4);
        ui->tablaModificarHoteles->setHorizontalHeaderLabels(titulosParteSuperior);
        while(nodoActual!=NULL)
        {

            indice = nodoActual->getData();

            ifstream leerH("Hoteles.txt",ios::app);
            QMessageBox msgBox;

            msgBox.setText("Tellp:"+QString::number(leerH.tellg()));
            msgBox.exec();
            // leerH.seekg(indice.getPosicion(),leerH.beg);
            leerH.seekg(indice.getPosicion(),leerH.beg);

            leerH.read((char*)&hotel,sizeof(Hotel));
            QString actualHotel = QString::fromStdString(hotel.getCodigo());

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
            nodoActual = nodoActual->getNext();
            leerH.close();
        }
    }
}

void MenuHoteles2::on_botonEliminarModHoteles_clicked()
{

    Hotel hotel;
    IndiceHotel indice;
    NodoDoble<IndiceHotel> *nodoActual, *encontrado;
    ListaSimple<IndiceHotel> lAux;
    encontrado = NULL;
    lAux.initialize();
    nodoActual = l.first();
    ofstream escAH("HotelesAux.txt",ios::app);
    //limpiartablaHoteles();
    if(l.isEmpty())
    {
        QMessageBox msgBox;
        msgBox.setText("No existen Indices");
        msgBox.exec();
    }else
    {
        while(nodoActual!=NULL)
        {
            indice = nodoActual->getData();
            ifstream leerH("Hoteles.txt",ios::app);

            leerH.seekg(indice.getPosicion(),leerH.beg);
            leerH.read((char*)&hotel,sizeof(Hotel));
            QString actualHotel = QString::fromStdString(hotel.getCodigo());
            if(actualHotel != ui->inputCodigoHotelEliminar->text()){
                escAH.write((char *)&hotel,sizeof(Hotel));
                escAH.seekp(0,escAH.end);
                indice.setLlave(hotel.getCodigo());
                indice.setPosicion(escAH.tellp());
                indice.setPosicion(indice.getPosicion()-sizeof(Hotel));

                nodoActual->setData(indice);
            }else{
                QMessageBox msgBox;
                msgBox.setText("Se encontro:"+QString::fromStdString(hotel.getCodigo()));
                msgBox.exec();
                ui->mensajeRespuesta->insertPlainText("Se encontro y se elimino el hotel que deseabas.\n");
                encontrado = nodoActual;
            }
            nodoActual = nodoActual->getNext();
            leerH.close();
        }
    }
    if(encontrado!=NULL){
        l.delete_e(encontrado);
    }
    escAH.close();
    remove("Hoteles.txt");
    rename("HotelesAux.txt","Hoteles.txt");
    on_guardarIndices_clicked();
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
    NodoDoble<IndiceHotel> *nodoActual;
    ofstream escAH("HotelesAux.txt",ios::app);
    //limpiartablaHoteles();
    nodoActual = l.first();
    if(l.isEmpty())
    {
        QMessageBox msgBox;
        msgBox.setText("No existe el archivo de Empleados");
        msgBox.exec();
    }else
    {
        while(nodoActual != NULL)
        {

            indice = nodoActual->getData();

            ifstream leerH("Hoteles.txt",ios::app);

            // leerH.seekg(indice.getPosicion(),leerH.beg);
            leerH.seekg(indice.getPosicion(),leerH.beg);

            leerH.read((char*)&hotel,sizeof(Hotel));
            QString actualHotel = QString::fromStdString(hotel.getCodigo());

            QTableWidgetItem* item = ui->tablaModificarHoteles->item(0,0);
            if(!item || item->text() == "")
            {
                QMessageBox msgBox;
                msgBox.setText("No se encuentra ningun indice con ese codigo.\n");
                msgBox.exec();
            }else{
                if(actualHotel.toInt() == ui->inputCodigoHotelMod->text().toInt()){


                    hotel.setCodigo(ui->tablaModificarHoteles->item(0,0)->text().toStdString());
                    QMessageBox msgBox;
                    msgBox.setText(ui->tablaModificarHoteles->item(0,0)->text()+"Se efectuaran los cambios");
                    msgBox.exec();
                    hotel.setPaisDeHotel(ui->tablaModificarHoteles->item(0,1)->text().toStdString());
                    hotel.setNombreHotel(ui->tablaModificarHoteles->item(0,2)->text().toStdString());
                    hotel.setTipo(ui->tablaModificarHoteles->item(0,3)->text().toStdString());
                    hotel.setTarifa(ui->tablaModificarHoteles->item(0,4)->text().toStdString());
                }

            }
            escAH.write((char *)&hotel,sizeof(Hotel));

            nodoActual = nodoActual->getNext();
            leerH.close();
        }
    }
    escAH.close();
    on_guardarIndices_clicked();
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
        escI.write((char *)&indice,sizeof(IndiceHotel));
        nodoActual = nodoActual->getNext();
    }
    escI.close();
    remove("Indices.txt");
    rename("IndicesAux.txt","Indices.txt");
}

void MenuHoteles2::on_mostrarLista_clicked()
{
    NodoDoble<IndiceHotel> *nodoActual;
    QString textoInformativo;
    int x = 0;
    nodoActual = l.first();
    while(nodoActual!= NULL){
        textoInformativo += "\n\n";
        textoInformativo += QString::number(x);
        textoInformativo += "\nLlave:\n";
        textoInformativo += QString::fromStdString(nodoActual->getData().getLlave());
        textoInformativo += "\nPosicion:\n";
        textoInformativo += QString::number(nodoActual->getData().getPosicion());
        x++;
        nodoActual = nodoActual->getNext();
    }
    QMessageBox msgBox;
    msgBox.setText("Todos los indices");
    msgBox.setInformativeText(textoInformativo);
    msgBox.exec();
}
