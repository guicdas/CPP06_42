#include "ScalarConverter.hpp"

int main( int ac, char **av ){
	//const ScalarConverter sc = ScalarConverter();
	if (ac < 2)
		std::cout << "Please write an argument!\n";
	else if (ac > 2)
		std::cout << "Too many arguments!\n";
	else if (strlen(av[1]) == 0)
		std::cout << "choose between (c | i | f | d)!\n";
	else if (av[1][0] == 'c' || av[1][0] == 'i' || av[1][0] == 'd' || av[1][0] == 'f')
	{
		switch (av[1][0]){
		case 'c':
			ScalarConverter::convert("'0'");
			ScalarConverter::convert("'\n'");
			ScalarConverter::convert("c");
			ScalarConverter::convert("}");
			ScalarConverter::convert("127");
			break;
		case 'i':
			ScalarConverter::convert("0");
			ScalarConverter::convert("2147483647");
			ScalarConverter::convert("+2147483647");
			ScalarConverter::convert("2147483648");
			ScalarConverter::convert("-2147483648");
			ScalarConverter::convert("-2147483649");
			break;
		case 'f':
			ScalarConverter::convert("0.0f");
			ScalarConverter::convert("2147483647.4f");
			ScalarConverter::convert("2147483647.0f");
			ScalarConverter::convert("+2147483647.0f");
			ScalarConverter::convert("999997483647.0f");
			ScalarConverter::convert("-inff");
			ScalarConverter::convert("+inff");
			break;
		default:
			break;
		}
	}
	else
		ScalarConverter::convert(av[1]);
}