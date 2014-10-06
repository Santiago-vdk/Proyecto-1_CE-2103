#include "ListaPuntos.h"

ListaPuntos::ListaPuntos()
{
    _Tamanio=0;
    _Head= NULL;
    _Tail= NULL;
}

ListaPuntos::~ListaPuntos()
{
    for(int i=0;i<_Tamanio;i++){
        NodoPunto *tmp=_Head;
        _Head=_Head->getNext();
        delete tmp;
    }
}

NodoPunto *ListaPuntos::getHead()
{
    return _Head;
}

NodoPunto *ListaPuntos::getTail()
{
    return _Tail;
}

void ListaPuntos::insertarDato(CvPoint *pDato)
{
    NodoPunto *tmp = new NodoPunto();
    tmp->setDato(pDato);
    if(_Tamanio==0){
        _Head=tmp;
        _Tail=tmp;
        _Tamanio++;
    }
    else{
        _Tail->setNext(tmp);
        _Tail=tmp;
        _Tamanio++;
    }

}

CvPoint *ListaPuntos::getDatoEnPos(int i)
{
    NodoPunto *tmp = _Head;
    for(int a=0;a<i;a++){
       tmp=tmp->getNext();
    }
    return tmp->getDato();

}
