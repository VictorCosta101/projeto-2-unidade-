#include <sculptor.h>
#include <cmath>
#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
   string arquivo = "objeto1";

   Sculptor espaco(100,100,100);

   espaco.setColor(1,0,0,1);

   espaco.putSphere(49,49,49,20);

   espaco.writeOFF(arquivo);


    return 0;
}
