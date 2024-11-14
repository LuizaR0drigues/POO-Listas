#include <stdio.h>
#include <iostream>

//classe para numeros complexos
class C
{
private:
    double _real;
    double _imag;

public:
    C(double real = 0, double imag = 0) : _real(real), _imag(imag) {}

    C& operator=(const C& a)
    {//copia
        _real = a._real;
        _imag = a._imag;
        return *this;
    };

    C operator-()
    {//conjugar um numero complexo
        C aux;
        aux._imag = -_imag;
        aux._real = -_real;
        return aux;
    };

    friend C operator+(const C& a, const C& b)
    {//operação de adição
        C soma;
        soma._real = a._real + b._real;
        soma._imag = a._imag + b._imag;
        return soma;
    };

    friend C operator-(const C& a, const C& b)
    {//operação de substração
        C sub;
        sub._real = a._real - b._real;
        sub._imag = a._imag - b._imag;
        return sub;
    };

    friend C operator*(const C& a, const C& b)
    {//operaçao de multiplicação
        C mult;
        mult._real = (a._real * b._real) - (a._imag * b._imag);
        mult._imag = (a._real * b._imag) + (a._imag * b._real);
        return mult;
    };

    friend C operator/(const C& a, const C& b)
    { //operador para operação de adição de dois numeros complexos
        // z1 = a + bi e z2 = c+di
        //zi    (a + bi) (c-di)     (ac + bd) + (bc + ad)i
        //--- = ----------------- = ----------------------
        //z2    (c + di) (c-di)          (c² + d²)
        C mult;
        double denominador = b._real * b._real + b._imag * b._imag;
        mult._real = (a._real * b._real + a._imag * b._imag) / denominador;
        mult._imag = (a._imag * b._real - a._real * b._imag) / denominador;
        return mult;
    };

    double parte_real() const
    {//retorna somente a parte real
         return _real;
    };
    double parte_imag() const 
    { //retorna somente a parte imaginanaria
        return _imag; 
    };

    virtual std::ostream& imprimir(std::ostream& aux) const
    {
        aux << _real;
        if (_imag >= 0)
            aux << " + " << _imag << "i";
        else
            aux << " - " << -_imag << "i";
        return aux;
    };

    friend std::ostream& operator<<(std::ostream& aux, const C& c)
    {
        return c.imprimir(aux);
    };
};

//classe dos reais que herdam propriedades dos comlexos
class R : public C
{
public:
    R(double real = 0) : C(real, 0) {}

    std::ostream& imprimir(std::ostream& aux) const override
    {
        aux << parte_real();
        return aux;
    };
};

//classe dos racionais que herda os reais
class Q : public R
{
private:
    int _numerador;
    int _denominador;

public:
    Q(int num = 0, int deno = 1) : R((double)num / deno), _numerador(num), _denominador(deno) {}

    std::ostream& imprimir(std::ostream& aux) const override
    {
        aux << _numerador;
        if (_denominador != 1)
            aux << "/" << _denominador;
        return aux;
    };
};

//classe dos inteiros que herda os racionais
class Z : public Q
{
public:
    Z(int num = 0) : Q(num, 1) {}

    std::ostream& imprimir(std::ostream& aux) const override
    {
        //Imprime somente a arte Real de Z
        if(this->parte_real() >0){
            aux << "+" << parte_real();
        }
        else{
            aux << "-" << parte_real();
        }
        return aux;
    };
};

//classe dos naturais que herda os inteiros
class N : public Z
{
public:
    N(int real = 0) : Z(real) {}

    std::ostream& imprimir(std::ostream& os) const override
    {
        os << parte_real() ;
        return os;
    };
};

int main() {
const int numObjetos = 5;
C* objetos[numObjetos];
objetos[0] = new C(3.5, 2.1);
objetos[1] = new R(5.0);
objetos[2] = new Q(1, 3);
objetos[3] = new Z(10);
objetos[4] = new N(10);

for (int i = 0; i < numObjetos; ++i)
std::cout << *objetos[i] << std::endl;
for (int i = 0; i < numObjetos; ++i)
delete objetos[i];
return 0;
}