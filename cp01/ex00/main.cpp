#include "Zombie.hpp"

int main()
{
    Zombie *Zombiez = newZombie("ZombieHeap");
    Zombiez->announce();
    delete Zombiez;

    Zombie Zomb("ZombieStack");
    Zomb.announce();
    
    randomChump("ZombieChump");
}