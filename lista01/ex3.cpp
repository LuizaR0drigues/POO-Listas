#include <iostream>

int main()
{
    int n;
    std::cin >> n;

   for(int i =0; i<=2*n; i++)
    {
        if (i < 2 * n) {
            std::cout << i << ", "; 
        } else {
            std::cout << i; 
        }
    }
    return 0;

}