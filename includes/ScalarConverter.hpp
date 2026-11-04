#ifndef SCALAR_HPP
#define SCALAR_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <exception>
#include <math.h>

class ScalarConverter
{
	public:
		ScalarConverter();
		~ScalarConverter();
		static void convert(std::string src) {
			
			// if (src == "-inf" || src == "+inf" || src == "nan")
			// {
			// 	std::cout << "char: " << "impossible" << std::endl;
			// 	std::cout << "int: " << "impossible" << std::endl;
			// 	std::cout << "float: " << src << "f" << std::endl;
			// 	std::cout << "double: " << src << std::endl;
			// 	return;
			// }

			if (src.length() == 1 && std::isalpha(src[0]))
				std::cout << "char: " << src[0] << std::endl;
			else if (isinf(std::strtod(src.c_str(), NULL)) || isnan(std::strtod(src.c_str(), NULL)) )
				std::cout << "char: " << "impossible" << std::endl;
			else
				std::cout << "char: " << "Non displayable" << std::endl;
			
			int num;
			bool overflow = false;
			num = std::atoi(src.c_str());
			if (num < INT32_MIN || INT32_MAX < num) {
				std::cout << "int: " << "impossible" << std::endl;
				overflow = true;
			}
			if (!overflow)
				std::cout << "int: " << num << std::endl;
			
			overflow = false;
			std::cout << std::fixed << std::setprecision(1);
			float f;
			try {
				f = std::atof(src.c_str());
			} catch (std::exception &e)
			{
				std::cout << "float: " << "impossible" << std::endl;
				overflow = true;
			}
			if (!overflow)
				std::cout << "float: " << f << "f" << std::endl;
			overflow = false;

			double d;
			try {
				d = std::strtod(src.c_str(), NULL);
			} catch (std::exception &e)
			{
				std::cout << "double: " << "impossible" << std::endl;
				overflow = true;
			}
			if (!overflow)
				std::cout << "double: " << d << std::endl;
		}
};

#endif 