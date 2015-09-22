#include "funciones.h"
#include <QMessageBox>
int matrizPes[30][30];
void eliminarDestinoEnMatriz(int valor)
{
    leerMatriz();
    int matrizAux [30][30];
    int x,y;
    x=y=0;
    memset(matrizAux,0,sizeof(matrizAux));

    for(int i = 0 ; i < 30; i++)
    {
        if(valor==i)
        {
            x=i+1;
        }
            for(int j = 0 ; j < 30; j++)
            {
                if(valor == j)
                {
                    y=j+1;
                }
                matrizAux[i][j] = matrizPes[x][y];
                y++;
            }
            y=0;
            x++;
    }
    memset(matrizPes,0,sizeof(matrizPes));
    for(int i = 0 ; i < 30; i++){
        for(int j = 0 ; j < 30; j++){
            matrizPes[i][j]= matrizAux[i][j];
        }
    }
    guardarMatriz();

}

void leerMatriz(){
    int col,fil;
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
                matrizPes[fil][col] = a;
                col++;
            }
            if(leePesos.eof())break;
        }
    }

    leePesos.close();
}
void guardarMatriz()
{
    remove("Pesos.txt");
    ofstream esc("Pesos.txt",ios::app);
    for(int fil= 0; fil<30; fil++)
    {
        for(int col= 0; col<30; col++)
        {
            esc<<matrizPes[fil][col]<<"|";

        }
        esc<<"&|";
    }
    esc.close();

}
