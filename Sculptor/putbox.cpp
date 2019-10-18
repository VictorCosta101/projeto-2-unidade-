#include "putbox.h"
//classe para desenhar uma 'cubo'

PutBox::PutBox(int x0, int x1, int y0, int y1, int z0, int z1, float r, float g, float b, float alpha){
   // recebe as variaveis do argumento do metodo PutBox para as variais da classe,
    _x0=x0; _x1=x1;_y0=y0;_y1=y1; _z0=z0;_z1=z1;
    _r=r; _g=g; _b=b;a=alpha;
}

// destrutor da classe
PutBox::~PutBox()
{

}
// cria um objeto sculptor t para usar as funções de atribuição de cor e criar um objeto com ela.
void PutBox::draw(Sculptor &t){
    t.putBox(_x0,_x1,_y0,_y1,_z0,_z1);
    t.setColor(_r,_g,_b,a);
}
