#include "NodoSecundario.h"
#include <cstring>
NodoSecundario::NodoSecundario()
{
}

bool NodoSecundario::operator==(const NodoSecundario &d){
    /*string obj1,obj2;
    obj1=pais;
    obj2=d.pais;*/
     return (strcmp(d.pais,pais)==0);
    }
bool NodoSecundario::operator<(const NodoSecundario &d){
    /*string obj1,obj2;
    obj1=pais;
    obj2=d.pais;*/
     return (strcmp(d.pais,pais)==0);
    }
bool NodoSecundario::operator<=(const NodoSecundario &d){
    /*string obj1,obj2;
    obj1=pais;
    obj2=d.pais;*/
     return (strcmp(d.pais,pais)==0);
    }
ostream& operator<<(ostream& os,NodoSecundario &d){

    return os;
    }
bool NodoSecundario::operator!=(const NodoSecundario &d){
    /*string obj1,obj2;
    obj1=pais;
    obj2=d.pais;*/
     return (strcmp(d.pais,pais)==0);
    }
