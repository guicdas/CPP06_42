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
		ScalarConverter( void );
		ScalarConverter( const ScalarConverter & );
		ScalarConverter& operator=( const ScalarConverter & );
		~ScalarConverter( void );

	public:
		static void convert(const std::string &);
};

void	convertCharacter( const std::string & );
void	convertInt( const std::string & );
void	convertFloat( const std::string & );
void	convertDouble( const std::string & );
int		whichType( const std::string & );