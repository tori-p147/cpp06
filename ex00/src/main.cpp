#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	(void)argc;
	ScalarConverter sc;
	sc.convert(argv[1]);
	return (0);
}
