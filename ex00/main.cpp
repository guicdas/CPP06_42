#include "ScalarConverter.hpp"

int main( int ac, char **av ){
	//const ScalarConverter sc = ScalarConverter();
	if (ac < 2)
		std::cout << "Please write an argument!\n";
	else if (ac > 2)
		std::cout << "Too many arguments!\n";
	else
		ScalarConverter::convert(av[1]);
}