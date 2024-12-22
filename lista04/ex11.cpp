#include <iostream>
#include <string>
#include <regex>

class Pessoa
{
private:
    std::string _nome, _cidade, _uf, _pais;
    int _idade;

public:
    Pessoa(const std::string& str)
    {
        //std::cout <<  str << std::endl;
        // Regex  nome, idade, cidade, UF e país
        std::regex reg(R"(([^,]+) tenho (\d+) anos e moro em (.+)-([A-Z]{2}),([^\"]+))");
        std::smatch match;

        if (std::regex_search(str, match, reg))
        {
            /*teste 
            std::cout << "Nome:" << match[1] << std::endl;
            std::cout << "Idade:" << match[2] << std::endl;
            std::cout << "Cidade:" << match[3] << std::endl;
            std::cout << "UF:" << match[4] << std::endl;
            std::cout << "País:" << match[5] << std::endl;
            */
            // Atribuir os valores capturados
            _nome = match[1];
            _idade = std::stoi(match[2].str());  // Converte int
            _cidade = match[3];
            _uf = match[4];
            _pais = match[5];
        }

    }
    //impressao usando o std::cout<<
    friend std::ostream &operator<<(std::ostream &os, const Pessoa &A)
    {
        os << A._nome << std::endl;
        os << A._idade << std::endl;
        os << A._cidade << std::endl;
        os << A._uf << std::endl;
        os << A._pais << std::endl;
        return os;
    }
};

int main()
{
    std::cout << Pessoa("André tenho 34 anos e moro em São Carlos-SP,Brasil");

    return 0;
}
