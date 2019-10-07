#include "cutbox.h"


CutBox::CutBox(int x0,int x1, int y0, int y1, int z0, int z1)
{
    x0_ = x0; x1_ = x1; y0_ = y0; y1_ = y1; z1_ = z1;
}
CutBox::~CutBox()
{}

void CutBox::draw(Sculptor &t)
{
    t.cutBox(x0_,x1_,y0_,y1_,z0_,z1_);
}
