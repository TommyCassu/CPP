#include "Serializer.hpp"

int main() {

    Data data;

    data.item_name = "Yaourt";
    data.nb_items = 66;

    std::cout << "Default value :" <<std::endl;
    std::cout << data.item_name <<std::endl;
    std::cout << data.nb_items <<std::endl;

    std::cout << "Serialization and Deserialization :" <<std::endl;
    uintptr_t serialized = Serializer::serialize(&data);
    Data *deseralized = Serializer::deserialize(serialized);
    std::cout << deseralized->item_name <<std::endl;
    std::cout << deseralized->nb_items <<std::endl;

}