#include "menudestinos.h"
#include "ui_menudestinos.h"

MenuDestinos::MenuDestinos(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuDestinos)
{
    ui->setupUi(this);
    ui->inputCodigoD->setEnabled(false);
    ui->inputCodigoD->setText( QString::number(contarRegistros()));

}

MenuDestinos::~MenuDestinos()
{
    delete ui;
}

void MenuDestinos::limpiarVentana()
{

    ui->inputCodigoD->setText( QString::number(contarRegistros()));
    ui->inputNombreD->setText("");
    ui->inputTipoD->setText("");
    ui->inputEstatusD->setText("");
}

void MenuDestinos::limpiarTablaDestinos()
{
    for(int i = 0; i < ui->tablaDestinos->rowCount();)
    {
        delete ui->tablaDestinos->item(i,0);
        delete ui->tablaDestinos->item(i,1);
        delete ui->tablaDestinos->item(i,2);
        delete ui->tablaDestinos->item(i,3);

        ui->tablaDestinos->removeRow(i);
    }
    for(int i = 0; i < ui->tablaDestinos->columnCount();)
    {
        ui->tablaDestinos->removeColumn(i);
    }

    for(int i = 0; i < ui->tablaModificarDestinos->rowCount();)
    {
        delete ui->tablaModificarDestinos->item(i,0);
        delete ui->tablaModificarDestinos->item(i,1);
        delete ui->tablaModificarDestinos->item(i,2);
        delete ui->tablaModificarDestinos->item(i,3);

        ui->tablaModificarDestinos->removeRow(i);
    }
    for(int i = 0; i < ui->tablaModificarDestinos->columnCount();)
    {
        ui->tablaModificarDestinos->removeColumn(i);
    }
}

int MenuDestinos::contarRegistros()
{
    char cadenaLeida[MAX_CARACTERES];
    int tamanioCadena;
    int i, j;
    ifstream lee("Destinos.txt",ios::app);
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
            if(lee.eof())break;
            j++;
            if(j == 4)
            {
                //Si entra significa que ya guardo 4 columnas de datos
                i++; //se incrementa un nuevo registro destino
                j=0;

            }
        }
    }
    lee.close();
    return i;
}

void MenuDestinos::reEnumerar()
{
    int a;
    int x = 1;
    char cod[MAX_CARACTERES];
    char nombre[MAX_CARACTERES];
    char tipo[MAX_CARACTERES];
    char status[MAX_CARACTERES];
    ifstream leer("Destinos.txt");
    ofstream escA("Auxiliar.txt");
    if(!leer.good())
    {
        QMessageBox msgBox;
        msgBox.setText("No existe el archivo de Destinos");
        msgBox.exec();
    }else
    {
       while(!leer.eof())
       {
           leer.read((char *)&a,sizeof(int));
           leer.read((char *)&cod,a);
           cod[a]='\0';
           leer.read((char *)&a,sizeof(int));
           leer.read((char *)&nombre,a);
           nombre[a]='\0';
           leer.read((char *)&a,sizeof(int));
           leer.read((char *)&tipo,a);
           tipo[a]='\0';
           leer.read((char *)&a,sizeof(int));
           leer.read((char *)&status,a);
           status[a]='\0';
           if(leer.eof())break;

               itoa(x,cod,10);
               a=strlen(cod);
               escA.write((char *)&a, sizeof(int));
               escA.write((char *)&cod, a);

               a=strlen(nombre);
               escA.write((char *)&a, sizeof(int));
               escA.write((char *)&nombre, a);

               a=strlen(tipo);
               escA.write((char *)&a, sizeof(int));
               escA.write((char *)&tipo, a);

               a=strlen(status);
               escA.write((char *)&a, sizeof(int));
               escA.write((char *)&status, a);

            x++;
       }
    }
    leer.close();
    escA.close();
    remove("Destinos.txt");
    rename("Auxiliar.txt", "Destinos.txt");
}

void MenuDestinos::on_botonAceptarAgregar_clicked()
{

    Destino destino;
    bool formularioCompleto;//si sigue siendo cero al final no hubo errores
    if( ui->inputCodigoD->text().toStdString()=="" ||
        ui->inputNombreD->text().toStdString()=="" ||
        ui->inputTipoD->text().toStdString()=="" ||
        ui->inputEstatusD->text().toStdString()==""){
        formularioCompleto = false;
    }else{
        formularioCompleto = true;
    }
    if(formularioCompleto){
        QMessageBox msgBox;
        msgBox.setText("Se han obtenido los datos.");
        msgBox.setInformativeText("Quieres guardar los cambios?");
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Save);
        int ret = msgBox.exec();
        switch (ret) {
          case QMessageBox::Save:
                // Presiono Save
                destino.setCodigoDestino(atoi(ui->inputCodigoD->text().toStdString().c_str()));
                destino.setNombreDestino(ui->inputNombreD->text().toStdString());
                destino.setTipoDestino(ui->inputTipoD->text().toStdString());
                destino.setEstatusDestino(ui->inputEstatusD->text().toStdString());
                destino.guardar();
                limpiarVentana();
              break;
          case QMessageBox::Cancel:
                // Presionaron Cancel
              break;
          default:
                 // Este apartado nunca debe de ser alcanzado
              break;
        }

    }else
    {
        QMessageBox msgBox;
        msgBox.setText("El formulario esta incompleto.\n Intentalo de nuevo");
        msgBox.exec();
    }

}

void MenuDestinos::on_botonActualizarDestinos_clicked()
{

    char cadenaLeida[MAX_CARACTERES];
    int tamanioCadena;
    int i, j;
    QTableWidgetItem *elemento;
    ifstream lee("Destinos.txt",ios::app);
    QStringList titulosParteSuperior;
    titulosParteSuperior<<"Codigo"<<"Nombre"<<"Tipo"<<"Estatus";
    i =  j = 0;
    limpiarTablaDestinos();
    if(!lee.good())
    {
        QMessageBox msgBox;
        msgBox.setText("No existe el archivo de Destinos");
        msgBox.exec();
    }else
    {
        ui->tablaDestinos->insertColumn(0);
        ui->tablaDestinos->insertColumn(1);
        ui->tablaDestinos->insertColumn(2);
        ui->tablaDestinos->insertColumn(3);
        ui->tablaDestinos->setHorizontalHeaderLabels(titulosParteSuperior);
        while(!lee.eof())
        {
            if( j == 4 && !lee.eof() )
            {
                //Si entra significa que ya guardo 4 columnas de datos
                i++;
                j=0;
                //Agregara una nueva fila
                ui->tablaDestinos->insertRow(i);
            }else if( i == 0  && j == 0){
                ui->tablaDestinos->insertRow(i);
            }
            lee.read((char *)&tamanioCadena,sizeof(int));
            lee.read((char *)&cadenaLeida, tamanioCadena);
            cadenaLeida[tamanioCadena] = '\0';
            if(lee.eof())break;
            elemento = new QTableWidgetItem(cadenaLeida);
            ui->tablaDestinos->setItem(i,j,elemento);
            j++;

            if(lee.eof())break;
        }
    }
    ui->tablaDestinos->removeRow(ui->tablaDestinos->rowCount()-1);
    lee.close();
}

void MenuDestinos::on_botonBuscarModDest_clicked()
{
    int tamanioCadena;
    char codigo[MAX_CARACTERES];
    char nombre[MAX_CARACTERES];
    char tipo[MAX_CARACTERES];
    char estatus[MAX_CARACTERES];
    QTableWidgetItem *elemColum1, *elemColum2, *elemColum3, *elemColum4;
    ifstream lee("Destinos.txt",ios::app);
    QStringList titulosParteSuperior;
    titulosParteSuperior<<"Codigo"<<"Nombre"<<"Tipo"<<"Estatus";
    limpiarTablaDestinos();
    if(!lee.good())
    {
        QMessageBox msgBox;
        msgBox.setText("No existe el archivo de Destinos");
        msgBox.exec();
    }else
    {
        ui->tablaModificarDestinos->insertColumn(0);
        ui->tablaModificarDestinos->insertColumn(1);
        ui->tablaModificarDestinos->insertColumn(2);
        ui->tablaModificarDestinos->insertColumn(3);
        ui->tablaModificarDestinos->setHorizontalHeaderLabels(titulosParteSuperior);
        while(!lee.eof())
        {

            lee.read((char *)&tamanioCadena,sizeof(int));
            lee.read((char *)&codigo, tamanioCadena);
            codigo[tamanioCadena] = '\0';
            lee.read((char *)&tamanioCadena,sizeof(int));
            lee.read((char *)&nombre, tamanioCadena);
            nombre[tamanioCadena] = '\0';
            lee.read((char *)&tamanioCadena,sizeof(int));
            lee.read((char *)&tipo, tamanioCadena);
            tipo[tamanioCadena] = '\0';
            lee.read((char *)&tamanioCadena,sizeof(int));
            lee.read((char *)&estatus, tamanioCadena);
            estatus[tamanioCadena] = '\0';
            //Ya leyo todas las partes del objeto
            elemColum1 = new QTableWidgetItem(codigo);
            elemColum2 = new QTableWidgetItem(nombre);
            elemColum3 = new QTableWidgetItem(tipo);
            elemColum4 = new QTableWidgetItem(estatus);
            if(lee.eof())break;
            if(ui->inputCodigoDModificar->text().toStdString()!= "" && strcmp(codigo,ui->inputCodigoDModificar->text().toStdString().c_str())== 0){

                ui->tablaModificarDestinos->insertRow(0);
                ui->tablaModificarDestinos->setItem(0,0,elemColum1);
                ui->tablaModificarDestinos->setItem(0,1,elemColum2);
                ui->tablaModificarDestinos->setItem(0,2,elemColum3);
                ui->tablaModificarDestinos->setItem(0,3,elemColum4);
            } else if(ui->inputNombreDModificar->text().toStdString()!="" && strcmp(nombre,ui->inputNombreDModificar->text().toStdString().c_str())== 0){

                ui->tablaModificarDestinos->insertRow(0);
                ui->tablaModificarDestinos->setItem(0,0,elemColum1);
                ui->tablaModificarDestinos->setItem(0,1,elemColum2);
                ui->tablaModificarDestinos->setItem(0,2,elemColum3);
                ui->tablaModificarDestinos->setItem(0,3,elemColum4);
            } else if(ui->inputTipoDModificar->text().toStdString()!="" && strcmp(tipo,ui->inputTipoDModificar->text().toStdString().c_str())== 0){

                ui->tablaModificarDestinos->insertRow(0);
                ui->tablaModificarDestinos->setItem(0,0,elemColum1);
                ui->tablaModificarDestinos->setItem(0,1,elemColum2);
                ui->tablaModificarDestinos->setItem(0,2,elemColum3);
                ui->tablaModificarDestinos->setItem(0,3,elemColum4);
            } else if(ui->inputEstatusDModificar->text().toStdString()!="" && strcmp(estatus,ui->inputEstatusDModificar->text().toStdString().c_str())==0){

                ui->tablaModificarDestinos->insertRow(0);
                ui->tablaModificarDestinos->setItem(0,0,elemColum1);
                ui->tablaModificarDestinos->setItem(0,1,elemColum2);
                ui->tablaModificarDestinos->setItem(0,2,elemColum3);
                ui->tablaModificarDestinos->setItem(0,3,elemColum4);
            }
            if(lee.eof())break;

        }
    }
    lee.close();
}

void MenuDestinos::on_botonGuardarModDest_clicked()
{
    int a;
    char cod[MAX_CARACTERES];
    char nombre[MAX_CARACTERES];
    char tipo[MAX_CARACTERES];
    char status[MAX_CARACTERES];
    ifstream leer("Destinos.txt");
    ofstream escA("Auxiliar.txt", ios::app);
    if(!leer.good())
    {
        QMessageBox msgBox;
        msgBox.setText("No existe el archivo de Destinos");
        msgBox.exec();
    }else
    {
       while(!leer.eof())
       {

           leer.read((char *)&a,sizeof(int));
           leer.read((char *)&cod,a);
           cod[a]='\0';
           leer.read((char *)&a,sizeof(int));
           leer.read((char *)&nombre,a);
           nombre[a]='\0';
           leer.read((char *)&a,sizeof(int));
           leer.read((char *)&tipo,a);
           tipo[a]='\0';
           leer.read((char *)&a,sizeof(int));
           leer.read((char *)&status,a);
           status[a]='\0';
           if(leer.eof())break;

           for(int i = 0; i < ui->tablaModificarDestinos->rowCount();i++)
           {
               if(strcmp(ui->tablaModificarDestinos->item(i,0)->text().toStdString().c_str(),cod)==0)
               {
                   strcpy(cod,ui->tablaModificarDestinos->item(i,0)->text().toStdString().c_str());
                   strcpy(nombre,ui->tablaModificarDestinos->item(i,1)->text().toStdString().c_str());
                   strcpy(tipo,ui->tablaModificarDestinos->item(i,2)->text().toStdString().c_str());
                   strcpy(status,ui->tablaModificarDestinos->item(i,3)->text().toStdString().c_str());
                   break;
               }
           }


            a=strlen(cod);
            escA.write((char *)&a, sizeof(int));
            escA.write((char *)&cod, a);

            a=strlen(nombre);
            escA.write((char *)&a, sizeof(int));
            escA.write((char *)&nombre, a);

            a=strlen(tipo);
            escA.write((char *)&a, sizeof(int));
            escA.write((char *)&tipo, a);

            a=strlen(status);
            escA.write((char *)&a, sizeof(int));
            escA.write((char *)&status, a);

       }
    }
    leer.close();
    escA.close();
    remove("Destinos.txt");
    rename("Auxiliar.txt", "Destinos.txt");
}

void MenuDestinos::on_botonEliminarDestino_clicked()
{
    int tamanioCadena;
    int posicion=0;
    char codigo[MAX_CARACTERES];
    char nombre[MAX_CARACTERES];
    char tipo[MAX_CARACTERES];
    char estatus[MAX_CARACTERES];
    int a;
    bool seEncontro = false;
    ifstream lee("Destinos.txt",ios::app);
    ofstream escA("Auxiliar.txt",ios::app);

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
            lee.read((char *)&codigo, tamanioCadena);
            codigo[tamanioCadena] = '\0';
            lee.read((char *)&tamanioCadena,sizeof(int));
            lee.read((char *)&nombre, tamanioCadena);
            nombre[tamanioCadena] = '\0';
            lee.read((char *)&tamanioCadena,sizeof(int));
            lee.read((char *)&tipo, tamanioCadena);
            tipo[tamanioCadena] = '\0';
            lee.read((char *)&tamanioCadena,sizeof(int));
            lee.read((char *)&estatus, tamanioCadena);
            estatus[tamanioCadena] = '\0';

            //Ya leyo todas las partes del objeto
            if(lee.eof())break;
            if(ui->inputCodigoDEliminar->text().toStdString()!= "" && strcmp(codigo,ui->inputCodigoDEliminar->text().toStdString().c_str())== 0){
                seEncontro = true;
                eliminarDestinoEnMatriz(posicion);
                QMessageBox msgBox;
                msgBox.setText(QString::number(posicion));
                msgBox.exec();
            } else if(ui->inputNombreDEliminar->text().toStdString()!="" && strcmp(nombre,ui->inputNombreDEliminar->text().toStdString().c_str())== 0){
                seEncontro = true;
                eliminarDestinoEnMatriz(posicion);

            } else if(ui->inputTipoDEliminar->text().toStdString()!="" && strcmp(tipo,ui->inputTipoDEliminar->text().toStdString().c_str())== 0){
                seEncontro = true;
                eliminarDestinoEnMatriz(posicion);

            } else if(ui->inputEstatusDEliminar->text().toStdString()!="" && strcmp(estatus,ui->inputEstatusDEliminar->text().toStdString().c_str())==0){
                seEncontro = true;
                eliminarDestinoEnMatriz(posicion);
            }else{
                a=strlen(codigo);
                escA.write((char *)&a, sizeof(int));
                escA.write((char *)&codigo, a);

                a=strlen(nombre);
                escA.write((char *)&a, sizeof(int));
                escA.write((char *)&nombre, a);

                a=strlen(tipo);
                escA.write((char *)&a, sizeof(int));
                escA.write((char *)&tipo, a);

                a=strlen(estatus);
                escA.write((char *)&a, sizeof(int));
                escA.write((char *)&estatus, a);

            }
            posicion++;
            if(lee.eof())break;
       }
    }
    lee.close();
    escA.close();
    remove("Destinos.txt");
    rename("Auxiliar.txt", "Destinos.txt");
    if(seEncontro)
    {
        QMessageBox msgBox;
        msgBox.setText("Se elimino correctamente el destino o destinos deseados. ");
        msgBox.exec();
    }else
    {
        QMessageBox msgBox;
        msgBox.setText("No se encontro destino o destinos deseados a eliminar. ");
        msgBox.exec();
    }

    reEnumerar();
    limpiarTablaDestinos();
    ui->inputCodigoD->setText(QString::number(contarRegistros()));

}

