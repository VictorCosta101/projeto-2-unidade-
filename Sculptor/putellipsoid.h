#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H
#include "figurageometrica.h"

class PutEllipsoid: public FiguraGeometrica
{
protected:
     int _x0,_y0,_z0,_raiox,_raioy,_raioz;
     float _r, _g, _b, a;
public:
    PutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry,
                 int rz,float r,float g,float b,float alpha);
    ~PutEllipsoid();
     void draw(Sculptor &t);
};

#endif // PUTELLIPSOID_H
