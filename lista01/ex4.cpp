#include <iostream>

int main()
{
    int num, i;
    i =0;
    std:: cin >> num;
    while( i <= num)
        {
            if (i != 0 && i % 3 == 0 && 
                i % 5 == 0 &&
                i % 7 == 0 && 
                i % 11 == 0 &&
                i % 17 == 0)
            {
               std:: cout << i << std:: endl;
            }
            i++;
        }
    return 0;
}