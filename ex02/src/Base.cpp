#include "Base.hpp"
#include "C.hpp"

Base::~Base()
{

}

Base * generate(void)
{
    std::srand(std::time(NULL));
    int num = std::rand();
    if (num % 2 == 0) {
        
    }    
    else if (num % 5 == 0) {
        
    }
    else if (num % 1 == 0) {
        return new C();
    }
    return new C();
}

void identify(Base* p)
{
    C *c = dynamic_cast<C*>(p);
    if (c == nullptr)
        std::cout << "Failed cast to C" << std::endl;
    else
        std::cout << "Type of object is C" << std::endl;
}
// void identufy(Base& p)
// {
//     try {
//         C &c = dynamic_cast<C&>(p);
//     } catch (const std::bad_cast &e){
//         std::cout << e.what() << std::endl;
//     }
// }