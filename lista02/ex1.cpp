#include <iostream>
#include <stdio.h>

class Televisao
{ //atributos privados
    bool _ligada;
    int _canal;

public:
    Televisao(bool ligada = false, int canal = 1){//construtor da classe
         _ligada = ligada;
         _canal = canal;
    }
    void liga(){  //altera o estado para True
          _ligada = true;

    }             
    void desliga()  //altera o estado para False
    {
    _ligada = false;
    }
    void canal_cima()//aumenta o canal em 1 se for true
    {
        if(_ligada == true)
        {
            _canal +=1;
        }
    }
    void canal_baixo() //descrece o canal em 1 se for true
    {
        if(_ligada == true)
        {
            _canal -=1;
        }   
    }
    friend std::ostream& operator<<(std::ostream &out, const Televisao &tv)//declaração da classe amg
    {

        if(tv._ligada)
        {
            out << "(ligada, "<<  tv._canal << ")" ;
        }
        else
        {
            out << "(desligada, "<<  tv._canal << ")" ;
        }
        return out;
    }
};

int main()
{
    Televisao tv;

    std:: cout << tv;
    tv.canal_cima();
    std:: cout << tv;
    tv.canal_baixo();
    std:: cout << tv;
    std:: cout << tv;
    tv.liga();
    std:: cout << tv;
    tv.canal_cima();
    std:: cout << tv;
    tv.canal_baixo();
    std:: cout << tv;
    tv.desliga();
    std:: cout << tv;
    tv.canal_cima();
    std:: cout << tv;
    return 0;
}