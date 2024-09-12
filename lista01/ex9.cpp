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
    //outra possibilidade:
    // std:: cin >> x1 >> y1 >> x2 >> y2;
    
    //calculando a dist euclidiana usando as funções sqrt(raiz quadrado)
    // e pow para elevar a potencia de 2 
    dist = sqrt(pow((x1 - x2), 2) + pow((y1 - y2),2));
    
    //usando a função setprecision(x) para definir a precisão de x casas decimais
    std :: cout  << std:: fixed << std :: setprecision(4) << dist << std::endl;
}