#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main()
{
    std::cout << "* Constructor *" << std::endl;
    const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    std::cout << std::endl;
    std::cout<< "* TYPE *" << std::endl;
    std::cout << "Animal type is " << meta->getType() << std::endl;
    std::cout << "Animal type is " << cat->getType() << std::endl;
    std::cout << "Animal type is " << dog->getType() << std::endl;
    std::cout << std::endl;
    std::cout<< "* Sound *" << std::endl;
    meta->makeSound(); 
    dog->makeSound();
    cat->makeSound();
    delete meta;
    delete dog;
    delete cat;
    std::cout << std::endl;
    std::cout<< "* WrongAnimal/Cat*" << std::endl;
    const WrongAnimal* wronganimal = new WrongAnimal();
    const WrongAnimal* wrongcat = new WrongCat();
    std::cout << wrongcat->getType() << " " << std::endl;
    wrongcat->makeSound();
    wronganimal->makeSound();
    delete wronganimal;
    delete wrongcat;
    return 0;
}