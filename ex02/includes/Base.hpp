#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>

class Base {
    public:
        virtual ~Base();
};

Base * generate(void);
void identify(Base* p);
// void identufy(Base& p);

#endif