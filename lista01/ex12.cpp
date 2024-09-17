#include <stdio.h>
#include <iostream>

using namespace std;

int pow(int b, int e, int m)
{
   int aux, i=0, resto;
   aux = b;
   while (i < e)
   {
    if (i == 0)
    {
        aux *= 1;
    }
    else{
     aux *= b;
    }
    i++;
     //cout << aux <<  endl;
   }
   
    resto =  aux % m;
    cout << resto<< endl;
   return resto;
}

int main()
{   int num1, num2, num3;
    cin >> num1 >> num2 >> num3;
    int test = pow(num1, num2, num3);
}
