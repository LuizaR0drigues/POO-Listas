#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string>

class BigInt
{
private:
    int* _partes; //vetor com as noves partes do numero BigInt
    int _npartes; //numero de elementos presentes no vetor
    bool _positivo; //representa se o numero é positivo(true), negativo(false)
public:
    BigInt(std::string numero)//recebe o numero em string e quebrada em parte para por no vetor int
    {
        _partes = new int[_npartes];
        for(int i=0; i<_npartes; i++)
        {
            _partes[i] = numero[i];
        }
    };
    BigInt(int num, bool eh_num = true){
        if(eh_num) //conversãao de int para bigint
        {
            std::string aux = std::to_string(num);
            int tam_num = aux.size();
            for(int i=0; i< tam_num; i++)
            {
                _partes[i] = aux[i] - '0';
            }
        }
        else{
            _partes = new int[num];
            for(int i=0; i<num; i++){
                _partes[i] = 0;
            }
        }
    };
    
    BigInt() //cria um vetor zerado
    {
         _npartes = 1;
         _partes = new int[_npartes];
         _partes[_npartes] = 0;
    };
    BigInt(BigInt&& b) //passa a posse de b para a
    {
        //tranferindo os dados
         for(int i=0; i<_npartes; i++){
                _partes[i] = b._partes[i];
            }
        _npartes = b._npartes;
        _positivo = b._positivo;

        //zerando o antigo objeto
         b._partes = nullptr;
         b._npartes = 0;
         b._positivo = true;

    };
    ~BigInt(){
        delete[] _partes; //desaloca memoria
    };
    bool Positivo()
    {
        if(_positivo){
            return true;
        }
        else{
            return false;
        }
    };

    BigInt& operator=(const BigInt& b) //Os operadores de atribuição armazenam um valor no objeto especificado pelo operando esquerdo. = é do tipo simples
    {

        //tranferindo os dados
        //libera memoria e dpeois tranfere
        delete[] _partes;

        _npartes = b._npartes;
        _positivo = b._positivo;

        _partes = new int(_npartes);
        for(int i=0; i<_npartes; i++){
                _partes[i] = b._partes[i];
        }

        return *this;
    };

    BigInt abs() // Retorna um BigInt representando o modulo do numero
    {
        
            BigInt aux; //cria uma copia em modulo
            aux._npartes = _npartes;
            aux._partes = new int(aux._npartes);
            for(int i=0; i<aux._npartes; i++){
                aux._partes[i] = _partes[i];
            }
            aux._positivo = true;
            return aux;
        
    };

    friend bool operator==(const BigInt& a, const BigInt& b){
        //Deve retornar true se a = b e 
        //false caso contrario: a > b
        int i, aux;
        i = a._npartes -1;
        while(i >= 0) //percorre o vetor enquanto for igual, se todos os elementos forem igauis retorna true
            {
                if( a._partes[i] == b._partes[i]){
                   continue;
                }
            else{
                return false;
            }
            i--;
        }
            return true;
        
    };

    friend bool operator>(const BigInt& a, const BigInt& b){
        //Deve retornar true se a for maior que b e 
        //false caso contrario: a > b
        int i, aux;
        if(a._npartes > b._npartes){ // a é maior que b em elementod
            return true;
        }
        else if(a._npartes < b._npartes){
            return false;
        }
        else{ // tem tamanhos iguais
            i = a._npartes -1;
            while(i >= 0)
            {
                if( a._partes[i] > b._partes[i]){
                    return true;
                }
            else{
                return false;
            }
            i--;
            }
            return false;
        }
    };

    friend BigInt operator+(const BigInt& a, const BigInt& b){
        BigInt result;
        int aux =0;

        if(a._npartes > b._npartes)
        {
            aux = a._npartes;
        }
        else if(a._npartes < b._npartes){
            aux = b._npartes;
        }
        else{
            aux = a._npartes;
        }

        result._partes = new int{aux};
        for(int i=aux -1; i >= 0; i--){
            result._partes[i] = a._partes[i] + b._partes[i];
        }
        return result;
    };
    friend BigInt operator-(const BigInt& a, const BigInt& b){
        BigInt result;
        int aux =0;

        if(a._npartes > b._npartes)
        {
            aux = a._npartes;
        }
        else if(a._npartes < b._npartes){
            aux = b._npartes;
        }
        else{
            return 0;
        }

        result._partes = new int{aux};
        for(int i=aux -1; i >= 0; i--){
            if(a._npartes > b._npartes)
            {
                result._partes[i] = a._partes[i] - b._partes[i];
            }
           else{
                result._partes[i] = b._partes[i] - a._partes[i];
           }
        }
        return result;
    };
    BigInt operator-() const
    {
        BigInt aux; //cria uma copia em modulo
            aux._npartes = _npartes;
            aux._partes = new int(aux._npartes);
            for(int i=0; i<aux._npartes; i++){
                aux._partes[i] = _partes[i];
            }
            aux._positivo = false;
            return aux;
    };
    friend BigInt operator*(const BigInt& a, const BigInt& b){
        BigInt result;
        int aux =0;

        if(a._npartes > b._npartes)//a dimensão de a é amior que b
        {
            result._partes = new int[a._npartes];
            for(int i=0; i< b._npartes; i++){
                    int aux = a._partes[i] * b._partes[i];
                    if(aux <10)
                    {
                        result._partes[i] = aux;
                    }else{
                        result._partes[i] = aux % 10; //adiciona o resto na  12 % 10 = 2
                        int carry_out = aux/10; // 12/ 10 = 1 que será incrementado na proxima casa
                        if(i+1 < b._npartes){
                            result._partes[i + 1] += carry_out;
                        }
                        else{
                            std::cout << "O valor é superior a 9 digitos" << std::endl;
                        }
                    }
            }

        }
        else if(a._npartes < b._npartes){ //a dimensão de b é amior que a
            result._partes = new int[a._npartes];
            for(int i=0; i< a._npartes; i++){
                    int aux = a._partes[i] * b._partes[i];
                    if(aux <10)
                    {
                        result._partes[i] = aux;
                    }else{
                        result._partes[i] = aux % 10; //adiciona o resto na  12 % 10 = 2
                        int carry_out = aux/10; // 12/ 10 = 1 que será incrementado na proxima casa

                        if(i+1 < b._npartes){
                            result._partes[i + 1] += carry_out;
                        }
                        else{
                            std::cout << "O valor é superior a 9 digitos" << std::endl;
                        }
                    }
            }
        }
        else{ //tamanhos iguais 
            aux = a._npartes;
            result._partes = new int[a._npartes];
            for(int i=0; i< a._npartes; i++){
                  int aux = a._partes[i] * b._partes[i];
                    if(aux <10)
                    {
                        result._partes[i] = aux;
                    }else{
                        result._partes[i] = aux % 10; //adiciona o resto na  12 % 10 = 2
                        int carry_out = aux/10; // 12/ 10 = 1 que será incrementado na proxima casa

                        if(i+1 < b._npartes){
                            result._partes[i + 1] += carry_out;
                        }
                        else{
                            std::cout << "O valor é superior a 9 digitos" << std::endl;
                        }
                    }
            }

        }
        
        return result;
    };

    BigInt operator/(int b)
   {
        //criando uma cópia
        BigInt result;
        result._npartes = _npartes;
        result._partes - _partes;
        result._positivo = _positivo;

        for(int i =0; i<result._npartes; i++)
        {
            if(result._partes[i] != 0){
            
                result._partes[i] /= b;
            }   
        }
        return result;
    
   };

   friend std::ostream& operator<<(std::ostream &out, const BigInt &a){
        for(int i=0; i<a._npartes; i++)
        {
            std::cout << a._partes[i];
        }
   };

    friend BigInt operator^(const BigInt& a, const BigInt& b){
        //b * a^b >= 0

        if( b == 0)
        {
            return 1;
        }
        if( a == 0)
        {
            return 0;
        }
        BigInt aux;
    
        aux._partes[0] = 1;
        while( b._partes > 0){
            if(b._partes && 1 == 1)
            {
                for( int i=0; i< b._npartes; i++)
                {
                    aux._partes[i] = (aux._partes[i] *  a._partes[i]) - '0'; // aux = aux * a
                }
            }
                for(int i=0; i< a._npartes; i++)
                {
                    a._partes[i] = (a._partes[i] * a._partes[i] ) - '0';
                }
                for(int i=0; i< b._npartes; i++)
                {
                    b._partes[i] = b._partes[i] - '0'; 
                }
                for(int i=0; i< b._npartes; i++)
                {
                    b._partes[i] = b._partes[i] >> 1; // b= b/2
                }
            
        }

        return aux;
    };

    friend std::ostream& operator<<(std::ostream &out, const BigInt &a){
        for(int i=0; i< a._npartes; i++)
        {
            out << a._partes[i];
        }

        return out;
    }

};

