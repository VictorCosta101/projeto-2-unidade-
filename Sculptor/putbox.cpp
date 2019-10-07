#include "putbox.h"

PutBox::PutBox(int x0, int x1, int y0, int y1, int z0,int z1, float r
               , float g, float b, float alpha)
{
 x0_ = x0; x1_ = x1;y0_ = y0;  y1_ = y1; z0_ = z0;z1_ = z1;

 r_=r ; g_ = g; b_ = b; a= alpha;


}

PutBox::~PutBox()
{}

void PutBox::draw(Sculptor &t)

{
    t.setColor(r_,g_,b_,a);
    t.putBox(x0_,x1_,y0_,y1_,z0_,z1_);
}
