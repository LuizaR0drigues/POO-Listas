#include <iostream>
#include <vector>
#include <algorithm>

typedef std::vector<std::vector<int>> Matriz;
void ordena_par(Matriz &M)
{
    std::vector<int> cont(M.size(), 0); // vetor zerado do tamanho de linha de M

    for (int i = 0; i < M.size(); i++)
    {
        for (auto &elem : M[i])
        {
            if (elem % 2 == 0) // se for par
            {
                cont[i] += 1; // para cada linha um contador
            }
        }
    }

    for (int i = 0; i < M.size(); i++)
    {
        for (int j = 0; j < M.size() - 1; j++)
        {
            if (cont[j] > cont[j + 1] || (cont[j] == cont[j+1] && M[j] > M[j+1]))
            {
                std::swap(cont[j], cont[j + 1]);
                std::swap(M[j], M[j + 1]);
            }
        }
    }
}

int main()
{
    int nl, nc, val;
    std::cin >> nl >> nc;
    Matriz m = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    ordena_par(m);
    for (int i = 0; i < nl; i++)
    {
        for (int j = 0; j < nc; j++)
            std::cout << m[i][j] << " ";
        std::cout << std::endl;
    }
    return 0;
}