#include "menuhoteles2.h"
#include "ui_menuhoteles2.h"

MenuHoteles2::MenuHoteles2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuHoteles2)
{
    ui->setupUi(this);
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
    QString codigoPais = ui->inputCodigoPaisHotel->text();
    QString nombreHotel = ui->inputNombreHotel->text();
    QString tarifa = ui->inputTarifaHotel->text();
    QString tipo = ui->inputTipoHotel->text();
    if(codigo == "" || codigoPais == ""|| nombreHotel == ""|| tarifa == "" || tipo == "")
    {
        // Se desprende un MessageBox Si el usuario no ingreso cualquiera de los anteriores datos
        if(codigo == "")
        {

        }else if(codigoPais == "")
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
        hotel.setCodigo(codigo.toInt());
        hotel.setCodigoPais(codigoPais.toInt());
        hotel.setNombreHotel(nombreHotel.toStdString());
        hotel.setTipo(tipo.toStdString());
        hotel.setTarifa(tarifa.toInt());
        indice.setLlave(hotel.getCodigo());
        ofstream escH("Hoteles.txt",ios::app);
        ofstream escI("Indices.txt",ios::app);
        escH.write((char *)&hotel,sizeof(hotel));
        escH.seekp(0,escH.end);
        indice.setPosicion(escH.tellp());
        indice.setPosicion(indice.getPosicion()-sizeof(hotel));
        escI.write((char *)&indice,sizeof(indice));
        escI.close();
        escH.close();
    }
}
