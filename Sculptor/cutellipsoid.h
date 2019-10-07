#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H

#include "figurageometrica.h"

class CutEllipsoid: public FiguraGeometrica
{
protected:
int x_, y_, z_, rx_, ry_, rz_;
public:
    CutEllipsoid(int x, int y, int z, int rx, int ry , int rz);

   ~CutEllipsoid();


    void draw(Sculptor &t);


};

#endif // CUTELLIPSOID_H
