#include <iostream>
#include <vector>
#include <set>

//https://www.geeksforgeeks.org/set-in-cpp-stl/
std::set<int> converte_set(std::vector<int> v){
    std::set<int> aux;

    for(int i : v)
    {
        aux.insert(i); // Insere elementos no set de fromma ordeanda e sem repetição
    }
    return aux;
}
// remove o elemneto n 
std::vector<int> retira(std::vector<int> v, int n)
{
    std::set<int> set_v = converte_set(v);
    // Retirando elemento do set
    set_v.erase(n);

    // Cria um novo vetor 
    std::vector<int> aux_v;
    for(int a : set_v) {
        aux_v.push_back(a); // adiciona os elementos 
    }
    return aux_v;
}


#include <iostream>
int main() {
std::vector<int> v = {5,1,8,4,3,5};
for(auto e : retira(v, 8) )
std::cout << e << std::endl;
return 0;
}