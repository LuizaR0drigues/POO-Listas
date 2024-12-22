#include <iostream>
#include <vector>
#include <string>
#include <regex>

std::vector<double> notas(std::string s)
{
    // Uso do regex
    std::vector<double> notas; // Vetor para armazenar as notas extraídas
    std::regex re(R"(\d+(\.\d+)?)"); //definindo que pega o double

    //https://en.cppreference.com/w/cpp/regex/regex_iterator
    //pega a primeira inyeracao na string
    std::regex_iterator<std::string::iterator> aux(s.begin(), s.end(), re);
    std::regex_iterator<std::string::iterator> rend; //intera sobre a string

    for(; aux != rend; ++aux){
        // Adiciona as notas encontradas ao vetor
        notas.push_back(std::stod(aux->str())); // Converte e armazena a nota
    }

    return notas;
}

int main()
{
    std::string s = "Andre,10,Smaira,5"; // String de entrada
    for (double n : notas(s)) {
        std::cout << n << std::endl; // Exibe as notas extraídas
    }

    return 0;
}
