#include "putsphere.h"

// classe para criar uma espera

PutSphere::PutSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float alpha)
{
    // passar dados do argumento do metodo PutSphere para as variaveis da classe

    _x0=xcenter;_y0=ycenter;_z0=zcenter;_raio=radius;
    _r=r;_g=g;_b=b;a=alpha;
}

PutSphere::~PutSphere()
{
// destrutor da classe, liberação da memoria alocada
}

void PutSphere::draw(Sculptor &t)
{
    // criação de um objeto scultor t para uasr as funções de cor(setcolor) e criação da esfera(putsphere)
    t.putSphere(_x0,_y0,_z0,_raio);
    t.setColor(_r,_g,_b,a);
}
