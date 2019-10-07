#include "cutellipsoid.h"

CutEllipsoid::CutEllipsoid(int x, int y, int z, int rx, int ry , int rz)
{
    x_ = x; y_ = y; z_ = z; rx_ = rx; ry_ = ry; rz_ = rz;


}

CutEllipsoid::~CutEllipsoid()
{}

void CutEllipsoid::draw(Sculptor &t)
{
    t.cutEllipsoid(x_,y_,z_,rx_,ry_,rz_);
}
