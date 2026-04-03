#include "ScalarConverter.hpp"
#include <sstream> 
#include <iomanip>
#include <iostream>
#include <limits>
#include <cmath>


static void print_impossible(void)
{
	std::cout << "char: Impossible " << "\n";
	std::cout << "int: Impossible " << "\n";
	std::cout << "float: Impossible " << "\n";
	std::cout << "double: Impossible " << std::endl;
}

static void print_char(const std::string arg)
{
	const char	*str = arg.c_str();
	int			i = static_cast<int>(str[0]);
	float		flt = static_cast<float>(i);
	double		dbl = static_cast<double>(i);

	std::cout << "char: " << arg << "\n";
	std::cout << "int: " << i << "\n";
	std::cout << "float: " << flt << ".0f" << "\n";
	std::cout << "double: " << dbl << ".0" << std::endl;
}

static void print_edge(const std::string arg)
{
	if (arg == "nan" || arg == "nanf")
	{
		std::cout << "char: Impossible" << "\n";
		std::cout << "int: Impossible " << "\n";
		std::cout << "float: nanf" << "\n";
		std::cout << "double: nan" << std::endl;
		return ;
	}
	else if (arg == "+inf" || arg == "+inff")
	{
		std::cout << "char: Impossible" << "\n";
		std::cout << "int: Impossible " << "\n";
		std::cout << "float: +inff" << "\n";
		std::cout << "double: +inf" << std::endl;
		return ;
	}
	else if (arg == "-inf" || arg == "-inff")
	{
		std::cout << "char: Impossible" << "\n";
		std::cout << "int: Impossible " << "\n";
		std::cout << "float: -inff" << "\n";
		std::cout << "double: -inf" << std::endl;
		return ;
	}
}

static void print_num(const std::string arg)
{
	std::stringstream	ss;
	ss << arg;
	double				value;
	ss >> value;

	if (arg == "nan" || arg == "+inf" || arg == "-inf" || arg == "nanf" || arg == "+inff" || arg == "-inff")
	{
		print_edge(arg);
		return ;
	}

	if (value >= 0 && value <= 127 && std::isprint(value))
		std::cout << "char: " << static_cast<char>(value) << "\n";
	else  if (value > 255)
		std::cout << "char: Impossible" << "\n";
	else
		std::cout << "char: Non displayable" << std::endl;

	if (value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max() && value == static_cast<int>(value))
		std::cout << "int: " << static_cast<int>(value) << "\n";
	else 
		std::cout << "int: Impossible " << "\n";

	if (std::isfinite(value) &&
		std::abs(value) <= static_cast<double>(std::numeric_limits<float>::max()))
	{
		std::cout << "float: "
				<< std::fixed << std::setprecision(1)
				<< static_cast<float>(value)
				<< "f\n";
	}
	else
	{
		std::cout << "float: Impossible\n";
	}

	if (std::isfinite(value) &&
		std::abs(value) <= std::numeric_limits<double>::max())
	{
		std::cout << "double: "
					<< std::fixed << std::setprecision(1)
					<< value
					<< "\n";
	}
	else
	{
		std::cout << "double: Impossible\n";
	}
}

static void print(Type type, const std::string arg)
{
	switch (type)
	{
		case EMPTY : case NONE : 
			print_impossible();
			break;
		case CHAR :
			print_char(arg);
			break;
		case INT : case FLOAT : case DOUBLE :
			print_num(arg);
			break;
	}
}

void trim(std::string& str)
{
	str.erase(str.find_last_not_of(' ') + 1);
	str.erase(str.find_last_not_of('	') + 1);
	str.erase(0, str.find_first_not_of(' '));
	str.erase(0, str.find_first_not_of('	'));
}

void ScalarConverter::convert(char* toconv)
{
	std::string arg = toconv;
	trim(arg);
	Type type = parser(arg);
	print(type, arg);
}