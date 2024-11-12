#include <stdio.h>
#include <iostream>

  static long long int calculo_mdc(long long int a, long long int b ){
        long long int resto = 0;
        //printf(" MDC a %lld b %lld \n",a, b);

        if( a == 0)
        {
            return b;
        }
         if(b == 0)
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
        //printf("Resto  %lld \n", resto);
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

        //verificando se o dennominador é negativo  
         if(_denominador < 0)
        {
            _numerador = _numerador *-1;
            _denominador = _denominador * -1;
        }
        else{
        _numerador = _numerador;
        _denominador = _denominador;
        }
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
        if(f._numerador % f._denominador == 0)
        {
            os << f._numerador / f._denominador;
        }
        else
        {
            os << f._numerador << '/' << f._denominador;
        }
        return os;
    }
    
};

int main(){
Fracao f(-5LL, 13LL);
    f = f * Fracao(-34LL, 48LL);
    f = f / Fracao(58LL, 56LL);
    f = f * Fracao(-44LL, 85LL);
    std::cout << f << " " << double(f) << std::endl;
    f = f * Fracao(1LL, 44LL);
    f = f + Fracao(-58LL, 95LL);
    f = f / Fracao(1LL, 49LL);
    f = f + Fracao(-75LL, 8LL);
    std::cout << f << " " << double(f) << std::endl;
    f = f + Fracao(1LL, 72LL);
    f = f / Fracao(98LL, 2LL);
    std::cout << f << " " << double(f) << std::endl;
    f = f / Fracao(58LL, 28LL);
    f = f + Fracao(-77LL, 77LL);
    f = f / Fracao(-46LL, 99LL);
    f = f - Fracao(-92LL, 86LL);
    std::cout << f << " " << double(f) << std::endl;
    f = f + Fracao(28LL, 42LL);
    f = f * Fracao(-18LL, 32LL);
    std::cout << f << " " << double(f) << std::endl;
    f = f / Fracao(70LL, 92LL);
    f = f + Fracao(-83LL, 22LL);
    f = f / Fracao(86LL, 100LL);
    f = f + Fracao(34LL, 83LL);
    f = f - Fracao(21LL, 79LL);

    return 0;
}