#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string>
#define TAM_MAX 9


class BigInt
{
private:
    int* _partes; //vetor com as noves partes do numero BigInt
    int _npartes; //numero de elementos presentes no vetor
    bool _positivo; //representa se o numero é positivo(true), negativo(false)
public:
    BigInt(std::string numero)//recebe o numero em string e quebrada em parte para por no vetor int
    {
        //encontrando o tamanho da string
        int aux = numero.length();
        printf("Aqui %d \n", aux);
        //verificação de sinal
        if(numero[0] == '-')
        {
            _positivo = false;
            aux -=1;
        }
        else{
            _positivo = true;
        }
        printf("testeanto\n");
         //valor de nparte
         _npartes = (aux + TAM_MAX -1) / TAM_MAX; //tam da string  + tamanho maximo(9) -1 /9
        _partes = (int*)malloc(_npartes *sizeof(int));

        int inicio;
        for(int i=_npartes-1; i>= 0; i--)
        {
            inicio = aux - TAM_MAX;
            if(inicio >= 0)
            {    _partes[i] = std::stoi(numero.substr((inicio,TAM_MAX)));
                aux = inicio;
            }
             else {
            _partes[i] = std::stoi(numero.substr(0, aux)); // Extrai o restante
            }
        }
        // Teste de saída
        printf("Número original: %s\n", numero.c_str());
        for (int i = 0; i < _npartes; i++) {
            printf("Aqui");
            printf("Parte %d: %d\n", i, _partes[i]);
        }
        
       
    };
    BigInt(int num, bool eh_num = true){
        if(eh_num) //conversãao de int para bigint
        {
             printf("Aqui");
            std::string aux = std::to_string(std::abs(num));
            int tam_num = aux.size();
            if( num >= 0 ){
                _positivo = true;
            }
            else{
                _positivo = false;
            }

            _npartes = (aux.size() + TAM_MAX -1)/TAM_MAX;
            _partes = (int*)malloc(_npartes * sizeof(int));


            int inicio, aux2;
            aux2 = aux.size();
            for(int i=_npartes-1; i>= 0; i--)
            {
                inicio = aux2 - TAM_MAX;
                if(inicio >= 0)
                {    _partes[i] = std::stoi(aux.substr((inicio, aux2- inicio)));
                    aux = inicio;
                }
            }

        }
        else{
            _npartes = num;
            _positivo = true;
            _partes = new int[_npartes];
            for( int i = 0; i<_npartes; i++)
            {
                _partes[i] = 0;
            }
        }
        
    };
    
    BigInt() //cria um vetor zerado
    {
         _npartes = 1;
         _partes = new int[1];
         _partes[0] = 0;
    };
    BigInt(BigInt&& b) //passa a posse de b para a
    {
        //tranferindo os dados
         _partes = b._partes;
         _npartes = b._npartes;
         _positivo = b._positivo;

         b._npartes =0;
         b._partes = nullptr;

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
        if( _partes != nullptr)
                delete[]_partes;
        
        _npartes = b._npartes;
        _positivo = b._positivo;
        
    
        _partes = new int[_npartes];
        for(int i=0; i<_npartes; i++){
                _partes[i] = b._partes[i];
        }
        
        return *this;
    };

    BigInt abs() // Retorna um BigInt representando o modulo do numero
    {
            BigInt aux;
            aux._npartes = _npartes;
            aux._partes = new int[aux._npartes];
            aux._positivo = true;
            for(int i=0; i<aux._npartes; i++){
                aux._partes[i] = _partes[i];
            }
            
            return aux;
        
    };

    friend bool operator==(const BigInt& a, const BigInt& b){
        //Deve retornar true se a = b e 
        //false caso contrario: a > b
       
        //verificação se possuem o mesmo sinal
        if( a._positivo != b._positivo)
        {
            return false;
        }
        
        //verificação de tamanho
        if( a._npartes != b._npartes)
        {
            return false;
        }
        
        bool flag = true;
        for(int i= a._npartes -1; i>= 0; i--)
        {
            if(a._partes[i] != b._partes[i]){
                flag = false;
            }

        }
        return flag;
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

        result._partes = new int[aux];
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
        if(a._npartes < b._npartes){
            aux = b._npartes;
        }
       
        result._partes = new int[aux];
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

   /*friend std::ostream& operator>>(std::ostream &out, const BigInt &a){
        for(int i=0; i<a._npartes; i++)
        {
            std::cout << a._partes[i];
        }
   };*/

    friend BigInt operator^(const BigInt& a, const BigInt& b){
        //b * a^b >= 0

        if( b == 0)
        {
            return BigInt();
        }
        if( a == 0)
        {
            return BigInt(1);
        }
        BigInt aux, auxB;
        auxB = b;
        aux._partes[0] = 1;
        while( auxB._partes[0] > 0){
            if((auxB._partes[0] & 1 )== 1)
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
                    auxB._partes[i] = auxB._partes[i] >> 1; // Desloca os bits para a direita (b / 2)
                }
        }

        return aux;
    };

    friend std::ostream& operator<<(std::ostream &out, const BigInt &a){
        std:: string aux;
       if(a._partes == nullptr)
       {
        return out;
       }

       if(!a._positivo){
        out << '-';
       }


        out << a._partes[0];
       for( int i=1; i< a._npartes-1; i++)
       {
            aux = std::to_string(a._partes[i]);

             // Preenche com zeros à esquerda se o tamanho for menor que TAM_MAX
            out << std::string(TAM_MAX - aux.length(), '0') << aux;
       }

        return out;
    }

};

int main() {
    BigInt a(-17246288);
    
    /*a = a ^ BigInt(16);*/
    a = a / (1252876278);
    std::cout<< a << std::endl;

    /*a = a + BigInt(702491595);
    a = a * BigInt(-526492506);
    std::cout << a << std::endl;
    a = a + BigInt(-1932018109);
    std::cout << a.abs() << std::endl;
    a = a - BigInt(1398450167);
    a = a * BigInt(-2087903471);
    std::cout << a.abs() << std::endl;
    a = a / (2078060853);
    a = a ^ BigInt(19);
    std::cout << a.abs() << std::endl;
    std::cout << a << std::endl;
    a = a ^ BigInt(26);*/
    return 0;
}