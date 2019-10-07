#include "cutsphere.h"

CutSphere::CutSphere(int x,int y,int z, int r)
{
    x_=x; y_=y; z_=z; r_=r;
}

CutSphere::~CutSphere()
{

}

void CutSphere::draw(Sculptor &t)
{
    t.cutSphere(x_,y_,z_,r_);
}
