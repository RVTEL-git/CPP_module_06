#include "Serializer.hpp"
#include <sstream>
#include <limits>
#include <iostream>
#include <cmath>

uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}