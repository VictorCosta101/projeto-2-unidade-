#ifndef CUTSPHERE_H
#define CUTSPHERE_H

#include "figurageometrica.h"

class CutSphere: public FiguraGeometrica
{

protected:
int x_, y_, z_, r_;

public:
    CutSphere(int x,int y,int z,int r);

    ~CutSphere();

    void draw(Sculptor &t);
};

#endif // CUTSPHERE_H
