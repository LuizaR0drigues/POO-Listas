#include <iostream>
#include <stack>

//declaração da função stack que retonra o kesimo elemto par
int elementok(std::stack<int>& pilha, int k){
    std::stack<int> cpy_pilha;
    cpy_pilha  = pilha;
    int cont =0;
    while( not pilha.empty())// equanto a cpy_pilha tiver elementos
    {
        int elem = cpy_pilha.top(); //pega o elem do topo
        cpy_pilha.pop(); //retir 1 elem da pilha

        //verifica se o topo é par e retorn se qtdpar for igual a k
        if( elem % 2 == 0) {
            cont++;
            if(cont == k )
            {
                return elem;
            }
        }
    }

    //caso não, retorna -1
    return -1;
}

int main(){
// INICIALIZAC ̧AO DA PILHA  ̃
std::stack<int> pilha;
for(int e=5; e>=1; e--) //inserindo elementos na pilha 
{
    pilha.push(e); //push -> insere elementos
}
// TESTE DE FATO
std::cout << elementok(pilha, 2) << std::endl;

while(not pilha.empty()) {
    std::cout << pilha.top() << " " ;

    pilha.pop();
    }
std::cout << std::endl;
return 0;
}