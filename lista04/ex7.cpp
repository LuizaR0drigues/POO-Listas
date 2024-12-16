#include <iostream>
#include <string>
#include <regex>



std::string retira(std::string texto, char c) {
    // Copia do texto original
    std::string cpy_texto = texto;
    
    // Usando o regex para encontrar o char e remove-lo
    std::string aux(1, c); // Criando uma string com o char 

    // Caracteres especiais - removendo os especiais
    std::string char_especial = std::regex_replace(aux, std::regex("([.*+?^=!:${}()|\\[\\]\\/\\\\])"), "\\$1");
    
    // Criando o regex
    std::regex reg(char_especial);

    // Substituindo o caractere específico
    cpy_texto = std::regex_replace(cpy_texto, reg, "");

    //std::cout << "Texto: " << texto << "\nCaractere: " << c << std::endl;
    return cpy_texto;
}

int main() {
    std::string texto;
    char c;

    std::getline(std::cin, texto);
    std::cin >> c;
    std::cout << retira(texto, c) << std::endl;
    return 0;
}