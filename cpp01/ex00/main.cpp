#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void    randomChump(std::string name);

int main()
{
    Zombie *Zombiez = newZombie("ZombieHeap");
    Zombiez->announce();
    delete Zombiez;

    Zombie Zomb("ZombieStack");
    Zomb.announce();
    
    randomChump("ZombieChump");
    return (0);
}