#include "pixel.h"
#include <QDebug>

pixel::pixel(int pRed, int pGreen, int pBlue)
{
    _Red = pRed;
    _Green = pGreen;
    _Blue = pBlue;

}



bool pixel::esBlanco()
{
    if (_Red > 245 && _Red <= 255){
        if (_Green > 245 && _Green <=255){
            if (_Blue > 245 && _Blue <= 255){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}


int pixel::getRed()
{
    return _Red;
}

int pixel::getBlue()
{
    return _Blue;
}

int pixel::getGreen()
{
    return _Green;
}




void pixel::setRed(int red)
{
    _Red=red;
}
void pixel::setGreen(int green)
{
    _Green=green;
}
void pixel::setBlue(int blue)
{
    _Red=blue;
}


