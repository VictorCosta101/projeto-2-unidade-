#ifndef PUTBOX_H
#define PUTBOX_H

#include "figurageometrica.h"
class PutBox:public FiguraGeometrica{

protected:
    int _x0,_x1,_y0,_y1,_z0,_z1;
    float _r, _g, _b, a;
public:
    PutBox(int x0,int x1, int y0,int y1, int z0,int z1, float r, float g, float b, float alpha);
    ~PutBox();
    void draw(Sculptor &t);
};


#endif // PUTBOX_H
