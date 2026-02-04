# ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cctype>
class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &oldScalarConverter);
        ScalarConverter& operator=(const ScalarConverter &oldScalarConverter);
        ~ScalarConverter();
    public:
        static void convert(std::string const &value);

        class      InvalidInputNoPrintableException : public std::exception{
                public:
                    virtual const char* what() const throw();
            };
};

# endif