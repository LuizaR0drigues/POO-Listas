#include <iostream>
#include <stdio.h>


int soma(double a, double b)
{
    int partint;
    partint = (int) a + b;
    return partint;
}
int main()
{
    double num1, num2;
    std:: cin >> num1;
    std:: cin >> num2;

    int soma1 = soma(num1, num2);
    std :: cout << soma1 << std::endl;

    return 0;
}