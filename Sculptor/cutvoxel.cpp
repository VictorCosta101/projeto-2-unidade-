#include "cutvoxel.h"

CutVoxel::CutVoxel(int x, int y, int z)
{
    _x=x; _y=y; _z=z;
}

CutVoxel::~CutVoxel(){

}

void CutVoxel::draw(Sculptor &t)
{
    t.cutVoxel(_x,_y,_z);
}
