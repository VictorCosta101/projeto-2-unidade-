#include <iostream>
#include <sculptor.h>


using namespace std;

int main()
{
    int acao=0;
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


    v.writeOFF(arquivo);

    return 0;
}
