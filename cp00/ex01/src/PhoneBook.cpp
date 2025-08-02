#include "../inc/PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    count = 0;
}

void PhoneBook::add_contact()
{
    std::string input;

    std::cout << "Enter First Name" << std::endl;
    std::cin >> input;
    Contacts[count].setFirstname(input);

    std::cout << "Enter Last Name" << std::endl;
    std::cin >> input;
    Contacts[count].setLastname(input);

    std::cout << "Enter Nickname" << std::endl;
    std::cin >> input;
    Contacts[count].setNickname(input);

    std::cout << "Enter Phone Number" << std::endl;
    std::cin >> input;
    Contacts[count].setPhonenumber(input);

    std::cout << "Enter Darkest Secret" << std::endl;
    std::cin >> input;
    Contacts[count].setDarkestsecret(input);
    std::cout << std::endl;

    std::cout << "Contact create successfully !" << std::endl;

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
    int input;

    i = 0;
    std::cout << "#__________";
    std::cout << "___________";
    std::cout << "___________";
    std::cout << "__________#" << std::endl;
    while (i < count)
    {
        std::cout << "|" << std::setw(10) << i;
        std::cout << "|" << std::setw(10) << formatData(Contacts[i].getFirstname());
        std::cout << "|" << std::setw(10) << formatData(Contacts[i].getLastname());
        std::cout << "|" << std::setw(10) << formatData(Contacts[i].getNickname()) << "|" << std::endl; 
        i++;
    }
    std::cout << "Enter the index of user :" << std::endl;
    std::cin. >> input;
    if (input < 9 && input > 0)
    {
        std::cout << std::left << std::setw(10) << "First Name";
        std::cout << ": " << Contacts[input].getFirstname() << std::endl;
        std::cout << std::left << std::setw(10) << "Last Name";
        std::cout << ": " <<Contacts[input].getLastname() << std::endl;
        std::cout << std::left << std::setw(10) << "Nickname";
        std::cout << ": " <<Contacts[input].getNickname() << std::endl;
        std::cout << std::left << std::setw(10) << "Number";
        std::cout << ": " <<Contacts[input].getPhonenumber() << std::endl;
        std::cout << std::left << std::setw(10) << "Darkest Secret";
        std::cout << ": " <<Contacts[input].getDarkestsecret() << std::endl;
    }

}
//std::cout << Contacts[count].getFirstname() << std::endl;