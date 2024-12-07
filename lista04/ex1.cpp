#include <iostream>
#include <stack>

//declaração da função stack que retonra o kesimo elemto par
int elementok(std::stack<int>& pilha, int k){
    std::stack<int> cpy_pilha;
    cpy_pilha  = pilha;
    int cont = 0;
 
    while( not cpy_pilha.empty())// equanto a cpy_pilha tiver elementos
    {
        int elem = cpy_pilha.top(); //pega o elem do topo
        cpy_pilha.pop(); //retir 1 elem da pilha

        //verifica se o topo é par e retorn se qtdpar for igual a k
        if( elem % 2 == 0 ) {
           cont++;
           //printf("%ld %d %d %d\n",pilha.size(), cont, k, elem);
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
std::stack<int> p;
    p.push(-584);
    p.push(984);
    p.push(766);
    p.push(530);
    p.push(572);
    p.push(250);
    p.push(-374);
    p.push(-863);
    p.push(-168);
    p.push(-180);
    p.push(751);
    p.push(-835);
    p.push(-730);
    p.push(-198);
    p.push(952);
    p.push(312);
    p.push(783);
    p.push(-139);
    p.push(-978);
    p.push(304);
    p.push(128);
    p.push(745);
    p.push(-839);
    p.push(-467);
    p.push(-971);
    p.push(410);
    p.push(387);
    p.push(-198);
    p.push(669);
    p.push(940);
    p.push(548);
    p.push(798);
    p.push(319);
    p.push(497);
    p.push(618);
    p.push(170);
    p.push(-132);
    p.push(-978);
    p.push(-340);
    p.push(84);
    p.push(-727);
    p.push(568);
    p.push(212);
    p.push(747);
    p.push(-283);
    p.push(-368);
    p.push(-159);
    p.push(763);
    p.push(-971);
    p.push(160);
    p.push(230);
    printf("%d\n", elementok(p, 78));
    printf("%d\n", elementok(p, 58));
    printf("%d\n", elementok(p, 87));
    printf("%d\n", elementok(p, 19));
    printf("%d\n", elementok(p, 29));
    printf("%d\n", elementok(p, 85));
    printf("%d\n", elementok(p, 48));
    printf("%d\n", elementok(p, 63));
    printf("%d\n", elementok(p, 30));
    printf("%d\n", elementok(p, 44));
    return 0;
}