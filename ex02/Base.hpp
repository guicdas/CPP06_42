#pragma once

#include <iostream>
#include <stdlib.h>
#include <ctime>

class Base{
	public:
		virtual ~Base( void );
};

Base	*generate( void );
void	identify( Base * );
void	identify( Base & );