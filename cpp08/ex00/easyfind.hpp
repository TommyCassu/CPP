# ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>

class      OccurrenceNotFoundException : public std::exception{
            public:
                virtual const char* what() const throw() {
                    return ("Occurence not found !");
    };
};

template<typename T>
typename T::iterator   easyfind(T& param1, int param2) {
    typename T::iterator it = std::find(param1.begin(), param1.end(), param2);
    if (it == param1.end())
        throw OccurrenceNotFoundException();
    return it;
}
# endif