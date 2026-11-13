#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>
#include <iostream>
#include <stdint.h>
#include "Data.hpp"

class Serializer {

    public:
        Serializer();
        ~Serializer();
        static uintptr_t serialize(Data* ptr)
        {
            return reinterpret_cast<uintptr_t>(ptr);
        }
        Data* deserializer(uintptr_t raw) 
        {
            return reinterpret_cast<Data*>(raw);
        }
};

#endif