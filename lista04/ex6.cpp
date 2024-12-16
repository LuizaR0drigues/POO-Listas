#include <iostream>
#include <vector>


std::vector<int> retira(std::vector<int> v, int n)
{
    std::vector<int> cpy_v = v;

    for (int i = 0; i < cpy_v.size();)
    {
        // Se o valor for igual ao número a ser removido
        if (cpy_v[i] == n)
        {
            cpy_v.erase(cpy_v.begin() + i); // Remove o elemento em i
        }
        else
        {
            i++; // incrementa caso contrario
        }
    }

    //bubble sort que ordena e apaga elementos repetidos na cpy_v
    for (int i = 0; i < cpy_v.size(); i++) 
    {
        for (int j = 0; j < cpy_v.size() - i - 1; j++)  
        {
            //realiza a troca
            if (cpy_v[j] > cpy_v[j + 1]) 
            {
                std::swap(cpy_v[j], cpy_v[j + 1]);
            }
            //apaga a partir da segunda repeticao
            if(cpy_v[j] == cpy_v[j + 1]){
                 cpy_v.erase(cpy_v.begin() + j + 1);
            }
        }
    }

    return cpy_v;
}

#include <iostream>
int main() {
std::vector<int> v = {5,1,8,4,3,5};
for(auto e : retira(v, 8) )
std::cout << e << std::endl;
return 0;
}