#include "secundario.h"
#include <fstream>
#include <cstring>
bool Secundario::operator==(const Secundario &d){
    string obj1,obj2;
    obj1=pais;
    obj2=d.pais;
     return obj1==obj2;
    }
bool Secundario::operator<(const Secundario &d){
    string obj1,obj2;
    obj1=pais;
     obj2=d.pais;
    return obj1<obj2;
    }
bool Secundario::operator<=(const Secundario &d){
    string obj1,obj2;
    obj1=pais;
     obj2=d.pais;
    return obj1<=obj2;
    }
ostream& operator<<(ostream& os,Secundario &d){
       /*os<<"-----------------\n";
       os<<"Primer nodo     :"<<d.primerNodo<<endl;
       os<<"extension   :"<<d.extension<<endl;
       os<<"-----------------\n\n";*/
    return os;
    }




void Secundario::inicializar()
{

    ofstream escS("Secundario.txt",ios::app);
    int a;
    a=-1;
    //QStringList paisesDisponibles;
    ifstream lee("Destinos.txt",ios::app);
    int tamanioCadena;
    char cadenaLeida[100];
    int i = 0;
    if(!lee.good())
    {
        //QMessageBox msgBox;
        //msgBox.setText("No existe el archivo de Destinos");
        //msgBox.exec();
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
            //Se copia el pais que existe en archivo de paises
            //y se inicializa que su primera posicion esta en -1 por que no existe ningun
            //otro hotel con ese pais
            escS.write((char*)this,sizeof(Secundario));
            strcpy(this->pais,cadenaLeida);
            this->primerNodo=a;
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
    escS.close();
}
