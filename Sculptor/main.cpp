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
    Sculptor *s; // Obetejo sculptor

    vector<FiguraGeometrica*> v; // vetor para armazenar objetos criados pelo draw

    // variaveis para leitura do arquivo
    string texto, comando;
    ifstream arq;
    // Abrir o aqruivo com as infomações dos objetos
    arq.open("C:/Users/UFRNLAB/Desktop/projeto-2-unidade-/Sculptor/objeto.txt",ios::in);

    if(!arq.is_open()) //Verificação se o arquivo arq está aberto

    {

        exit(0);
    }

    stringstream ss;

    //leitura do arquivo arq
    while(arq.good())
    {
        getline(arq, texto);


            stringstream ss(texto);
            ss >> comando;
            cout << comando << endl;


            if(comando.compare("dim")==0)
            {
                // Recebe os dados de dimensão

                int x,y,z;
                ss >> x >> y >> z;

                s = new Sculptor(x,y,z);

            }

            else if (comando.compare("putvoxel")==0)
            {
                // recebe dados para cria  um voxel

                int x0,y0,z0; // coordenadas do voxel
                float r,g,b,alpha; // cores e transparencia

                ss >> x0 >> y0 >> z0 >> r >> g >> b >>alpha;

                v.push_back(new PutVoxel(x0,y0,z0,r,g,b,alpha));// adcionar voxel ao vetor v
            }

            else if(comando.compare("cutvoxel")==0)
            {
                // Elimina um determinado Voxel

                int x0, y0, z0; // coordenadas do voxel

                ss >> x0 >> y0 >>z0;

                v.push_back(new CutVoxel(x0,y0,z0)); // retira o voxel do vetor v
            }
            else if (comando.compare("putbox")==0) {
                // cria objetos retangulares
                int pos[6]; // coordenadas do retangulo
                float color[4];// cores e transparencia

                ss >> pos[0]>>pos[1]>>pos[2]>> pos[3]>>pos[4]>>pos[5];
                ss >> color[0] >> color[1] >> color[2] >> color[3];

                //adiciona o novo retangulo ao vetor v
                v.push_back(new PutBox(pos[0],pos[1],pos[2],pos[3],pos[4],pos[5],color[0],color[1],color[2],color[3]));

            }
            else if(comando.compare("cutbox")==0)
            {
                //apaga/corta objetos retangulares
                int pos[6]; // coordenadas do retangulo para corte

                ss >> pos[0]>>pos[1]>>pos[2]>> pos[3]>>pos[4]>>pos[5];

               //retira do vetor v o retangulo
               v.push_back(new CutBox(pos[0],pos[1],pos[2],pos[3],pos[4],pos[5]));
            }
            else if (comando.compare("putsphere")==0)
            {
               // Cria uma esfra
             int pos[4];// coordenadas de centro e raio da esfera
             float color[4];//cor e transparencia

             ss >> pos[0] >> pos[1] >> pos[2] >> pos[3];
             ss >> color[0] >> color[1] >> color[2] >> color[3];

             //adiciona a esfera ao vetor v
             v.push_back(new PutSphere(pos[0],pos[1],pos[2],pos[3],color[0],color[1],color[2],color[3]));
            }
            else if (comando.compare("cutsphere")==0)
            {
                // Retira a esfera ou  um corte em forma de esfera
                int pos[4];// coordenadas de centro e raio da esfera

                ss >> pos[0] >>pos[1] >> pos[2] >>pos[3];

                //retira a esfera cortada
                v.push_back(new CutSphere(pos[0],pos[1],pos[2],pos[3]));
            }
            else if (comando.compare("putellipsoid")==0)
            {
                //cria uma elipse
                int pos[6]; //coordenadas de centro e raio da elipse
                float color[4];//cores e transparencia da elipse

                ss >> pos[0] >> pos[1] >> pos[2] >> pos[3] >> pos[4] >> pos[5];
                ss >> color[0] >> color[1] >> color[2] >> color[3];

                // adiciona a elipse ao vetor v
                v.push_back(new PutEllipsoid(pos[0],pos[1],pos[2],pos[3],pos[4],pos[5],color[0],color[1],color[2],color[3]));

            }
            else if (comando.compare("cutellipsoid")==0)
            {
                // corta total ou parcialmente a elipse
                int pos[6];//coordenadas de centro e raios da elipse

                ss >> pos[0] >> pos[1] >> pos[2] >> pos[3] >> pos[4] >> pos[5];

                // retira a elipse cortada do vetor v
                v.push_back(new CutEllipsoid(pos[0],pos[1],pos[2],pos[3],pos[4],pos[5]));

            }


    }

    // Utilização do metod draw para adcionar todos os objetos criados ao vetor v
for(int i = 0; i < v.size(); i++)
{
    v[i]->draw(*s);
    }
s->writeOFF("figura");// Dados dos obejtos são adicionados ao arquivo OFF

s->~Sculptor(); //liberação de mememoria do sculptor
arq.close();//Fechar o arquivo
return 0;




}
