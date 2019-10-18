#include "putellipsoid.h"

//classe  para cria objetos em forma de elipse

PutEllipsoid::PutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz, float r, float g, float b, float alpha){
    // construtor da classe
    // dados do argumento do metodo PutEllipsoide para as variaveis da classe
    _x0=xcenter;_y0=ycenter;_z0=zcenter;
     _raiox=rx;_raioy=ry;_raioz=rz;
     _r=r;_g=g;_b=b;a=alpha;
}

PutEllipsoid::~PutEllipsoid()
{
// destrutor da classe, liberação da memoria alocada
}

void PutEllipsoid::draw(Sculptor &t){
    // metodo draw cria um objeto sculptor t par usar as função de atribuição de cor(setcolor) e criar uma
    // elipse(putellipsoid)
    t.putEllipsoid(_x0,_y0,_z0,_raiox,_raioy,_raioz);
    t.setColor(_r,_g,_b,a);
}
