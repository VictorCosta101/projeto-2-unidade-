#include "putvoxel.h"

PutVoxel::PutVoxel(int x, int y, int z, float r, float g, float b, float alpha)
{
   _x=x; _y = y; _z = z;

   float _r = r; _g = g; _b = b; a = alpha;

}

PutVoxel::~PutVoxel()
{

}

void PutVoxel:: draw(Sculptor &t){
    t.setColor(_r,_g,_b,a);
    t.putVoxel(_x,_y,_z);
}
