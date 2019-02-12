#include<iostream>

#include"container.h"

//COSTRUTTORI
template<class T>
Container<T>::Container(T i, Container* p, Container * c): info(i), prev(p), next(c){}

//METODI GENERALI

template<class T>
int Container<T>::size()const{
    int x=0;
    Container *z=this;
    while(z){
        x++;
        z=z->next;
    }
    return x;
}

template<class T>
bool Container<T>::empty() const{return (this)? true : false;}

//METODI DI INSERIMENTO

/*template<class T>
void Container<T>::push_front(T *x){
    x->next=this;
    this=x;
}

template<class T>
void Container<T>::insert(T x){
    Container* z=new Container(x);
    z->next=this;
    this=z;
}*/



//METODI DI RICERCA
template<class T>
bool Container<T>::find(T x)const{
    while(this && this->info!=x)
         this=this->next;
    if(this->info==x)
         return true;
    return false;
}

template<class T>
Container<T> Container<T>::find(T x){
    Container *z=new Container();
    while(this){
        if(x==this){
        }
    }
}


//METODI DI CANCELLAZIONE
template<class T>
T Container<T>::pop_front(){
}



template<class T>
void Container<T>::erase(T x){
}


//DISTRUTTORE
template<class T>
Container<T>::~Container(){if(next) delete next;}


