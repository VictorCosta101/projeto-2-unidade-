#ifndef CUTBOX_H
#define CUTBOX_H

#include "figurageometrica.h"

class CutBox: public FiguraGeometrica
{
protected:
    int x0_, x1_, y0_,  y1_, z0_, z1_;
public:
    CutBox(int x0,int x1, int y0, int y1, int z0, int z1);

    ~CutBox();


    void draw(Sculptor &t);
};

#endif // CUTBOX_H
