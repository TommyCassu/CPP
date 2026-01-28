#include <iostream>
#include <string>
#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		Harl harl;
		harl.complain(av[1]);
	}
	else
	{
		std::cerr << "Error please respect usage : ./harlFilter valid_level" << std::endl;
		return (1);
	}
	return (0);
}