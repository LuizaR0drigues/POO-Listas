#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void ordena_strings(std::vector<std::string> &vetor)
{
    // ordena de forma crescente as strings
    //possui uma verificação dentro do metodo de ordenação que ira verificar os tamnhso da strings, em caso de empate, inverte a ordem
    std::sort(vetor.begin(), vetor.end(), [](const std::string elem1, const std::string elem2)
    {
        if(elem1.size() != elem2.size()){ //em caso de tamnhos diferentes
            return elem1.size() < elem2.size(); 
        }
        return elem1 > elem2; //devolve a ordem alfabetica inversa
    });

    
}

int main()
{
    std::vector<std::string> v;
    v.push_back("aaaaaaaaaaa");
    v.push_back("zzzzzzzzzzz");
    v.push_back("test");
    v.push_back("testando");
    v.push_back("testados");
    v.push_back("teste");
    ordena_strings(v);
    for (auto s : v)
        std::cout << s << std::endl;
    return 0;
}