# ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
#include <stdint.h>

typedef struct Data {
    std::string item_name;
    int nb_items;
} Data;

class Serializer {
    private:
        Serializer();
        Serializer(const Serializer &oldSerializer);
        Serializer& operator=(const Serializer &oldSerializer);
        ~Serializer();
    public:
        static  uintptr_t serialize(Data* ptr);
        static  Data* deserialize(uintptr_t raw);
};

# endif