#ifndef SCALAR_HPP
#define SCALAR_HPP

#include <iostream>
#include <iomanip>
#include <limits>
#include <cfloat>
#include <cctype>

class ScalarConverter
{
public:
	ScalarConverter();
	~ScalarConverter();
	static void convert(std::string src)
	{
		if (src.length() == 1 && std::isprint(src[0]) && !std::isdigit(src[0]))
		{
			std::cout << "char: " << src[0] << std::endl;
			std::cout << "int: " << "Non displayable" << std::endl;
			std::cout << "float: " << "Non displayable" << std::endl;
			std::cout << "double: " << "Non displayable" << std::endl;
			return;
		}
		double d = std::stod(src);
		bool isPseudoLiteral = (d == std::numeric_limits<double>::infinity() 
			|| d == -std::numeric_limits<double>::infinity()
			|| d != d);
		if (isPseudoLiteral)
			std::cout << "char: " << "impossible" << std::endl;
		else if (std::isdigit(src[0]))
			std::cout << "char: " << "Non displayable" << std::endl;
		else
			std::cout << "char: " << "'*'" << std::endl;

		if (isPseudoLiteral || d < INT32_MIN || INT32_MAX < d)
			std::cout << "int: " << "impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(d) << std::endl;

		std::cout << std::fixed << std::setprecision(1);
		if (isPseudoLiteral)
			std::cout << "float: " << d << "f" << std::endl;
		else if (d < -FLT_MAX || FLT_MAX < d)
			std::cout << "float: " << "impossible" << std::endl;
		else
			std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;

		if (isPseudoLiteral)
			std::cout << "double: " << d << std::endl;
		else if (d < -DBL_MAX || DBL_MAX < d)
			std::cout << "double: " << "impossible" << std::endl;
		else
			std::cout << "double: " << d << std::endl;
	}
};

#endif