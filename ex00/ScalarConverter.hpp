#pragma once

#include <iostream>
#include <string>
#include <limits>		//MAX-MIN
#include <stdlib.h>		//atof
#include <cmath>		//remainder
#include <cstdlib>		//strtof
#include <iomanip>		//fixed, precision
#include <cstring>		//cstring

class ScalarConverter{
	private:
		ScalarConverter( void );		//class must not be instanciable
		ScalarConverter( const ScalarConverter &S );
		ScalarConverter& operator=( const ScalarConverter &S );
		~ScalarConverter( void );

	public:
		static void convert(const std::string &string);
};

void	convertCharacter(const std::string &string);
void	convertInt(const std::string &string);
void	convertFloat(const std::string &string);
void	convertDouble(const std::string &string);
int		whichType(const std::string& str);