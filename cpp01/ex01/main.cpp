#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name);

int main(void)
{
    int n;

    n = 10;
    Zombie *Zombiezz = zombieHorde(n, "Zombie");
    for (int i = 0; i < n; i++)
        Zombiezz[i].announce();
    delete[] Zombiezz;
    return (0);
}