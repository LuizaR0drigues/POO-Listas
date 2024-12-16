#include <iostream>
#include <string>
#include <regex>
#include <vector>


std::string retira(std:: string texto, char c){
    //copia do texto original
    std::string cpy_texto =  texto;

    //usando o regex para encontra o char e remove-lo
    std::regex  reg(std::string(1, c));
    cpy_texto = std::regex_replace(cpy_texto, reg, "");

    return cpy_texto;
}

int main() {
std::cout << retira("Testes" , 'e' ) << std::endl;
std::cout << retira("Testes" , 'X' ) << std::endl;
return 0;
}