#include <stdio.h>
#include <iostream>

using namespace std;

int pow(int b, int e, int m)
{
   int aux, i=0, resto;
   aux = b;
   while (i < e)
   {
    if (i == 0) //caso do numero ser elevado a 0
    {
        aux *= 1;
    }
    else{ //utilizada a estrageia de somatoria de (b*b...) por n vezes
     aux *= b;
    }
    i++;
   }
   
    resto =  aux % m;
   return resto;
}

int main()
{   int num1, num2, num3;
    cin >> num1 >> num2 >> num3;
    int test = pow(num1, num2, num3);
    cout << test << endl;

    return 0;
}
