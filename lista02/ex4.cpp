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
           _a = 1;
            _b = rand() %100 ;
            _c = rand() % 100;
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
            v[1] = (-_b - sqrt( delta)) / (2 * _a);
            v[2] = (-_b +  sqrt( delta)) / (2 * _a);

        }
        else if( delta == 0)
        {
            v[0] = 1.0;
            v[1] = (-_b ) / (2 * _a);
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
    Polinomio2 p(1152, 2690, 128);
    double *v = p.raizes();
    for(int i=0; i<=v[0]; i++) std::cout << v[i] << " " ;
    std::cout << p(2) << std::endl;

    return 0;
}



