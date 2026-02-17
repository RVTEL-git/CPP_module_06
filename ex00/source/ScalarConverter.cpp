#include "ScalarConverter.hpp"
#include <iostream>

static Type parser(const std::string arg)
{
	bool	hasDot = false;
	bool	hasF = false;
	bool	invalid = false;

	if (!arg[0])
		return (EMPTY);
	if (!arg[1] && isalpha(arg[0]))
		return (CHAR);
	size_t	i = -1;
	while (isdigit(arg.at(++i)))
	{
		if (arg[i] == '.')
			hasDot = true;
		else if (arg[i] == 'f')
			hasF = true;
	}
	if (i < arg.length())
	{
		invalid = true;
		return (NONE);
	}
	if (hasDot && hasF)
		return (FLOAT);
	if (hasDot && !hasF)
		return (DOUBLE);
	return (INT);
}

static void	convert(char* toconv)
{
	const std::string arg = toconv;
	Type type = parser(arg);
	std::cout << type << std::endl;
}