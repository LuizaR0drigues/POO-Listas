#include <stdio.h>
#include <iostream>

  static long long int calculo_mdc(long long int a, long long int b ){
        long long int resto = 0;
        //printf(" MDC a %lld b %lld \n",a, b);
        if( a <= 0)
        {
            return b;
        }
        if(b <= 0)
        {
            return a;
        }
        if(a == b)
        {
            //quando ambos forem iguais, o mdc será 
            return a;
        }
        while(b != 0)
        {
                resto = a % b;
                a = b;
                b = resto;
        }
     //printf("Resto2 %lld \n", resto);
       return a;
    }

class Fracao
{
private:
    long long int _numerador; //atributos privados
    long long int _denominador;

    //funções responsáveis por reduzir a fração
    void reduz(){
        long long int divisor = calculo_mdc(_numerador, _denominador);
        _numerador /= divisor;
        _denominador /= divisor;  
    };

  
public:
    Fracao(long long int numerador = 0, long long int denominador = 1){//definindo os valores padroes
        _numerador = numerador;
        _denominador = denominador;
        reduz();
    };
   Fracao(double x, double eps ){ //sobrecarga de construtores
        _numerador = x/eps;
        _denominador = 1/eps;

        this->reduz();
    };

    friend Fracao operator+(const Fracao& a, const Fracao& b)
    {
        long long int aux_num, aux_den;
        aux_num = (a._numerador * b._denominador) + (a._denominador * b._numerador);
        aux_den = a._denominador * b._denominador;
        return Fracao(aux_num, aux_den);

    };
    friend Fracao operator-(const Fracao& a, const Fracao& b)
    {
        long long int aux_num, aux_den;
        aux_num = (a._numerador * b._denominador) - (a._denominador * b._numerador);
        aux_den = a._denominador * b._denominador;
        return Fracao(aux_num, aux_den);
    };
    friend Fracao operator*(const Fracao& a, const Fracao& b)
    {
        long long int aux_num, aux_den;
        aux_num = (a._numerador * b._numerador) ;
        aux_den = a._denominador * b._denominador;
        return Fracao(aux_num, aux_den);
    };
    friend Fracao operator/(const Fracao& a, const Fracao& b)
    {
        long long int aux_num, aux_den;
        aux_num = a._numerador * b._denominador;
        aux_den = a._denominador * b._numerador;
        return Fracao(aux_num, aux_den);
    };
    operator double()
    {
        return static_cast<double>(_numerador) / _denominador;
    };
    friend std::ostream& operator<<(std::ostream &os, const Fracao &f) {
        os << f._numerador << '/' << f._denominador;
        return os;
    }
    
};

int main(){
Fracao f;
std::cout << f << " " << double(f) << '\n' ;
f = f+Fracao(1LL, 2LL);
std::cout << f << " " << double(f) << '\n' ;
f = f+Fracao(1LL,2LL);
std::cout << f << " " << double(f) << '\n' ;
f = f*Fracao(3LL,2LL);
std::cout << f << " " << double(f) << '\n' ;
f = f/Fracao(3LL,4LL);
std::cout << f << " " << double(f) << '\n' ;
f = f-Fracao(1LL,6LL);
std::cout << f << " " << double(f) << '\n' ;
f = f*Fracao(0LL, 99999999999999LL);
std::cout << f << " " << double(f) << '\n' ;

    return 0;
}