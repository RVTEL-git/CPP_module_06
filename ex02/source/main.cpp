#include "Base.hpp"
#include "utils.hpp"
#include <iostream>

int main(int ac, char *av[])
{
	if (ac == 1)
	{
		(void)av;
		Base *ptr = generate();

		if (ptr)
		{
			identify(ptr);
			identify(*ptr);
			delete ptr;
			return (0);
		}
		else
		{
			std::cerr << "Error: Failed to generate object" << std::endl;
			return (1);
		}
	}
	std::cerr << "Error\nNo arg needed" << std::endl;
	return (1);
}