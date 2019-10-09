#include <iostream>
#include <sculptor.h>
#include <fstream>
#include <cstring>

using namespace std;

int main()
{

    char  a[30], b[12];




    ifstream arq;

    arq.open("C:/Users/UFRNLAB/Desktop/projeto 2/projeto-2-unidade-/Sculptor/objeto.txt",ios::in);

if(arq.is_open()){

    cout<<"ok"<<endl;
    arq.getline(a,sizeof(a));
}

for(int i = 0 ; i < sizeof(a) ; i++)
{   if(a[i] != ' '){
         b[i]=a[i];
    }
    else
    {
        break;
    }
}

arq >> a;
cout << a << endl;
cout << " b :" <<endl;
cout << b <<endl;

    /* int acao=0;
    string arquivo = "objeto1";

    Sculptor v(20,20,20);

    v.setColor(1,0,0,1);

    cout<< "putBox --------- [1]"<<endl;
    cout<< "cutBox --------- [2]"<<endl;
    cout<< "putSphere ------ [3]"<<endl;
    cout<< "cutSphere ------ [4]"<<endl;
    cout<< "putEllipsoid --- [5]"<<endl;
    cout<< "cutEllipsoid --- [6]"<<endl;
    cout<< "Todos ---------- [7]"<<endl;
    cout<<"Acao: ";
    cin>>acao;
    switch (acao) {
        case 1:
            v.putBox(2,5,2,5,2,5);
            break;
        case 2:
            v.cutBox(2,5,2,5,2,5);
            break;
        case 3:
            v.putSphere(9,9,9,6);
            break;
        case 4:
            v.cutSphere(9,9,9,6);
            break;
        case 5:
            v.putEllipsoid(9,9,9,10,6,3);
           break;


        case 6:
            v.cutEllipsoid(9,9,9,10,6,3);
            break;
        case 7:
            v.putBox(2,5,2,5,2,5);
            v.cutBox(2,5,2,5,2,5);
            v.putSphere(9,9,9,6);
            v.cutSphere(9,9,9,6);
            v.putEllipsoid(9,9,9,10,6,3);
            v.cutEllipsoid(9,9,9,10,6,3);
    }


    v.writeOFF(arquivo);*/

    return 0;
}
