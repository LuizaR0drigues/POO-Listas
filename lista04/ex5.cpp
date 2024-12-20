#include <iostream>
#include <map>

//defininfo o tipo matriz
typedef std::map<std::pair<int,int>,int> Matriz;
Matriz soma(const Matriz& A, const Matriz& B){
    Matriz soma= A;
    for(const auto& [indice, valor] : B){
        //se o primeiro e segundo elemento for iguais a -1, o valor nao se altera
        if(indice.first == -1 && indice.second == -1) //-1 índica o tamanho
        {
            soma[indice] = valor;
        }
        else{//realiza dos elementos que se encontram e indice != -1
            soma[indice] += valor;
        }
        
    }
    return soma;
}

int main() {
Matriz A = { {{-1, -1}, 2}, {{0,0}, 1}};
Matriz B = { {{-1, -1}, 2}, {{1,0}, 5}};
Matriz C = soma(A, B);
for(const auto& [k, v] : C)
std::cout << k.first << " " << k.second << " "

<< v << std::endl;

return 0;
}