#include <sculptor.h>
#include <iostream>
#include <cmath>


Sculptor::Sculptor(int _nx, int _ny, int _nz)
{
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
    a = alpha;
}

void Sculptor::putVoxel(int x, int y, int z)
{
    v[x][y][z].r=r;
    v[x][y][z].g=r;
    v[x][y][z].b=r;
    v[x][y][z].isOn=true;

}

void Sculptor::cutVoxel(int x, int y, int z)
{
    v[x][y][z].isOn=false;
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    if(x0>=0&&y0>=0&&z0>=0&&x1<=nx&&y1<=ny&&z1<=nz)
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
    if(xcenter<=nx&&ycenter<=ny&&zcenter<=nz)
    {
        for(int i =0 ; i < nx; i++)
        {
            for(int j = 0; j < ny; j++)
            {
                for(int k = 0; k < nz; k++)
                {
                 if(distancia(xcenter,i,ycenter,j,zcenter,k,radius))
                 {
                     putVoxel(i,j,k);
                 }
                }
            }
        }
    }
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    for(int i =0 ; i < nx; i++)
    {
        for(int j = 0; j < ny; j++)
        {
            for(int k = 0; k < nz; k++)
            {
             if(distancia(xcenter,i,ycenter,j,zcenter,k,radius))
             {
                 cutVoxel(i,j,k);
             }
            }
        }
    }}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{

}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{

}

void Sculptor::writeOFF(char *filename)
{

}

bool Sculptor::distancia(int x0, int x1, int y0, int y1, int z0, int z1, int radius)
{
    float dist;
    dist = pow((pow(x1-x0,2)+pow(y1-y0,2)+pow(z1-z0,2)),0.5);
    if(dist<=radius)
    {
        return true;
    }
    else return false;
}

