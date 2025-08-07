#include "../inc/PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    count = 0;
}

void PhoneBook::add_contact()
{
    std::string input;

    std::cout << "Enter First Name" << std::endl;
    std::getline(std::cin, input);
    Contacts[count % 8].setFirstname(input);

    std::cout << "Enter Last Name" << std::endl;
    std::getline(std::cin, input);
    Contacts[count % 8].setLastname(input);

    std::cout << "Enter Nickname" << std::endl;
    std::getline(std::cin, input);
    Contacts[count % 8].setNickname(input);

    std::cout << "Enter Phone Number" << std::endl;
    std::getline(std::cin, input);
    Contacts[count % 8].setPhonenumber(input);

    std::cout << "Enter Darkest Secret" << std::endl;
    std::getline(std::cin, input);
    Contacts[count % 8].setDarkestsecret(input);
    std::cout << std::endl;

    std::cout << "Contact create successfully !" << std::endl;

    if (count <  8)
        count++;
}

std::string formatData(const std::string& value)
{
    if (value.length() > 10)
        return (value.substr(0, 9) + ".");
    return (value);
}
void    PhoneBook::search_contact()
{
    int i;
    int index;
    std::string input;

    i = 0;
    std::cout << "#___________________________________________#" << std::endl;
    while (i < count)
    {
        std::cout << "|" << std::setw(10) << i;
        std::cout << "|" << std::setw(10) << formatData(Contacts[i].getFirstname());
        std::cout << "|" << std::setw(10) << formatData(Contacts[i].getLastname());
        std::cout << "|" << std::setw(10) << formatData(Contacts[i].getNickname()) << "|" << std::endl; 
        i++;
    }
    std::cout << "Enter the index of user :" << std::endl;
    std::getline(std::cin, input);
    std::stringstream ss(input);
    if (ss >> index && (index < 9 && index >= 0) && !Contacts[index].getFirstname().empty())
    {
        std::cout << std::left << std::setw(10) << "First Name";
        std::cout << ": " << Contacts[index].getFirstname() << std::endl;
        std::cout << std::left << std::setw(10) << "Last Name";
        std::cout << ": " <<Contacts[index].getLastname() << std::endl;
        std::cout << std::left << std::setw(10) << "Nickname";
        std::cout << ": " <<Contacts[index].getNickname() << std::endl;
        std::cout << std::left << std::setw(10) << "Number";
        std::cout << ": " << Contacts[index].getPhonenumber() << std::endl;
        std::cout << std::left << std::setw(10) << "Darkest Secret";
        std::cout << ": " <<Contacts[index].getDarkestsecret() << std::endl;
    }
    else
        std::cout << "Enter a valid index or contact have empty name";
}