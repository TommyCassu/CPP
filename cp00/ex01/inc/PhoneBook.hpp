#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "../inc/Contact.hpp"

class PhoneBook
{
    private:
        Contact Contacts[8];
        int count;
    public:
        PhoneBook();
        void add_contact();
        void search_contact();
};

#endif
