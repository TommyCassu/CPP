#include <iostream>
#include <string.h>

int main(int ac, char **av)
{
    int    i;
    int j;


    i = 0;
    j = 1;
    if (ac >= 2)
    {
        while (av[j])
        {
            i = 0;
            while (av[j][i])
            {
                av[j][i] = toupper(av[j][i]);
                std::cout << av[j][i];
                i++;
            }
            std::cout << " ";
            j++;
        }
        std::cout << std::endl;
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}