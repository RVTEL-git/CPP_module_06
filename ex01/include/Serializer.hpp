#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "utils.hpp"
#include "Data.hpp"
#include <string>
#include <stdint.h>

class Serializer
{
	private:
		Serializer();
		Serializer(Serializer &rhs);
		~Serializer();
		Serializer &operator=(Serializer &src);
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data			*deserialize(uintptr_t raw);
};

#endif