#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <sstream>


class Contact
{
    private:
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
    public:
        Contact();
        ~Contact();
        std::string getFirstname(void) const;
        std::string getLastname(void) const;
        std::string getNickname(void) const;
        std::string getPhonenumber(void) const;
        std::string getDarkestsecret(void) const;
        void setFirstname(const std::string &name);
        void setLastname(const std::string &name);
        void setNickname(const std::string &name);
        void setPhonenumber(const std::string &name);
        void setDarkestsecret(const std::string &name);
};

#endif