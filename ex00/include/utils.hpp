#ifndef UTILS_HPP
#define UTILS_HPP

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

Type parser(const std::string arg);

#endif