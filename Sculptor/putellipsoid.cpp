#include "putellipsoid.h"

PutEllipsoid::PutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz, float r, float g, float b, float alpha){
     _x0=xcenter;_y0=ycenter;_z0=zcenter;
     _raiox=rx;_raioy=ry;_raioz=rz;
     _r=r;_g=g;_b=b;a=alpha;
}

PutEllipsoid::~PutEllipsoid()
{

}

void PutEllipsoid::draw(Sculptor &t){
    t.putEllipsoid(_x0,_y0,_z0,_raiox,_raioy,_raioz);
    t.setColor(_r,_g,_b,a);
}
