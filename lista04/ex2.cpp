#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <limits>
#include <unordered_map>


std::string jogo(std::stack<int> cartas, std::queue<std::string> jogadores){

    std::stack<int> cpy_cartas = cartas; //copia da pilha 
    int tam = jogadores.size();
    std::vector<std::string> distri(tam); //um vector do tamanho de players
    std::vector<int> soma_cartas(tam, 0); //um vetor para somar as cartas
    int cont =0;

    //copia de jogadores
    std::vector<std::string> nomes_jogadores;
    for (int i = 0; i < tam; ++i) {
        nomes_jogadores.push_back(jogadores.front());
        jogadores.push(jogadores.front()); // Reinsere o jogador no final da fila
        jogadores.pop();
    }

    //distribuição de cartas
    while(not cpy_cartas.empty()){
        int elem = cpy_cartas.top(); //pega o elem do topo
        cpy_cartas.pop(); //retir 1 elem da pilha

        //verifica o primerio jogador e o "retira" da fila
        std::string player = jogadores.front();
        jogadores.pop();

        //distribuindo as cartas
        distri[cont] += std::to_string(elem) + " ";
        soma_cartas[cont] += elem;

        //o jogador em questão volta ao final da fila
        jogadores.push(player);
        
        //atualiza o contador
        cont = (cont + 1) %tam;
    
    }

    //inicializando variaveis para encontrar o jagador com menor pontos
   int menor_soma = soma_cartas[0];
    std::string vencedor = nomes_jogadores[0];

    for (int i = 1; i < tam; ++i) {
        if (soma_cartas[i] < menor_soma || 
           (soma_cartas[i] == menor_soma && nomes_jogadores[i] < vencedor)) {
            menor_soma = soma_cartas[i];
            vencedor = nomes_jogadores[i];
        }
    }

    return vencedor;
    

}

int main() {
// INICIALIZAC ̧AO DA PILHA  ̃
std::stack<int> cartas;
for(int e=1; e<=5; e++)
cartas.push(e);
// INICIALIZAC ̧AO DA FILA  ̃
std::queue<std::string> jogadores;
jogadores.push("andre" );
jogadores.push("bruno" );
jogadores.push("carla" );
// TESTE DE FATO
std::cout <<jogo(cartas, jogadores) << std::endl;
return 0;
}