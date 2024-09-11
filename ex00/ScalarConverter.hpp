#pragma once

#include <iostream>
#include <string>

class ScalarConverter{
	private:
		ScalarConverter( void );		//class must not be instanciable
		ScalarConverter( const ScalarConverter &S );
		ScalarConverter& operator=( const ScalarConverter &S );
		~ScalarConverter( void );

	public:
		static void convert(const std::string &string);
};

void	convertToCharacter(const std::string &string);
void	convertToInt(const std::string &string);
void	convertToFloat(const std::string &string);
void	convertToDouble(const std::string &string);

int  whichType(const std::string& str, size_t& len);