#include "../inc/Contact.hpp"

Contact::Contact()
{
    setFirstname("");
    setLastname("");
    setNickname("");
    setPhonenumber("");
    setDarkestsecret("");
}

void    Contact::setFirstname(const std::string &fname)
{
    first_name = fname;
}

void    Contact::setLastname(const std::string &lname)
{
    last_name = lname;
}

void    Contact::setNickname(const std::string &nname)
{
    nickname = nname;
}

void    Contact::setPhonenumber(const std::string &number)
{
    phone_number = number;
}

void    Contact::setDarkestsecret(const std::string &dsecret)
{
    darkest_secret = dsecret;
}

std::string    Contact::getFirstname(void) const
{
    return(first_name);
}

std::string    Contact::getLastname(void) const
{
    return(last_name);
}

std::string    Contact::getNickname(void) const
{
    return(nickname);
}

std::string    Contact::getPhonenumber(void) const
{
    return(phone_number);
}

std::string    Contact::getDarkestsecret(void) const
{
    return(darkest_secret);
}