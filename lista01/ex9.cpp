#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <math.h>

int main()
{
    double x1, x2, y1, y2, dist;

    std :: cin >> x1;
    std :: cin >> y1;
    std :: cin >> x2;
    std :: cin >> y2;
    
    dist = sqrt(pow((x1 - x2), 2) + pow((y1 - y2),2));
    std :: cout  << std:: setprecision(5) << dist ;
}