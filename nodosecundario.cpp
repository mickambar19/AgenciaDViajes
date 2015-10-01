#include "NodoSecundario.h"

NodoSecundario::NodoSecundario()
{
}

bool NodoSecundario::operator==(const NodoSecundario &d){
    string obj1,obj2;
    obj1=pais;
    obj2=d.pais;
     return obj1==obj2;
    }
bool NodoSecundario::operator<(const NodoSecundario &d){
    string obj1,obj2;
    obj1=pais;
     obj2=d.pais;
    return obj1<obj2;
    }
bool NodoSecundario::operator<=(const NodoSecundario &d){
    string obj1,obj2;
    obj1=pais;
     obj2=d.pais;
    return obj1<=obj2;
    }
ostream& operator<<(ostream& os,NodoSecundario &d){

    return os;
    }
bool NodoSecundario::operator!=(const NodoSecundario &d){
    string obj1,obj2;
    obj1=pais;
    obj2=d.pais;
     return obj1!=obj2;
    }
