#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
    Serializer s;
    Data data;
    data.name = "src";
    data.value = 1;
    uintptr_t uint_ptr = s.serialize(&data);
    Data *deserialized_data = s.deserializer(uint_ptr);
    std::cout << "Pointer to data object: " << &data << std::endl;
    std::cout << "Pointer after deserialized data object: " << deserialized_data << std::endl;
    std::cout << "Deserialized data object name: " << deserialized_data->name << std::endl;
    std::cout << "Deserialized data object value: " << deserialized_data->value << std::endl;
    return 0;
}