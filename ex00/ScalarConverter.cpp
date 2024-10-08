#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter( void ){
	std::cout << "ScalarConverter created by default!\n";
}

ScalarConverter::ScalarConverter( const ScalarConverter &S ){
	std::cout << "ScalarConverter Copy created!\n";
	*this = S;
}

ScalarConverter& ScalarConverter::operator=( const ScalarConverter &S ){
	std::cout << "ScalarConverter Copy created!\n";
	(void) &S;
		
	return (*this);
}

ScalarConverter::~ScalarConverter( void ){
	std::cout << "ScalarConverter destroyed!\n";
}

void ScalarConverter::convert(const std::string &string){
	std::cout << "string:\t" << string << std::endl;
	std::cout << "char:\t";
	convertToCharacter(string);
	std::cout << "\nint:\t";
	convertToInt(string);
	std::cout << "\nfloat:\t";
	convertToFloat(string);
	std::cout << "\ndouble:\t";
	convertToDouble(string);
}