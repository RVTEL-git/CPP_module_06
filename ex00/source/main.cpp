#include "ScalarConverter.hpp"
#include <iostream>

int main(int ac, char *av[])
{
	if (ac == 2)
	{
		ScalarConverter::convert(av[1]);
	}
	std::cerr << "Error\nWrong arg number" << std::endl;
}