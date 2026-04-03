#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include "utils.hpp"

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter &rhs);
		~ScalarConverter();
		ScalarConverter &operator=(ScalarConverter &src);
	public:
		static void	convert(char* toconv);
};

#endif