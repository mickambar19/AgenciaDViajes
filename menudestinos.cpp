#include "menudestinos.h"
#include "ui_menudestinos.h"

MenuDestinos::MenuDestinos(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuDestinos)
{
    ui->setupUi(this);
}

MenuDestinos::~MenuDestinos()
{
    delete ui;
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
