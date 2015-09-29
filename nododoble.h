#ifndef NODODOBLE_H
#define NODODOBLE_H

#include <iostream>

using namespace std;
template <class T>
class NodoDoble{
private:
   T elemento;
   int posn;
   NodoDoble<T>* anterior;
   NodoDoble<T>* siguiente;
public:
    int getPosn();
    void setposn(int a);
    NodoDoble(T elemento);
    NodoDoble(NodoDoble<T>* a,T elemento,NodoDoble<T>* d);
    void setData(T a);
    void setPrev(NodoDoble<T>* a);
    void setNext(NodoDoble<T>* a);
    T getData();
    NodoDoble<T>* getPrev();
    NodoDoble<T>* getNext();
    };
template <class T>
int NodoDoble<T>::getPosn()
{
    return posn;
}
template <class T>
void NodoDoble<T>::setposn(int a)
{
    posn=a;
}
template <class T>
NodoDoble<T>::NodoDoble(T elemento){
   this->elemento=elemento;
  siguiente=anterior=NULL;}

template <class T>
NodoDoble<T>::NodoDoble(NodoDoble<T>* a,T elemento,NodoDoble<T>* d){
   this->elemento=elemento;
   siguiente=d;
   anterior=a;}

template <class T>
T NodoDoble<T>::getData(){
    return elemento;}
template <class T>
void NodoDoble<T>::setData(T e){
    elemento=e;}

template <class T>
NodoDoble<T>* NodoDoble<T>::getNext(){
    return siguiente;}

template <class T>
NodoDoble<T>* NodoDoble<T>::getPrev(){
    return anterior;}

template <class T>
void NodoDoble<T>::setNext(NodoDoble<T>* a){
     siguiente=a;}

template <class T>
void NodoDoble<T>::setPrev(NodoDoble<T>* a){
     anterior=a;}
#endif // NODODOBLE_H
