#include "cutellipsoid.h"

//classe para cortes em forma de elipse

CutEllipsoid::CutEllipsoid(int x, int y, int z, int rx, int ry , int rz)
{
    // dados do argumento do metodo CutEllipsoide para as variaveis da classe
    x_ = x; y_ = y; z_ = z; rx_ = rx; ry_ = ry; rz_ = rz;


}

CutEllipsoid::~CutEllipsoid()
{
    // destrutor da classe
}

void CutEllipsoid::draw(Sculptor &t)
{
   // metodo draw cria um objeto sculptor t par usar a função de desativar uma elipse
    t.cutEllipsoid(x_,y_,z_,rx_,ry_,rz_);
}
