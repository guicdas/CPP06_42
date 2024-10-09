#pragma once

#include <iostream>

typedef struct Data{
	int		memberInt1;
	int		memberInt2;
} Data;

class Serializer{
	private:
		Serializer( void );
		Serializer( const Serializer &S );
		Serializer& operator=( const Serializer &S );
		~Serializer( void );

	public:
		static uintptr_t serialize(Data* ptr);
 		static Data* deserialize(uintptr_t raw);
};