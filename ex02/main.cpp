#include "Base.hpp"

int main( int ac, char **av ){
	(void)av;
	int repeat = 1;

	std::srand(std::time(0));
	if (ac > 2)
		std::cerr << "Wrong input!\n";
	else
	{
		if (ac == 2)
		{
			if (atoi(av[1]) <= 0)
			{
				std::cerr << "Please input a number bigger than 0!\n";
				exit(1);
			}
			repeat = atoi(av[1]);
		}
		for (;repeat > 0; repeat--)
		{
			Base *BasePointer = generate();
			std::cout <<"Base Value:\t\t" << BasePointer << "\n\n";

			std::cout <<"Identifying...\nPointer:\t";
			identify(BasePointer);

			std::cout <<"Reference:\t";
			identify(*BasePointer);

			delete (BasePointer);
		}
	}
}