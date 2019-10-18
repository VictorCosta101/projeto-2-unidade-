#include "putvoxel.h"
//classe que ativa um voxel na sua coordenas x,y,z e o atribui uma cor
PutVoxel::PutVoxel(int x, int y, int z, float r, float g, float b, float alpha)
{
   _x=x; _y = y; _z = z; //dados do argumento do metodo PutVoxel para as avriaveis da classe

   float _r = r; _g = g; _b = b; a = alpha;

}

PutVoxel::~PutVoxel()
{

}

void PutVoxel:: draw(Sculptor &t){
    //O metodo draw cria um objeto sculptor e usa as funções da classe para atribuir cor a um voxel
    t.setColor(_r,_g,_b,a);
    t.putVoxel(_x,_y,_z);
}
