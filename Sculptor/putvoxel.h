#ifndef PUTVOXEL_H
#define PUTVOXEL_H

#include "figurageometrica.h"

class putVoxel : public FiguraGeometrica
{
protected:
    int _x,_y,_z;
    float _r, _g, _b, a;
public:
    putVoxel(int x, int y, int z, float r, float g, float b, float alpha);
   ~putVoxel();

    void draw(Sculptor &t);
};

#endif // PUTVOXEL_H
