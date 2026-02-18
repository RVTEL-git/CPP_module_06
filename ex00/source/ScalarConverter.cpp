#include "ScalarConverter.hpp"
#include <iostream>

void ScalarConverter::convert(char* toconv)
{
	const std::string arg = toconv;
	Type type = parser(arg);
	std::cout << type << std::endl;
}