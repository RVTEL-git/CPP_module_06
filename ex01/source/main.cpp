#include "Serializer.hpp"
#include <iostream>

int main(int ac, char *av[])
{
	if (ac == 1)
	{
		(void)av;
		Data *ds = new Data;
		Data &ref = *ds;
		initData(ds);
		std::cout << "----------------------------" << std::endl;
		std::cout << "Before serialize: " << ds << std::endl;
		std::cout << "Reference as marker: " << &ref << std::endl;
		uintptr_t rawPtr = Serializer::serialize(ds);
		std::cout << "After serialize: " << rawPtr << std::endl;
		std::cout << "----------------------------" << std::endl;

		Data *tmp = NULL;
		std::cout << "Reference as marker: " << &ref << std::endl;
		tmp = Serializer::deserialize(rawPtr);
		std::cout << "After deserialize: " << tmp << std::endl;
		std::cout << "tmp->a: " << tmp->active << std::endl;
		std::cout << "tmp->b: " << tmp->id << std::endl;
		std::cout << "tmp->b: " << tmp->name << std::endl;
		std::cout << "----------------------------" << std::endl;

		delete ds;
		return (0);
	}
	std::cerr << "Error\nNo arg needed" << std::endl;
	return (1);
}