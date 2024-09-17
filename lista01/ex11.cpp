#include <string>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <sstream>

using namespace std;

string raizes(double a, double b, double c) //ax² + bx + c = 0
{

    double discri, raiz1, raiz2, aux;
     aux = pow(b, 2) - (4*a*c);
 
     discri = sqrt(discri);
     
     if ( discri > 0)
     {
        raiz1 = (- b + discri) / (2*a);
        raiz2 = (- b - discri) / (2*a);

        if ( raiz1 > raiz2)
        {
            printf("%.1f e %.1f\n", raiz2, raiz1);
        }
        else{
            printf("%.1f e %.1f\n", raiz1, raiz2);
        }
        
     }
     else if( discri < 0)
     {
        printf("Nenhuma\n");
     }
     else{
        raiz1 = (- b + discri) / (2*a);
        printf("%.f\n", raiz1);

     }
     
     return "0k";
}

int main()
{
    int num1, num2, num3;
    cin >> num1 >> num2 >> num3;
    string test = raizes(num1, num2, num3);
    return 0;
}