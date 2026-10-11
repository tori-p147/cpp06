#ifndef SCALAR_HPP
#define SCALAR_HPP

#include <iostream>
#include <string>


class ScalarConverter
{
	public:
		ScalarConverter();
		~ScalarConverter();
		static void convert(std::string src) {
			std::cout << "char: " << src[0] << std::endl;
			std::cout << "int: " << std::atoi(src.c_str()) << std::endl;
			std::cout << "float: " << std::atof(src.c_str()) << "f" << std::endl;
			std::cout << "double: " << std::strtod(src.c_str(), nullptr) << ".0" << std::endl;
		}
};

#endif 