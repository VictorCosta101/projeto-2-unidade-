#include "putsphere.h"



PutSphere::PutSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float alpha)
{
    _x0=xcenter;_y0=ycenter;_z0=zcenter;_raio=radius;
    _r=r;_g=g;_b=b;a=alpha;
}

PutSphere::~PutSphere()
{

}

void PutSphere::draw(Sculptor &t)
{
    t.putSphere(_x0,_y0,_z0,_raio);
    t.setColor(_r,_g,_b,a);
}
