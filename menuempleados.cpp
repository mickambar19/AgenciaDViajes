#include "menuempleados.h"
#include "ui_menuempleados.h"

MenuEmpleados::MenuEmpleados(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuEmpleados)
{
    ui->setupUi(this);
    ui->inputCodigoEmpleado->setEnabled(false);
    ui->inputContraseniaEmpleadoMod->setEnabled(false);
    ui->inputCodigoEmpleado->setText( QString::number(contarRegistros()));
    ui->inputContraseniaEmpleadoEliminar->setEnabled(false);
}

MenuEmpleados::~MenuEmpleados()
{
    delete ui;
}

void MenuEmpleados::limpiarVentana()
{
    ui->inputCodigoEmpleado->setText(QString::number(contarRegistros()));
    ui->inputNombreEmpleado->setText("");
    ui->inputTipoEmpleado->setText("");
    ui->inputUsuarioEmpleado->setText("");
    ui->inputContraseniaEmpleado->setText("");
}

void MenuEmpleados::limpiarTablaEmpleados()
{
    for(int i = 0; i < ui->tablaEmpleados->rowCount();)
    {
        delete ui->tablaEmpleados->item(i,0);
        delete ui->tablaEmpleados->item(i,1);
        delete ui->tablaEmpleados->item(i,2);
        delete ui->tablaEmpleados->item(i,3);

        ui->tablaEmpleados->removeRow(i);
    }
    for(int i = 0; i < ui->tablaEmpleados->columnCount();)
    {
        ui->tablaEmpleados->removeColumn(i);
    }

    for(int i = 0; i < ui->tablaModificarEmpleados->rowCount();)
    {
        delete ui->tablaModificarEmpleados->item(i,0);
        delete ui->tablaModificarEmpleados->item(i,1);
        delete ui->tablaModificarEmpleados->item(i,2);
        delete ui->tablaModificarEmpleados->item(i,3);

        ui->tablaModificarEmpleados->removeRow(i);
    }
    for(int i = 0; i < ui->tablaModificarEmpleados->columnCount();)
    {
        ui->tablaModificarEmpleados->removeColumn(i);
    }
}

int MenuEmpleados::contarRegistros()
{
    Empleado empleado;
    int i;
    ifstream lee("Empleados.txt",ios::app);
    i=1;

    if(!lee.good())
    {
        QMessageBox msgBox;
        msgBox.setText("No existe el archivo de Empleados");
        msgBox.exec();
    }else
    {
        while(!lee.eof())
        {
            lee.read((char *)&empleado,sizeof(empleado));

            if(lee.eof())break;


                i++; //se incrementa un nuevo registro empleado
        }
    }
    lee.close();
    return i;
}

void MenuEmpleados::reEnumerar()
{

    int x = 1;
    char aux[MAX_CARACT];
    Empleado empleado;
    ifstream leer("Empleados.txt");
    ofstream escA("Auxiliar.txt");
    if(!leer.good())
    {
        QMessageBox msgBox;
        msgBox.setText("No existe el archivo de Empleados");
        msgBox.exec();
    }else
    {
       while(!leer.eof())
       {
           leer.read((char *)&empleado,sizeof(empleado));

           if(leer.eof())break;

               itoa(x,aux,10);
               empleado.setCodigoEmpleado(x);
               escA.write((char *)&empleado,sizeof(empleado));
            x++;
       }
    }
    leer.close();
    escA.close();
    remove("Empleados.txt");
    rename("Auxiliar.txt", "Empleados.txt");
}

void MenuEmpleados::on_botonAceptarAgregaEmpleado_clicked()
{
    Empleado empleado;
    bool formularioCompleto;//si sigue siendo cero al final no hubo errores
    if( ui->inputCodigoEmpleado->text().toStdString()=="" ||
        ui->inputNombreEmpleado->text().toStdString()=="" ||
        ui->inputTipoEmpleado->text().toStdString()=="" ||
        ui->inputUsuarioEmpleado->text().toStdString()=="" ||
        ui->inputContraseniaEmpleado->text().toStdString()=="" ){
        formularioCompleto = false;
    }else{
        formularioCompleto = true;
    }
    if(formularioCompleto){
        QMessageBox msgBox;
        ofstream esc1("Empleados.txt",ios::app);
        msgBox.setText("Se han obtenido los datos.");
        msgBox.setInformativeText("Quieres guardar los cambios?");
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Save);
        int ret = msgBox.exec();
        switch (ret) {
          case QMessageBox::Save:
                // Presiono Save
                empleado.setCodigoEmpleado(atoi(ui->inputCodigoEmpleado->text().toStdString().c_str()));
                empleado.setNombreEmpleado(ui->inputNombreEmpleado->text().toStdString());
                empleado.setTipoEmpleado(ui->inputTipoEmpleado->text().toStdString());
                empleado.setUsuarioEmpleado(ui->inputUsuarioEmpleado->text().toStdString());
                empleado.setContraseniaEmpleado(ui->inputContraseniaEmpleado->text().toStdString());
                esc1.write((char *)&empleado,sizeof(empleado));
                esc1.close();
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

void MenuEmpleados::on_botonActualizarEmpleados_clicked()
{

    QTableWidgetItem *elemento;
    Empleado empleado;
    ifstream lee("Empleados.txt",ios::app);
    QStringList titulosParteSuperior;
    int i = 0;
    titulosParteSuperior<<"Codigo"<<"Nombre"<<"Usuario"<<"Password"<<"Tipo";
    limpiarTablaEmpleados();
    if(!lee.good())
    {
        QMessageBox msgBox;
        msgBox.setText("No existe el archivo de Empleados");
        msgBox.exec();
    }else
    {
        ui->tablaEmpleados->insertColumn(0);
        ui->tablaEmpleados->insertColumn(1);
        ui->tablaEmpleados->insertColumn(2);
        ui->tablaEmpleados->insertColumn(3);
        ui->tablaEmpleados->insertColumn(4);
        ui->tablaEmpleados->setHorizontalHeaderLabels(titulosParteSuperior);
        while(!lee.eof())
        {

            ui->tablaEmpleados->insertRow(i);

            lee.read((char *)&empleado,sizeof(empleado));
            if(lee.eof())break;
            elemento = new QTableWidgetItem(QString::number(empleado.getCodigoEmpleado()));
            ui->tablaEmpleados->setItem(i,0,elemento);
            elemento = new QTableWidgetItem(QString::fromStdString(empleado.getNombreEmpleado()));
            ui->tablaEmpleados->setItem(i,1,elemento);
            elemento = new QTableWidgetItem(QString::fromStdString(empleado.getUsuarioEmpleado()));
            ui->tablaEmpleados->setItem(i,2,elemento);
            elemento = new QTableWidgetItem(QString::fromStdString(empleado.getContraseniaEmpleado()));
            ui->tablaEmpleados->setItem(i,3,elemento);
            elemento = new QTableWidgetItem(QString::fromStdString(empleado.getTipoEmpleado()));
            ui->tablaEmpleados->setItem(i,4,elemento);
            i++;

            if(lee.eof())break;
        }
    }
    ui->tablaEmpleados->removeRow(ui->tablaEmpleados->rowCount()-1);
    lee.close();

}

void MenuEmpleados::on_botonBuscarModEmpleados_clicked()
{
    Empleado empleado;
    QTableWidgetItem *elemColum1, *elemColum2, *elemColum3, *elemColum4, *elemColum5;
    ifstream lee("Empleados.txt",ios::app);
    QStringList titulosParteSuperior;
    titulosParteSuperior<<"Codigo"<<"Nombre"<<"Usuario"<<"Password"<<"Tipo";
    limpiarTablaEmpleados();

    if(!lee.good())
    {
        QMessageBox msgBox;
        msgBox.setText("No existe el archivo de Empleados");
        msgBox.exec();
    }else
    {
        ui->tablaModificarEmpleados->insertColumn(0);
        ui->tablaModificarEmpleados->insertColumn(1);
        ui->tablaModificarEmpleados->insertColumn(2);
        ui->tablaModificarEmpleados->insertColumn(3);
        ui->tablaModificarEmpleados->insertColumn(4);
        ui->tablaModificarEmpleados->setHorizontalHeaderLabels(titulosParteSuperior);
        while(!lee.eof())
        {

            lee.read((char *)&empleado,sizeof(empleado));

            //Ya leyo todas las partes del objeto
            elemColum1 = new QTableWidgetItem(QString::number(empleado.getCodigoEmpleado()));
            elemColum2 = new QTableWidgetItem(QString::fromStdString(empleado.getNombreEmpleado()));
            elemColum3 = new QTableWidgetItem(QString::fromStdString(empleado.getUsuarioEmpleado()));
            elemColum4 = new QTableWidgetItem(QString::fromStdString(empleado.getContraseniaEmpleado()));
            elemColum5 = new QTableWidgetItem(QString::fromStdString(empleado.getTipoEmpleado()));
            if(lee.eof())break;
            if(ui->inputCodigoEmpleadoMod->text().toStdString()!= "" && empleado.getCodigoEmpleado() == atoi(ui->inputCodigoEmpleadoMod->text().toStdString().c_str())){

                ui->tablaModificarEmpleados->insertRow(0);
                ui->tablaModificarEmpleados->setItem(0,0,elemColum1);
                ui->tablaModificarEmpleados->setItem(0,1,elemColum2);
                ui->tablaModificarEmpleados->setItem(0,2,elemColum3);
                ui->tablaModificarEmpleados->setItem(0,3,elemColum4);
                ui->tablaModificarEmpleados->setItem(0,4,elemColum5);
            } else if(ui->inputNombreEmpleadoMod->text().toStdString()!="" && empleado.getNombreEmpleado() == ui->inputNombreEmpleadoMod->text().toStdString()){

                ui->tablaModificarEmpleados->insertRow(0);
                ui->tablaModificarEmpleados->setItem(0,0,elemColum1);
                ui->tablaModificarEmpleados->setItem(0,1,elemColum2);
                ui->tablaModificarEmpleados->setItem(0,2,elemColum3);
                ui->tablaModificarEmpleados->setItem(0,3,elemColum4);
                ui->tablaModificarEmpleados->setItem(0,4,elemColum5);
            } else if(ui->inputTipoEmpleadoMod->text().toStdString()!="" && empleado.getTipoEmpleado()== ui->inputTipoEmpleadoMod->text().toStdString()){

                ui->tablaModificarEmpleados->insertRow(0);
                ui->tablaModificarEmpleados->setItem(0,0,elemColum1);
                ui->tablaModificarEmpleados->setItem(0,1,elemColum2);
                ui->tablaModificarEmpleados->setItem(0,2,elemColum3);
                ui->tablaModificarEmpleados->setItem(0,3,elemColum4);
                ui->tablaModificarEmpleados->setItem(0,4,elemColum5);
            } else if(ui->inputUsuarioEmpleadoMod->text().toStdString()!="" && empleado.getUsuarioEmpleado() == ui->inputUsuarioEmpleadoMod->text().toStdString()){

                ui->tablaModificarEmpleados->insertRow(0);
                ui->tablaModificarEmpleados->setItem(0,0,elemColum1);
                ui->tablaModificarEmpleados->setItem(0,1,elemColum2);
                ui->tablaModificarEmpleados->setItem(0,2,elemColum3);
                ui->tablaModificarEmpleados->setItem(0,3,elemColum4);
                ui->tablaModificarEmpleados->setItem(0,4,elemColum5);
            }
            if(lee.eof())break;

        }
    }
    lee.close();
}

void MenuEmpleados::on_botonGuardarModEmpleados_clicked()
{
    Empleado empleado;
    ifstream leer("Empleados.txt");
    ofstream escA("Auxiliar.txt", ios::app);
    if(!leer.good())
    {
        QMessageBox msgBox;
        msgBox.setText("No existe el archivo de Empleados");
        msgBox.exec();
    }else
    {
       while(!leer.eof())
       {

           leer.read((char *)&empleado,sizeof(empleado));

           if(leer.eof())break;

           for(int i = 0; i < ui->tablaModificarEmpleados->rowCount();i++)
           {
               if(atoi(ui->tablaModificarEmpleados->item(i,0)->text().toStdString().c_str()) == empleado.getCodigoEmpleado())
               {
                   empleado.setCodigoEmpleado(atoi(ui->tablaModificarEmpleados->item(i,0)->text().toStdString().c_str()));
                   empleado.setNombreEmpleado(ui->tablaModificarEmpleados->item(i,1)->text().toStdString());
                   empleado.setUsuarioEmpleado(ui->tablaModificarEmpleados->item(i,2)->text().toStdString());
                   empleado.setContraseniaEmpleado(ui->tablaModificarEmpleados->item(i,3)->text().toStdString());
                   empleado.setTipoEmpleado(ui->tablaModificarEmpleados->item(i,4)->text().toStdString());

                   break;
               }
           }


           escA.write((char *)&empleado,sizeof(empleado));

       }
    }
    leer.close();
    escA.close();
    remove("Empleados.txt");
    rename("Auxiliar.txt", "Empleados.txt");
}

void MenuEmpleados::on_botonEliminarModEmpleados_clicked()
{
    Empleado empleado;
    bool seEncontro = false;
    ifstream lee("Empleados.txt",ios::app);
    ofstream escA("Auxiliar.txt",ios::app);
    if(!lee.good())
    {
        QMessageBox msgBox;
        msgBox.setText("No existe el archivo de Empleados");
        msgBox.exec();
    }else
    {
        while(!lee.eof())
        {
            lee.read((char *)&empleado,sizeof(empleado));

            //Ya leyo todas las partes del objeto
            if(lee.eof())break;
            if(ui->inputCodigoEmpleadoEliminar->text().toStdString()!= "" && empleado.getCodigoEmpleado() == atoi(ui->inputCodigoEmpleadoEliminar->text().toStdString().c_str())){
                seEncontro = true;

            } else if(ui->inputNombreEmpleadoEliminar->text().toStdString()!="" && empleado.getNombreEmpleado() == ui->inputNombreEmpleadoEliminar->text().toStdString()){
                seEncontro = true;

            } else if(ui->inputTipoEmpleadoEliminar->text().toStdString()!="" && empleado.getTipoEmpleado() == ui->inputTipoEmpleadoEliminar->text().toStdString()){
                seEncontro = true;

            } else if(ui->inputUsuarioEmpleadoEliminar->text().toStdString()!="" && empleado.getUsuarioEmpleado() == ui->inputUsuarioEmpleadoEliminar->text().toStdString()){
                seEncontro = true;
            }else{
                escA.write((char *)&empleado,sizeof(empleado));
            }
            if(lee.eof())break;
       }
    }
    lee.close();
    escA.close();
    remove("Empleados.txt");
    rename("Auxiliar.txt", "Empleados.txt");
    if(seEncontro)
    {
        QMessageBox msgBox;
        msgBox.setText("Se elimino correctamente el destino o Empleados deseados. ");
        msgBox.exec();
    }else
    {
        QMessageBox msgBox;
        msgBox.setText("No se encontro destino o Empleados deseados a eliminar. ");
        msgBox.exec();
    }

    reEnumerar();
    limpiarTablaEmpleados();
    ui->inputCodigoEmpleado->setText(QString::number(contarRegistros()));

}
