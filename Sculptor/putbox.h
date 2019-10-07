#ifndef PUTBOX_H
#define PUTBOX_H

#include "figurageometrica.h"

class PutBox: public FiguraGeometrica
{
protected:
    int x0_, x1_, y0_,  y1_, z0_, z1_;
    float r_, g_, b_, a;

public:
    PutBox(int x0, int x1, int y0, int y1, int z0,int z1, float r
           , float g, float b, float alpha);
     ~PutBox();

    void draw(Sculptor &t);
};

#endif // PUTBOX_H
