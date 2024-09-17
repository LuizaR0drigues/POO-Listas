#include <stdio.h>
#include <iostream>

using namespace std;

int pow(int b, int e, int m)
{
   int aux, i=1, resto;
   aux = b;
   while (i < e)
   {
     aux *= b;
     i++;
     //cout << aux <<  endl;
   }
   
    resto =  aux % m;
    //cout << resto<< endl;
   return aux;
}

int main()
{   int num1, num2, num3;
    
    int test = pow(2, 10, 100);
}
