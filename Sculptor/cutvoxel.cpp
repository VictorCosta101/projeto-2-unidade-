#include "cutvoxel.h"
//recebe coordenadas de um Voxel para ser desativado

CutVoxel::CutVoxel(int x, int y, int z)
{
    _x=x; _y=y; _z=z;// variaveis do metodo para as variavies da classe
}

CutVoxel::~CutVoxel(){
//Destrutor, libera a memoria alocada
}

void CutVoxel::draw(Sculptor &t)
{
    //cria um obejto sculpto t para chamar a função de desligar um voxel
    t.cutVoxel(_x,_y,_z);
}
