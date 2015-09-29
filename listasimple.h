#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H

#include <iostream>
#include "nododoble.h"
#include <cstdlib>
#include <stdexcept>

using namespace std;
template <class T>
class ListaSimple{
    private:
        NodoDoble<T>* primero;
        void quickSort(NodoDoble<T> *izq, NodoDoble<T> *der);
        void bubbleSort(NodoDoble<T> **elem,int conta);
        void selectionSort(NodoDoble<T> **elem,int conta);
        void insertionSort(NodoDoble<T> **elem,int conta);
        void shellSort(NodoDoble<T> **elem,int conta);
        T* merge_sort(T arr[], int n);
        T* merge(T arr1[], int size1, T arr2[], int size2);
       NodoDoble<T>* binaryAlgorithm(T e,NodoDoble<T> **elem, int conta);
    public:
        ListaSimple();
        ~ListaSimple();
        void initialize();
        bool isEmpty();
        void printAll();
        void printOne(NodoDoble<T>* a);
        NodoDoble<T>* first();
        NodoDoble<T>* last();
        NodoDoble<T>* getPrev(NodoDoble<T>* a);
        NodoDoble<T>* getNext(NodoDoble<T>* a);
        NodoDoble<T>* linealSearch(T elem);
        void order();
        void orderBubble();
        void orderInsertion();
        void orderShell();
        void orderSelection();
        void insertOneBefore(T elem, NodoDoble<T>* a);
        void insertOneAfter(T elem, NodoDoble<T>* a);
        NodoDoble<T>* binarySearch(T elem);
        void insertOrdered(T elem);
        void delete_e(NodoDoble<T>* a);
        void deleteAll();//anula
        void orderMerge();

        };

template <class T>
ListaSimple<T>::ListaSimple(){
    initialize();}

    template <class T>
ListaSimple<T>::~ListaSimple(){
    deleteAll();}

    template <class T>
void ListaSimple<T>::initialize(){
    primero=NULL;
    }

    template <class T>
bool ListaSimple<T>::isEmpty(){
    NodoDoble<T>* n;
    n=primero;
    if(n==NULL){
    return true;
    }
     else return false;
    }

    template <class T>
void ListaSimple<T>::printAll(){
    int i=1;
    T e;
    NodoDoble<T>* n;
    n=primero;
    while(n!=NULL){
    e=n->getData();
    cout<<i<<"\t"<<e<<endl;
    n=n->getNext();
    i++;
    }
    }

    template <class T>
void ListaSimple<T>::printOne(NodoDoble<T>* a){
    T e;
    if(a!=NULL)
    e=a->getData();
    cout<<"\t"<<e<<endl;
    }

    template <class T>
void ListaSimple<T>::insertOrdered(T elem){
    NodoDoble<T>* nuevo;
    T e;
    nuevo=new NodoDoble<T>(elem);
    if(primero==NULL){
    primero=nuevo;
    }else if(elem<primero->getData()){
    nuevo->setNext(primero);
    primero->setPrev(nuevo);
    primero=nuevo;
    }
    else{
    NodoDoble<T> *anterior,*p;
    anterior=p=primero;
    while(p->getNext()!=NULL && p->getData()<elem){
    anterior=p;
    p=p->getNext();
    }
    if(p->getData()<elem)//se inserta despues del ultimo
    anterior=p;
    nuevo->setNext(anterior->getNext());
    nuevo->setPrev(anterior);
    anterior->setNext(nuevo);
    (anterior->getNext())->setPrev(nuevo);
    }
    }

    template <class T>
NodoDoble<T>* ListaSimple<T>::linealSearch(T elem){
    NodoDoble<T>* p;
    T e;
    p=primero;
    while(p!=NULL){
    if(elem==p->getData()){
    e=p->getData();
    cout<<"te quedaste ciclado\n";
    return p;
    }
    p=p->getNext();
    }
    return NULL;
    }

    template <class T>
void ListaSimple<T>::delete_e(NodoDoble<T>* a){
    NodoDoble<T> *actual=a;
    NodoDoble<T> *anterior,*siguiente;
   if(!isEmpty()){
   if(actual==NULL){}
   else if(actual->getNext()==NULL && actual->getPrev()==NULL){
       delete a;
       primero=NULL;
   }else{
        siguiente=actual->getNext();
        anterior=actual->getPrev();
        if(siguiente!=NULL)siguiente->setPrev(anterior);
        if(anterior!=NULL) anterior->setNext(siguiente);
        if(actual==primero)primero=siguiente;
        delete actual;
        }}

    }

    template <class T>
void ListaSimple<T>::deleteAll(){
    NodoDoble<T> *anterior;
    if(!isEmpty()){ while(primero!=NULL){
    anterior=primero;
    primero=primero->getNext();
    delete anterior;
    }}
    }

    template <class T>
NodoDoble<T>* ListaSimple<T>::first(){
    return primero;
    }

    template <class T>
NodoDoble<T>* ListaSimple<T>::last(){
    NodoDoble<T>* n;
    n=primero;
    if(n==NULL){

    }
    else
    {
        while(n->getNext()!=NULL){
            n=n->getNext();
        }
    }
    return n;
    }

    template <class T>
NodoDoble<T>* ListaSimple<T>::getPrev(NodoDoble<T>* a){
     if(a==first()){
        return NULL;}else
        return a->getPrev();}

    template <class T>
NodoDoble<T>* ListaSimple<T>::getNext(NodoDoble<T>* a){
       if(a==last()){return NULL;}else
        return a->getNext();
    }

    template <class T>
void ListaSimple<T>::order(){
     int i=0;
     NodoDoble<T>* inicio;
     NodoDoble<T>* fin;
     NodoDoble<T>* aux;
     aux=first();
     T e;
     do
     {   if(aux==NULL) break;
         aux->setposn(i);
         i++;
         e=aux->getData();
         aux=aux->getNext();

     }while(aux!=NULL);
     inicio=first();
     fin=last();
     quickSort(inicio,fin);
    }

    template <class T>
void ListaSimple<T>::insertOneBefore(T elem, NodoDoble<T>* a){
    NodoDoble<T>* nuevo,*aux;
    T e;
    nuevo=new NodoDoble<T>(elem);
    if(a==NULL){
        primero=nuevo;
    }else if(a==primero){
        nuevo->setNext(primero);
        primero->setPrev(nuevo);
        primero=nuevo;
    }else{
    aux=getPrev(a);
    nuevo->setNext(a);
    a->setPrev(nuevo);
    if(aux!=NULL){
    aux->setNext(nuevo);}
    nuevo->setPrev(aux);
    }
    }

 template <class T>
void ListaSimple<T>::insertOneAfter(T elem, NodoDoble<T>* a){
    NodoDoble<T>* nuevo,*aux;
    nuevo=new NodoDoble<T>(elem);
    if(a==NULL){
        primero=nuevo;
    }else if(a==primero){
        aux=primero->getNext();
        nuevo->setNext(aux);
        if(aux!=NULL){
        aux->setPrev(nuevo);}
        primero->setNext(nuevo);
        nuevo->setPrev(primero);
    }else{
    nuevo->setNext(a->getNext());
    if(a->getNext()!=NULL){
    a->getNext()->setPrev(nuevo);}
    a->setNext(nuevo);
    nuevo->setPrev(a);}
    }

template <class T>
void ListaSimple<T>::quickSort(NodoDoble<T> *izq,NodoDoble<T> * der){
NodoDoble<T>* pivote;
NodoDoble<T>* g;
NodoDoble<T>* h;
T aux, e;
pivote=izq;
g=izq;
h=der;

while(g->getPosn()<=h->getPosn())
{
    while(g->getData()<pivote->getData()) g=g->getNext();
    while(pivote->getData()<h->getData()) h=h->getPrev();
    cout<<"aqui estas 4\n";
    if(g->getPosn()<=h->getPosn())
    {
        e=g->getData();
        cout<<"g: \n"<<e<<g->getPosn()<<endl;
        e=h->getData();
        cout<<"h: \n"<<e<<h->getPosn()<<endl;
        aux=g->getData();
        g->setData(h->getData());
        h->setData(aux);
        g=g->getNext();
        if(h->getPrev()!=NULL){
            h=h->getPrev();
        }
    }
        cout<<"aqui estas6\n";
}
cout<<"aqui estas7\n";
if(izq->getPosn()<h->getPosn())quickSort(izq,h);
if(g->getPosn()<der->getPosn())quickSort(g,der);
}
    template<class T>
void ListaSimple<T>::orderBubble(){
    NodoDoble<T> **arr;
    NodoDoble<T> *p;
    int contador=0;
    int g;
    p=primero;
    while(p!=NULL){
    contador++;
    p=p->getNext();
    }
    if(contador<2) return; // si hay cero o 1 elemento no hay nada qu ordenar
    arr=new NodoDoble<T> *[contador];
    p=primero;
    contador=0;
    while(p!=NULL){
    arr[contador++]=p;
    p=p->getNext();
    }
    bubbleSort(arr,contador-1);
    primero=arr[0];
    arr[0]->setPrev(NULL);
    for(g=0;g<contador-1;g++){
    arr[g]->setNext(arr[g+1]);
    arr[g+1]->setPrev(arr[g]);
    }
    arr[contador-1]->setNext(NULL);
    delete arr;
    }

    template<class T>
void ListaSimple<T>::bubbleSort(NodoDoble<T> **elem,int conta){
    NodoDoble<T> *aux;
    int h,g,d=conta;
    for(h=conta;h>0;h--){
    for(g=0;g<h;g++){
    if(elem[g+1]->getData()<elem[g]->getData()){
    aux=elem[g];
    elem[g]=elem[g+1];
    elem[g+1]=aux;
    d-=1;
    }}if(d==conta){
    break;
    d=conta;}
    }
    }
    template<class T>
void ListaSimple<T>::orderInsertion(){
    NodoDoble<T> **arr;
    NodoDoble<T> *p;
    int contador=0;
    int g;
    p=primero;
    while(p!=NULL){
    contador++;
    p=p->getNext();
    }
    if(contador<2) return; // si hay cero o 1 elemento no hay nada qu ordenar
    arr=new NodoDoble<T> *[contador];
    p=primero;
    contador=0;
    while(p!=NULL){
    arr[contador++]=p;
    p=p->getNext();
    }
    insertionSort(arr,contador-1);
    arr[0]->setPrev(NULL);
    for(g=0;g<contador-1;g++){
    arr[g]->setNext(arr[g+1]);
    arr[g+1]->setPrev(arr[g]);
    }
    arr[contador-1]->setNext(NULL);
    delete arr;
    }

    template<class T>
void ListaSimple<T>::insertionSort(NodoDoble<T> **elem,int conta){
    int g,h;
    NodoDoble<T> *aux;
    g=1;
    while(g<=conta){// 7 es como ultimo
    h=g;
    aux=elem[g];
    while(h>0 && aux->getData()<elem[h-1]->getData()){
    elem[h]=elem[h-1];
    h--;}
    if(g!=h){
    elem[h]=aux;}
    g++;
    }}

    template<class T>
void ListaSimple<T>::orderShell(){
    NodoDoble<T> **arr;
    NodoDoble<T> *p;
    int contador=0;
    int g;
    p=primero;
    while(p!=NULL){
    contador++;
    p=p->getNext();
    }
    if(contador<2) return; // si hay cero o 1 elemento no hay nada qu ordenar
    arr=new NodoDoble<T> *[contador];
    p=primero;
    contador=0;
    while(p!=NULL){
    arr[contador++]=p;
    p=p->getNext();
    }
    shellSort(arr,contador);
    primero=arr[0];
    arr[0]->setPrev(NULL);
    for(g=0;g<contador-1;g++){
    arr[g]->setNext(arr[g+1]);
    arr[g+1]->setPrev(arr[g]);
    }
    arr[contador-1]->setNext(NULL);
    delete arr;
    }

    template<class T>
void ListaSimple<T>::shellSort(NodoDoble<T> **elem,int conta){
    int i, j, inc;
    NodoDoble<T> *temp;
    for (inc = conta/2; inc > 0; inc /= 2)
    for (i = inc; i < conta; i++)
    for (j=i-inc; j>=0 && elem[j+inc]->getData()<elem[j]->getData(); j-=inc) {
    temp = elem[j];
    elem[j] = elem[j+inc];
    elem[j+inc] = temp;
    }
    }

    template<class T>
void ListaSimple<T>::orderSelection(){
    NodoDoble<T> **arr;
    NodoDoble<T> *p;
    int contador=0;
    int g;
    p=primero;
    while(p!=NULL){
    contador++;
    p=p->getNext();
    }
    if(contador<2) return; // si hay cero o 1 elemento no hay nada qu ordenar
    arr=new NodoDoble<T> *[contador];
    p=primero;
    contador=0;
    while(p!=NULL){
    arr[contador++]=p;
    p=p->getNext();
    }
    selectionSort(arr,contador-1);
    primero=arr[0];
    arr[0]->setPrev(NULL);
    for(g=0;g<contador-1;g++){
    arr[g]->setNext(arr[g+1]);
    arr[g+1]->setPrev(arr[g]);
    }
    arr[contador-1]->setNext(NULL);
    delete arr;
    }

    template<class T>
void ListaSimple<T>::selectionSort(NodoDoble<T> **elem,int conta)
    {     int menor, g, h;
    NodoDoble<T> *aux;
    g=0;
    while(g<conta){
    h=g+1;
    menor=g;
    while(h<=conta){
    if(elem[h]->getData()<elem[menor]->getData()){
    menor=h;}
    h++;}
    if(menor!=g){
    aux=elem[g];
    elem[g]=elem[menor];
    elem[menor]=aux;
    }
    g++;}}
template<class T>
void ListaSimple<T>::orderMerge(){
    T *arr;
    T *aux;
    NodoDoble<T> *p;
    int contador=0;
    int g;
    p=primero;
    while(p!=NULL){
    contador++;
    p=p->getNext();
    }
    if(contador<2) return; // si hay cero o 1 elemento no hay nada qu ordenar
    arr=new T[contador];
    p=primero;
    contador=0;
    while(p!=NULL){
    arr[contador++]=p->getData();
    p=p->getNext();
    }
    aux=new T [contador];
    aux=merge_sort(arr,contador);
    p=primero;
    for(g=0;g<=contador-1;++g){
        p->setData(aux[g]);
        p=p->getNext();
    }

    delete arr;
    delete aux;
}

template <class T>
T* ListaSimple<T>:: merge_sort(T arr[], int n)
{
   if(n < 2){return arr;}
   int mid = n/2;
   T *arr1 = merge_sort(arr,mid);
   T *arr2 = merge_sort(arr+mid,n-mid);
   return merge(arr1, mid, arr2, n-mid);
}

template <class T>
T* ListaSimple<T>:: merge(T arr1[], int size1, T arr2[], int size2)
{
   int i = 0,j = 0;

   T* out_array = new T[size1+size2];

   while((i < size1) && (j < size2))
   {
       if(arr2[j] <=arr1[i])
       {

           out_array[i+j] = arr1[i];
           ++i;
       }
       else
       {

           out_array[i+j] = arr2[j];
           ++j;
       }
   }
   while(i < size1)
   {
       //copy the reminder
       out_array[i+j] = arr1[i];
       i++;
   }
   while( j < size2)
   {
       out_array[i+j] = arr2[j];
       j++;
   }
   return out_array;
}
    template<class T>
NodoDoble<T>* ListaSimple<T>::binarySearch(T elem){
    NodoDoble<T> **arr;
    NodoDoble<T> *p,*encontrado;
    int contador=0;
    int g;
    p=primero;
    while(p!=NULL){
    contador++;
    p=p->getNext();
    }
    if(contador<2) {
    if(primero->getData()==elem){
    return primero; }
    else return NULL;} // si hay cero o 1 elemento no hay nada qu ordenar
    arr=new NodoDoble<T> *[contador];
    p=primero;
    contador=0;
    while(p!=NULL){
    arr[contador++]=p;
    p=p->getNext();
    }
    quickSort(arr,0,contador-1);
    encontrado=binaryAlgorithm(elem,arr,contador-1);
    primero=arr[0];
    for(g=0;g<contador-1;g++){
    arr[g]->setNext(arr[g+1]);
    }
    arr[contador-1]->setNext(NULL);
    delete arr;
    if(encontrado!=NULL){
    return encontrado;}
    else return NULL;
    }

    template<class T>
NodoDoble<T>* ListaSimple<T>::binaryAlgorithm(T e,NodoDoble<T> **elem, int conta)
    {
    int i=0,j=conta;
    int medio;
    while(i<=j)
    {   medio=(i+j)/2;
    if(elem[medio]->getData()==e)
    {return elem[medio];}
    if(e<elem[medio]->getData())
    {j=medio-1;}
    else
    {i=medio+1;}
    } return NULL;
    }
#endif // LISTASIMPLE_H
