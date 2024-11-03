#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

class  Arquivo
{
private:
    std::ifstream _conteudo; //iftream permite realizar a leitura do arquivo
public:
    Arquivo(std::string arquivo)
    {
        _conteudo.open(arquivo); //fopen(arq)
    };

    std::string proxima_linha()
    {
        std::string linha_arquivo;
        if(_conteudo.is_open()){
            std::getline(_conteudo, linha_arquivo); //permite pegar uma linha
           
        }else{
            std::cout << "Erro na leitura do arquivo.\n";
        }
         return linha_arquivo;
    };

    ~Arquivo(){//destrutor que ira liberar memmoria
        _conteudo.close(); //fecha o arquivo similar ao fclose(arq)
    };
};

int main(){

    Arquivo a("arquivo.txt" );
    std::cout << a.proxima_linha() << std::endl;
    std::cout << a.proxima_linha() << std::endl;
    return 0;
}
