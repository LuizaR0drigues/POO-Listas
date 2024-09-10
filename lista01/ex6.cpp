#include <iostream>
#include <stdio.h>


int soma(double a, double b)
{
    int partint;

    partint = (int(a) +  int(b));
    //std:: cout << partint;
    return partint;
}
int main()
{
    double num1, num2;
    std:: cin >> num1;
    std:: cin >> num2;
    std :: cout << soma(num1, num2) << std:: endl;

    return 0;
}