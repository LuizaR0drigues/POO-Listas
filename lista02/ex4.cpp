#include <stdio.h>
#include <iostream>
#include <random>
#include <math.h>
//c + bx + ax²
class Polinomio2
{
private:
    int _a, _b, _c;
public:
    Polinomio2(int aux_a =0, int aux_b =0, int aux_c =0){
        if(aux_a ==0)
        {
            aux_a = 1;
            aux_b = rand() %100 ;
            aux_c = rand() % 100;
        }
        else{
            _a = aux_a;
            _b = aux_b;
            _c = aux_c;

        }
    };

    double *raizes()
    {
        double *v = new double[3];
        //calculo do discrimante
        double delta = (_b * _b) - 4*_a * _c;

        if( delta  > 0)
        {
            
            v[0] = 2.0;
            v[1] = (-_b - delta) / 2 * _a;
            v[2] = (-_b + delta) / 2 * _a;

        }
        else if( delta == 0)
        {
            v[0] = 1.0;
            v[1] = (-_b + delta) / 2 * _a;
            v[2] = v[1];


        }
        else{
           v[0] = 0.0;

        }
        return v;
    };

    double operator()(double x)
    {
        double value = (x*x)*_a + _b *x + _c;
        return value;
    };
};


int main()
{
    double *v;
    Polinomio2 p1(1, 1, 1);
    v = p1.raizes(); for(int i=0; i<=v[0]; i++) std::cout << v[i] << " " ;
    std::cout << '\n' << p1(2) << '\n' ;
    Polinomio2 p2(1, 2, 1);
    v = p2.raizes(); for(int i=0; i<=v[0]; i++) std::cout << v[i] << " " ;
    std::cout << '\n' << p2(2) << '\n' ;
    Polinomio2 p3(1, -3, 2);
    v = p3.raizes(); for(int i=0; i<=v[0]; i++) std::cout << v[i] << " " ;
    std::cout << '\n' << p3(2) << '\n' ;

    return 0;
}



