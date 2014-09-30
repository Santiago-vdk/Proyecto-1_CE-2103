#ifndef PIXEL_H
#define PIXEL_H

#include <cstdlib>

using namespace std;

class pixel
{
public:
    pixel(int pRed, int pGreen, int pBlue);
    bool esBlanco();
    int getRed();
    int getGreen();
    int getBlue();

    void setRed(int red);
    void setGreen(int green);
    void setBlue(int blue);




private:
    int _Red;
    int _Green;
    int _Blue;




};
#endif // PIXEL_H
