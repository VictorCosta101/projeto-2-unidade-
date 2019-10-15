#include <iostream>
#include <sculptor.h>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "cutbox.h"
#include "putvoxel.h"
#include "cutvoxel.h"
#include "putbox.h"
#include "cutbox.h"
#include "putsphere.h"
#include "cutsphere.h"
#include "putellipsoid.h"
#include "cutellipsoid.h"

using namespace std;

int main()
{
    Sculptor *s;

    vector<FiguraGeometrica*> v;

    string texto, comando;
    ifstream arq;

    arq.open("C:/Users/UFRNLAB/Desktop/projeto 2/projeto-2-unidade-/Sculptor/objeto.txt",ios::in);

    stringstream ss;


    while(1)
    {
        getline(arq, texto);

        if(arq.good())
        {
            stringstream ss(texto);
            ss >> comando;
            cout << comando << endl;

            if(comando.compare("dim")==0)
            {
                int x,y,z;
                ss >> x >> y >> z;

                s = new Sculptor(x,y,z);

            }

            else if (comando.compare("putvoxel")==0)
            {
                int x0,y0,z0;
                float r,g,b,alpha;
                ss >> x0 >> y0 >> z0 >> r >> g >> b >>alpha;
                v.push_back(new PutVoxel(x0,y0,z0,r,g,b,alpha));
            }

            else if(comando.compare("cutvoxe")==0)
            {
                int x0, y0, z0;

                ss >> x0 >> y0 >>z0;

                v.push_back(new CutVoxel(x0,y0,z0));
            }
            else if (comando.compare("putbox")==0) {
                int pos[6];
                float color[4];

                ss >> pos[0]>>pos[1]>>pos[2]>> pos[3]>>pos[4]>>pos[5];
                ss >> color[0] >> color[1] >> color[2] >> color[3];

                v.push_back(new PutBox(pos[0],pos[1],pos[2],pos[3],pos[4],pos[5],color[0],color[1],color[2],color[3]));

            }
            else if(comando.compare("cutbox")==0)
            {
                int pos[6];

                ss >> pos[0]>>pos[1]>>pos[2]>> pos[3]>>pos[4]>>pos[5];

                v.push_back(new CutBox(pos[0],pos[1],pos[2],pos[3],pos[4],pos[5]));
            }
            else if (comando.compare("putsphere")==0)
            {
             int pos[4];
             float color[4];

             ss >> pos[0] >> pos[1] >> pos[2] >> pos[3];
             ss >> color[0] >> color[1] >> color[2] >> color[3];
             v.push_back(new PutSphere(pos[0],pos[1],pos[2],pos[3],color[0],color[1],color[2],color[3]));
            }
            else if (comando.compare("cutsphere")==0)
            {
                int pos[4];

                ss >> pos[0] >>pos[1] >> pos[2] >>pos[3];
                v.push_back(new CutSphere(pos[0],pos[1],pos[2],pos[3]));
            }
            else if (comando.compare("putellipsoid")==0)
            {
                int pos[6];
                float color[4];
                ss >> pos[0] >> pos[1] >> pos[2] >> pos[3] >> pos[4] >> pos[5];
                ss >> color[0] >> color[1] >> color[2] >> color[3];
                v.push_back(new PutEllipsoid(pos[0],pos[1],pos[2],pos[3],pos[4],pos[5],color[0],color[1],color[2],color[3]));

            }
            else if (comando.compare("cutellipsoid")==0)
            {
                int pos[6];

                ss >> pos[0] >> pos[1] >> pos[2] >> pos[3] >> pos[4] >> pos[5];
                v.push_back(new CutEllipsoid(pos[0],pos[1],pos[2],pos[3],pos[4],pos[5]));

            }
        }
    }

for(int i = 0; i < v.size(); i++)
{
    v[i]->draw(*s);
    }
s->writeOFF("objeto1");

s->~Sculptor();

return 0;




}
