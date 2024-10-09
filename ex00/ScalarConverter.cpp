#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter( void ){
	std::cout << "ScalarConverter created by default!\n";
}

ScalarConverter::ScalarConverter( const ScalarConverter &s ){
	std::cout << "ScalarConverter Copy created!\n";
	*this = s;
}

ScalarConverter& ScalarConverter::operator=( const ScalarConverter &s ){
	std::cout << "ScalarConverter Copy created!\n";
	(void) s;
	return (*this);
}

ScalarConverter::~ScalarConverter( void ){
	std::cout << "ScalarConverter destroyed!\n";
}

void ScalarConverter::convert(const std::string &s){
	std::cout << "/////////////////////\n";
	std::cout << "string:\t" << s << "\t";
	switch(whichType(s))
	{
		case 1:	std::cout << "exception found\n" << std::endl \
		<< "char:\timpossible\nint:\timpossible\n" \
		<< "float:\tnanf\ndouble:\tnan" << std::endl;
			break;
		case 2:	std::cout << "char found\n" << std::endl;
			convertCharacter(s);
			break;
		case 3: std::cout << "int found\n" << std::endl;
			convertInt(s);
			break;
		case 4:	std::cout << "float found\n" << std::endl;
			convertFloat(s);
			break;
		case 5:	std::cout << "double found\n" << std::endl;
			convertDouble(s);
			break;
		default:	std::cout << "Input is not -> int / char / double / float <-\n" << std::endl;
			break;
	}
}