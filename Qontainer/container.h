#ifndef CONTAINER
#define CONTAINER

template <class T>

class Container {
private:
    T info;
    Container* prev;
    Container* next;

public:
    //COSTRUTTORI
    Container(T =0,Container* =nullptr, Container* =nullptr);

    //METODI GENERALI
    int size()const;
    bool empty()const;

    //METODI DI INSERIMENTO
    void push_front(T* x);
    void insert(T x);

    //METODI DI RICERCA
    Container<T> find(T x); //restituisce un container con tutti gli oggetti di tipo T contenuti nella container di invocazione
    bool find(T x)const; //restituisce true se l'oggetto e' presente nella lista

    //METODI DI CANCELLAZIONE
    T pop_front();
    void erase(T x); // cancella dalla lista di invocazione tutti gli oggetti di tipo T

    //DISTRUTTORE
    ~Container();

//TEMPLATE DI FUNZIONE

template<class T1,class T2>
    Container<T1> find(T1 classe,T2 campo,T2 valore); //funzione che data una classe T1 restituisce un container con tutti i T1 con campo T2 uguale al valore T2 esistenti nella lista di partenza

template<class T1,class T2>
    void erase(T1 x,T2 campo,T2 valore);//cancella dalla lista di invocazione tutti gli oggetti di tipo T1 per valore del campo T2
};


#endif // CONTAINER

