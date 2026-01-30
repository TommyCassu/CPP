#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{

    Animal* animals[4];
    
    std::cout << "* Constructor *" << std::endl;
    animals[0] = new Dog();
	animals[1] = new Dog();
	animals[2] = new Cat();
	animals[3] = new Cat();
    
    std::cout << std::endl;
    std::cout<< "* TYPE *" << std::endl;
    for (int i = 0; i < 4; i++) {
		std::cout << "Animal type is " << animals[i]->getType() << std::endl;
	}
    std::cout << std::endl;
    std::cout<< "* Sound *" << std::endl;
    for (int i = 0; i < 4; i++) {
		animals[i]->makeSound();
	}
    std::cout << std::endl;
    std::cout<< "*** Deep Copy ***" << std::endl;
    std::cout << std::endl;
    std::cout << "* Constructor *" << std::endl;
    Dog *DogFirst = new Dog();
	DogFirst->manageBrain()->setIdea(0, "Croquette");
	Dog DogSecond(*DogFirst);
	DogSecond.manageBrain()->setIdea(0, "Friandise");
    std::cout << std::endl;
    std::cout<< "* Idea : *" << std::endl;
	std::cout << "DogFirst idea : " << DogFirst->manageBrain()->getIdea(0) << std::endl;
	std::cout << "DogSecond idea: " << DogSecond.manageBrain()->getIdea(0) << std::endl;
    std::cout << std::endl;
    Cat *CatFirst = new Cat();
	CatFirst->manageBrain()->setIdea(0, "Dormir");
	Cat CatSecond(*CatFirst);
	CatSecond.manageBrain()->setIdea(0, "Lait");
    std::cout << std::endl;
    std::cout<< "* Idea : *" << std::endl;
	std::cout << "CatFirst idea : " << CatFirst->manageBrain()->getIdea(0) << std::endl;
	std::cout << "CatSecond idea: " << CatSecond.manageBrain()->getIdea(0) << std::endl;
    std::cout << std::endl;
    delete DogFirst;
    delete CatFirst;

    for (int i = 0; i < 4; i++) {
		delete animals[i];
	}
    return 0;

}

