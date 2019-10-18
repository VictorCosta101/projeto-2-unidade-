#include "cutsphere.h"
// classe para corte em forma de esfera
CutSphere::CutSphere(int x,int y,int z, int r)
{
    //construtor
    x_=x; y_=y; z_=z; r_=r; // dados do argumento dos metodo CutSphere para as variaveis da classe
}

CutSphere::~CutSphere()
{
// destrutor da classe, liberação da memoria alocada
}

void CutSphere::draw(Sculptor &t)
{
    // o metodo draw cria um objeto sculptor t para usar a função cutspehere
    t.cutSphere(x_,y_,z_,r_);
}
