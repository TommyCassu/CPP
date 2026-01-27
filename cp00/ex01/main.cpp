#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook pBook;
    std::string input;

    while (true)
    {
        std::cout << "Enter a Phone Number instruction  : ADD | SEARCH | EXIT" << std::endl;
        std::cout << "> ";
        std::getline (std::cin, input);
        if (input == "EXIT")
            break ;
        else if (input == "ADD")
            pBook.add_contact();
        else if (input == "SEARCH")
            pBook.search_contact();
        else
            std::cout << "Enter a valid instruction please !" << std::endl;
    }
}