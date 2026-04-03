#include "utils.hpp"

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <stdlib.h>
#include <time.h>
#include <iostream>

Base	*generate(void)
{
	srand(time(0));
	int	randm = rand();
	Base *ret;
	if (randm % 3 == 0)
	{
		std::cout << "New A created" << std::endl;
		ret = new A;
	}
	else if (randm % 2 == 0)
	{
		std::cout << "New B created" << std::endl;
		ret = new B;
	}
	else
	{
		std::cout << "New C created" << std::endl;
		ret = new C;
	}
	return (ret);
}

void	identify(Base *p)
{
	if (!p)
	{
		std::cerr << "Error\nRecieveing a NULL pointer" << std::endl;
		return ;
	}
	if (dynamic_cast<A*>(p))
		std::cout << "Object ptr is class A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Object is class B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Object is class C" << std::endl;
}

void	identify(Base &p)
{
	for (int i = 0; i < 3; i++)
	{
		try
		{
			switch (i)
			{
				case 0:
				{
					A a = dynamic_cast<A&>(p);
					std::cout << "Object ref is class A" << std::endl;
					break;
				}
				case 1:
				{
					B b = dynamic_cast<B&>(p);
					std::cout << "Object ref is class B" << std::endl;
					break;
				}
				case 2:
				{
					C c = dynamic_cast<C&>(p);
					std::cout << "Object ref is class C" << std::endl;
					break;
				}
			}
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}