#include <iostream>

int main()
{
    float nb,precb, nc, precc, aux;

    std:: cin >> nb;
    std :: cin >> precb;
    std :: cin>> nc;
    std :: cin >> precc;
    
    aux = nb * precb + nc * precc;
    
    printf("%.1f\n", aux);

    return 0;
}