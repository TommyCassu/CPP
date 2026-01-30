# ifndef Brain_HPP
# define Brain_HPP

# include <string>
# include <iostream>

class Brain
{
    protected:
        std::string _ideas[100];
    public:
        Brain();
        Brain(const Brain &brain);
        Brain &operator=(const Brain &brain);
        ~Brain();

};

# endif