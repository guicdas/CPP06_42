#pragma once

#include <iostream>
#include <stdint.h>

typedef struct Data{
	int		memberInt1;
	int		memberInt2;
} Data;

class Serializer{
	private:
		Serializer( void );
		Serializer( Serializer const & );
		Serializer& operator=( Serializer const & );
		~Serializer( void );

	public:
		static uintptr_t serialize( Data * );
 		static Data* deserialize( uintptr_t );
};