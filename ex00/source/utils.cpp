#include "utils.hpp"
#include <iostream>

static inline bool	simple_check(const std::string arg, Type *type)
{
	if (arg == "+inf")
	{
		*type = DOUBLE;
		return (true);
	}
	if (arg == "-inf")
	{
		*type = DOUBLE;
		return (true);
	}
	if (arg == "nan")
	{
		*type = DOUBLE;
		return (true);
	}
	if (arg == "+inff")
	{
		*type = FLOAT;
		return (true);
	}
	if (arg == "-inff")
	{
		*type = FLOAT;
		return (true);
	}
	if (arg == "nanf")
	{
		*type = FLOAT;
		return (true);
	}
	if (!arg[0])
	{
		*type = EMPTY;
		return (true);
	}
	if (!arg[1] && isalpha(arg[0]))
	{
		*type = CHAR;
		return (true);
	}
	return (false);
}

Type parser(const std::string arg)
{
	bool	hasDot = false;
	bool	hasF = false;
	bool	invalid = false;
	Type	ret;

	if (!simple_check(arg, &ret))
	{
		size_t	i = 0;
		size_t	len = arg.length();
		while (i < len)
		{
			if (isdigit(arg.at(i)))
				i++;
			else if (!hasDot && arg[i] == '.')
			{
				hasDot = true;
				i++;
			}
			else if (!hasF && arg[i] == 'f')
			{
				hasF = true;
				i++;
			}
			else
				break;
		}
		if (i < arg.length())
		{
			invalid = true;
			ret = NONE;
			return (ret);
		}
		if (hasDot && hasF)
		{
			ret = FLOAT;
			return (ret);
		}
		if (hasDot && !hasF)
		{
			ret = DOUBLE;
			return (ret);
		}
		ret = INT;
		return (ret);
	}
	return (ret);
}
