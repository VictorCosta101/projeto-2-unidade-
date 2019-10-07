#ifndef PUTSPHERE_H
#define PUTSPHERE_H
#include "figurageometrica.h"


class PutSphere: public FiguraGeometrica
{
protected:
    int _x0,_y0,_z0,_raio;
    float _r, _g, _b, a;
public:
    PutSphere(int xcenter, int ycenter, int zcenter, int radius
              ,float r, float g,float b,float alpha);
    ~PutSphere();
     void draw(Sculptor &t);
};

#endif // PUTSPHERE_H
