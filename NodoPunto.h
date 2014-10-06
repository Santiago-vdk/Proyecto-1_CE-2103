#ifndef NODOPUNTO_H
#define NODOPUNTO_H
#include <opencv/cv.h>

class NodoPunto
{
public:
    NodoPunto();
    CvPoint *getDato();
    NodoPunto *getNext();
    NodoPunto *getPrev();
    void setNext(NodoPunto *pNext);
    void setPrev(NodoPunto *pPrev);
    void setDato(CvPoint *pDato);

private:
    CvPoint *_dato;
    NodoPunto *_next=NULL;
    NodoPunto *_prev=NULL;
};


#endif // NODOPUNTO_H
