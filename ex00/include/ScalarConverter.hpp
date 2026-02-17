#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

enum Type
{
	EMPTY,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	NONE
};

class ScalarConverter
{
	public:
		static void	convert(char* toconv);
};

#endif