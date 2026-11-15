#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

Base::~Base()
{
}

Base	*generate(void)
{
	int	num;

    std::cout << "Generating random number..." << std::endl;
	std::srand(std::time(NULL));
	num = std::rand();
	std::cout << "Generated random number is " << num << std::endl;
    std::cout << "-----" << std::endl;
	if (num % 2 == 0)
		return (new A());
	else if (num % 5 == 0)
		return (new B());
	else if (num % 1 == 0)
		return (new C());
	return (nullptr);
}

void	identify(Base *p)
{
	A	*a;
	B	*b;
	C	*c;

    std::cout << "Identifying object by pointer..." << std::endl;
	a = dynamic_cast<A *>(p);
	if (a)
	{
		std::cout << "Type of object is A" << std::endl;
		return ;
	}
	b = dynamic_cast<B *>(p);
	if (b)
	{
		std::cout << "Type of object is B" << std::endl;
		return ;
	}
	c = dynamic_cast<C *>(p);
	if (c)
	{
		std::cout << "Type of object is C" << std::endl;
		return ;
	}
	std::cout << "Type is undefined" << std::endl;
	return ;
}
void	identify(Base &p)
{
    std::cout << "-----" << std::endl;
    std::cout << "Identifying object by reference..." << std::endl;
	try
	{
		A &a = dynamic_cast<A &>(p);
		std::cout << "Type of object is A" << std::endl;
	}
	catch (const std::bad_cast &e)
	{
		try
		{
			B &b = dynamic_cast<B &>(p);
			std::cout << "Type of object is B" << std::endl;
		}
		catch (const std::bad_cast &e)
		{
			try
			{
				C &c = dynamic_cast<C &>(p);
				std::cout << "Type of object is C" << std::endl;
			}
			catch (const std::bad_cast &e)
			{
				std::cout << "Type is undefined" << std::endl;
			}
		}
	}
}
