#ifndef CONTAINER
#define CONTAINER

#include<iostream>
#include <typeinfo>
#include"device.h"

template <class T>
class Container {
private:
    class nodo {
      public:
        T info;
        nodo *next;
        nodo(const T t=NULL, nodo* n=nullptr): info(t), next(n) {}
        ~nodo() {if(next) delete next;}
      };
    nodo* first;
public:
    //COSTRUTTORI
    Container(T=NULL);

    //METODI GENERALI
    int size();
    bool empty()const;

    //METODO DI INSERIMENTO
    void insert(T x);

    //DISTRUTTORE
    ~Container();

    //METODO DI RICERCA
    bool find(T)const; // restituisce true se nel container di invocazione esiste x
    template<class U>
    Container<U> find(U) const; //restituisce un container contenente tutti e soli gli oggetti di tipo U

    //METODO DI CANCELLAZIONE
    template<class U>
    void erase(U*) ; // cancella dalla lista di invocazione tutti gli oggetti di tipo U

    //CLASSE ITERATORE
    class Iterator {
        friend class Container<T>;
      private:
         nodo* pt;
        Iterator(nodo* p): pt(p) {}
      public:
        Iterator(): pt(nullptr) {}

        Iterator& operator++() {
          if(pt) {
            if(pt->next == nullptr) {pt = pt+1;}
            else pt = pt->next;
          }
          return *this;
        }

        const T& operator*() const {
          return pt->info;
        }
        const T* operator->() const {
          return &(pt->info);
        }
        bool operator==(const Iterator& x) const {
          return pt == x.pt;
        }
        bool operator!=(const Iterator& x) const {
          return pt != x.pt;
        }
    };
      Iterator begin() const {
        return Iterator(first);
      }

      Iterator end()const{
        if(first==nullptr) return nullptr;
        nodo* x=first;
        while(x->next)
            x = x->next;
        return ++x;
      }

};


//COSTRUTTORI
template<class T>
Container<T>::Container(T t){
    if(!t) first = nullptr;
    else
        first = new nodo(t);
}




//METODI GENERALI

template<class T>
int Container<T>::size(){
    if(empty())
        return 0;
    int count = 0;
    for(Iterator i=begin(); i!=end(); ++i)
        ++count;
    return count;
}

template<class T>
bool Container<T>::empty() const{ return !first; }

//METODO DI INSERIMENTO

template<class T>
void Container<T>::insert(T x){
    nodo* f = new nodo(x,nullptr);
       if(first==NULL)
           first=f;
       else{
           nodo* z=first;
           while(z->next)
                z=z->next;
           z->next=f;
       }
}

//METODO DI RICERCA

template<class T>
template<class U>
Container<U> Container<T>::find(U t) const{
    Container<U> x;
    nodo* z=first;
    while(z){
        if(dynamic_cast<U>((z->info)) !=NULL)
            x.insert(dynamic_cast<U>((z->info)));
            z=z->next;
    }
    return x;
}

template<class T>
bool Container<T>::find(T x)const{
    nodo* z=first;
    while(z){
        if(z==x)
            return true;
    z=z->next;
    }
    return false;
}

//METODI DI CANCELLAZIONE

template<class T>
template<class U>
void Container<T>::erase(U* w){
    nodo* x;
    nodo* z=this->first;
    while(z && first==z){
        if(dynamic_cast<U*>((z->info)) !=NULL){
            nodo* temp=z;
            z=z->next;
            this->first=z;
            temp->next=nullptr;
            delete temp;
        }
        else{
            x=z;
            z=z->next;
        }
    }
    while(z){
        if(dynamic_cast<U*>((z->info)) !=NULL){
            nodo* temp=z;
            z=z->next;
            x->next=z;
            temp->next=nullptr;
            delete temp;
        }else{
            x=x->next;
            z=z->next;
        }
    }
}


//DISTRUTTORE
template<class T>
Container<T>::~Container(){if(first) delete first;}


#endif
