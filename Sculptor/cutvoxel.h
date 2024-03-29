#ifndef CUTVOXEL_H
#define CUTVOXEL_H

#include "figurageometrica.h"

class CutVoxel: public FiguraGeometrica
{
protected:
    int _x, _y, _z;
public:
    CutVoxel(int x, int y, int z);
    ~CutVoxel();

    void draw(Sculptor &t);
};

#endif // CUTVOXEL_H
