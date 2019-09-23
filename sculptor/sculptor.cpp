#include "sculptor.h"
#include <iostream>
#include <fstream>
#include <cmath>

using namespace  std;
Sculptor::Sculptor(int _nx, int _ny, int _nz)
{
    int nx=_nx, ny=_ny,nz=_nz;
    Voxel ***v = new Voxel**[_nx];
    for(int i = 0; i < _nz; ++i){
        v[i] = new Voxel*[_ny];
        for(int j = 0; j < _ny; ++j)
        {
            v[i][j] = new Voxel[_nz];
        }}
}

Sculptor::~Sculptor()
{
    for(int i = 0; i < nx; i++)
    {
        for(int j = 0; j < ny; j++)
        {
            delete [] v[i][j];

            delete[] v[i];
        }
    }
    delete[] v;
}

void Sculptor::setColor(float r, float g, float b, float alpha)
{
    this->r=r;
    this->g=g;
    this->b=b;
    this ->a=alpha;
}

void Sculptor::putVoxel(int x, int y, int z)
{
    v[x][y][z].isOn=true;
    v[x][y][z].r=r;
    v[x][y][z].g=r;
    v[x][y][z].b=r;
    v[x][y][z].a=a;

}

void Sculptor::cutVoxel(int x, int y, int z)
{
    v[x][y][z].isOn=false;
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1)
{


        for(int i = x0; i < x1; i++)
        {
            for(int j = y0; j < y1; j++)
            {
                for(int k = z0; k < z1; k++)
                {
                    putVoxel(i,j,k);
                }
            }
        }

}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    if(x0>=0&&y0>=0&&z0>=0&&x1<=nx&&y1<=ny&&z1<=nz)
    {
        for(int i = x0; i < x1; i++)
        {
            for(int j = y0; j < y1; j++)
            {
                for(int k = z0; k < z1; k++)
                {
                 cutVoxel(i,j,k);
                }
            }
        }
    }
}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    if(xcenter>=nx&&ycenter>=ny&&zcenter>=nz)
    {
        for(int i =0 ; i < nx; i++)
        {
            for(int j = 0; j < ny; j++)
            {
                for(int k = 0; k < nz; k++)
                {
                    int dist = (((xcenter-i)*(xcenter-i))+((ycenter-j)*(ycenter-j))+((zcenter-k)*(zcenter-k)));

                    if(dist<=(radius*radius))
                 {
                        v[i][j][k].isOn=true;
                        v[i][j][k].r=r;
                        v[i][j][k].g=r;
                        v[i][j][k].b=r;
                        v[i][j][k].a=a;
                 }
                }
            }
        }
    }
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius)
{/*
    for(int i =0 ; i < nx; i++)
    {
        for(int j = 0; j < ny; j++)
        {
            for(int k = 0; k < nz; k++)
            {
             if(distancia(xcenter,i,ycenter,j,zcenter,k,radius))
             {
                 cout<<"x = "<<i<<" y = "<<j<<" z = "<<k <<endl;
                 cutVoxel(i,j,k);
             }
            }
        }
    }*/}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    if(xcenter<=nx&&ycenter<=ny&&zcenter<=nz)
    {/*
        for(int i =0 ; i < nx; i++)
        {
            for(int j = 0; j < ny; j++)
            {
                for(int k = 0; k < nz; k++)
                {
                 if(distanciaElipse(xcenter, ycenter, zcenter, rx, ry, rz, i, j,k))
                 {
                     putVoxel(i,j,k);
                 }
                }
            }
        }
    }*/
}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx , int ry, int rz)
{if(xcenter<=nx&&ycenter<=ny&&zcenter<=nz)
    {/*
        for(int i =0 ; i < nx; i++)
        {
            for(int j = 0; j < ny; j++)
            {
                for(int k = 0; k < nz; k++)
                {
                 if(distanciaElipse(xcenter, ycenter, zcenter, rx, ry, rz, i, j,k))
                 {
                     cutVoxel(i,j,k);
                 }
                }
            }
        }
    }*/
}
}
void Sculptor::writeOFF(string filename)
{
    //Variavel para efetuar as funções de fluxos.
    ofstream objeto;
    //Contador para o número de vertices.
    int Nvertices=0;
    //Contador para o número de faces.
    int Nfaces=0;
    //Variavel auxiliar na execução e determinação de cada face para cada Voxel.
    int aux=0;
    //Abrindo arquivo.
    objeto.open("C:/Users/Victor/Desktop/projeto_2_sculptor/"+filename+".off");
    //Condição para determinar se o arquivo foi aberto.
    if(objeto.is_open()){
        cout << "arquivo OFF foi aberto\n";
    }
    else{
        cout << "arquivo OFF nao foi aberto\n";
        exit(1);
    }
    //Primeira linha do arquivo. Linha de reconhecimento.
    objeto<<"OFF"<<endl;
    //Contar a quantidade de vertices e faces. Obs.: isOn deve ser verdadeiro.
    for(int i=0;i<nx;i++){
        for(int j=0;j<ny;j++){
            for(int k=0;k<nz;k++){
                if(v[i][j][k].isOn){
                    Nvertices=Nvertices+8;
                    Nfaces=Nfaces+6;
                }
            }
        }
    }
    //Segunda linha do arquivo. Linha para mostra quantidade de vertices e faces.
    objeto<<Nvertices<<" "<<Nfaces<<" "<<0<<endl;
    //Dimensionamento de cada vertice em relação a cada Voxel com isOn true. Obs.: dimensão de cada Voxel 1.
    for(int i=0;i<nx;i++){
        for(int j=0;j<ny;j++){
            for(int k=0;k<nz;k++){
                if(v[i][j][k].isOn){
                        objeto<<i-0.5<<" "<<j+0.5<<" "<<k-0.5<<endl;
                        objeto<<i-0.5<<" "<<j-0.5<<" "<<k-0.5<<endl;
                        objeto<<i+0.5<<" "<<j-0.5<<" "<<k-0.5<<endl;
                        objeto<<i+0.5<<" "<<j+0.5<<" "<<k-0.5<<endl;
                        objeto<<i-0.5<<" "<<j+0.5<<" "<<k+0.5<<endl;
                        objeto<<i-0.5<<" "<<j-0.5<<" "<<k+0.5<<endl;
                        objeto<<i+0.5<<" "<<j-0.5<<" "<<k+0.5<<endl;
                        objeto<<i+0.5<<" "<<j+0.5<<" "<<k+0.5<<endl;
                }
            }
        }
    }
    //Dimensionar cada face de cada Voxel e atribuindo as cores correspondente.
    for(int i=0;i<nx;i++){
        for(int j=0;j<ny;j++){
            for(int k=0;k<nz;k++){
                if(v[i][j][k].isOn){
                    objeto<<4<<" "<<aux+0<<" "<<aux+3<<" "<<aux+2<<" "<<aux+1<<" "<<v[i][j][k].r<<" "
                    <<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                    objeto<<4<<" "<<aux+4<<" "<<aux+5<<" "<<aux+6<<" "<<aux+7<<" "<<v[i][j][k].r<<" "
                    <<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                    objeto<<4<<" "<<aux+0<<" "<<aux+1<<" "<<aux+5<<" "<<aux+4<<" "<<v[i][j][k].r<<" "
                    <<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                    objeto<<4<<" "<<aux+0<<" "<<aux+4<<" "<<aux+7<<" "<<aux+3<<" "<<v[i][j][k].r<<" "
                    <<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                    objeto<<4<<" "<<aux+3<<" "<<aux+7<<" "<<aux+6<<" "<<aux+2<<" "<<v[i][j][k].r<<" "
                    <<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                    objeto<<4<<" "<<aux+1<<" "<<aux+2<<" "<<aux+6<<" "<<aux+5<<" "<<v[i][j][k].r<<" "
                    <<v[i][j][k].g<<" "<<v[i][j][k].b<<" "<<v[i][j][k].a<<endl;
                    aux=aux+8;
                }
            }
        }
    }
    //Condição para apresentar o fim do arquivo.
    if(objeto.is_open()){
        cout << "arquivo OFF salvo"<<endl;
    }

}





